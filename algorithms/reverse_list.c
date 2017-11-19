// reverse a linked list
// in http://www.sunlands.com/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* list)
{
    Node* p = list;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// sort the list
void reverse_list(Node** head)
{
    // Node* cur  = *head;
    // Node* prev = NULL;
    // Node* next = NULL;
    // while(cur != NULL)
    // {
    //     next = cur->next;
    //     cur->next = prev;
    //     prev = cur;
    //     cur = next;
    // }
    // *head = prev;

    Node* p = (*head)->next;
    (*head)->next = NULL;
    while (p) {
        Node* tmp = p->next;
        p->next = *head;
        *head = p;
        p = tmp;
    }
}

// sort list, return the head
Node* reverse(Node* head)
{
    if (head == NULL)
        return head; 
    Node* p = head->next;
    head->next = NULL;
    while(p) {
        Node* tmp = p->next;
        p->next = head;
        head = p;
        p = tmp;
    }
    return head;
}

int main()
{
    int list_data[] = {1, 3, 5, 7, 9};
    Node* head;
    Node* p;
    for (int i = 0; i < 5; ++i)
    {
        if (i == 0)
        {
            head = (Node*)malloc(sizeof(Node));
            head->data = list_data[i];
            head->next = NULL;
            p = head;
        }
        else
        {
            Node* temp = (Node*)malloc(sizeof(Node));
            temp->data = list_data[i];
            temp->next = NULL;
            p->next = temp;
            p = temp;
        }
    }

    print_list(head);
    reverse_list(&head);
    print_list(head);
    head = reverse(head);
    print_list(head);

    // TODO: release the malloc memory

    return 0;
}