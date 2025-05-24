#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertAtHead(Node *head, int value)
{
    Node *tempNode = malloc(sizeof(Node));
    if (tempNode == NULL)
    {
        fprintf(stderr, "memory allocation failed!\n");
        return NULL;
    }
    tempNode->data = value;
    tempNode->next = head;
    return tempNode;
}

Node *insertAtTail(Node *head, int value)
{
    if (head == NULL)
    {
        Node *tempNode = malloc(sizeof(Node));
        if (tempNode == NULL)
        {
            fprintf(stderr, "memory allocation failed!\n");
            return NULL;
        }
        tempNode->data = value;
        tempNode->next = NULL;
        return tempNode;
    }
    head->next = insertAtTail(head->next, value);
    return head;
}

Node *deleteNode(Node *head, int value)
{
    if (head == NULL)
        return NULL;

    if (head->data == value)
    {
        Node *temp = head->next;
        free(head);
        return temp;
    }
    head->next = deleteNode(head->next, value);
    return head;
}

void traverseList(Node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    traverseList(head->next);
}

void freeList(Node *head)
{
    if (head == NULL)
        return;
    freeList(head->next);
    free(head);
}
Node *insertAfterNode(Node *head, int value, int newVal)
{
    if (head == NULL)
        return head;
    if (head->data == value)
    {
        Node *temp = malloc(sizeof(Node));
        if (temp == NULL)
        {
            fprintf(stderr, "Memory allocation failed!\n");
            return head; // Return the unchanged list
        }
        temp->data = newVal;
        temp->next = head->next;
        head->next = temp;
        return head;
    }

    head->next = insertAfterNode(head->next, value, newVal);
    return head;
}

int main()
{
    Node *list = NULL;

    // Insert at head
    list = insertAtHead(list, 10);
    list = insertAtHead(list, 20);
    list = insertAtHead(list, 30);
    printf("After inserting 30, 20, 10 at head:\n");
    traverseList(list);
    printf("\n");

    // Insert at tail
    list = insertAtTail(list, 40);
    list = insertAtTail(list, 50);
    printf("After inserting 40, 50 at tail:\n");
    traverseList(list);
    printf("\n");

    // Insert after node with value 10
    list = insertAfterNode(list, 10, 25);
    printf("After inserting 25 after 10:\n");
    traverseList(list);
    printf("\n");

    // Delete a node
    list = deleteNode(list, 20);
    printf("After deleting node with value 20:\n");
    traverseList(list);
    printf("\n");

    // Clean up
    freeList(list);

    return 0;
}
