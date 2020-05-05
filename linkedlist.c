#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char c;
    struct node *next;
}node_t; 


void printlist(node_t *head)
{
    node_t *temp = head;

    while(temp != NULL)
    {
        printf("%c - ", temp -> c);
        temp = temp -> next;
    }
}

node_t *create_new_node(char c)
{
    node_t *result;

    result = malloc(sizeof(node_t));
    result -> c = c;
    result -> next = NULL;

    return result;
}

void insert_after(node_t *prev, node_t *insert)
{
    insert->next = NULL;
    prev->next = insert;
}

int main()
{
    int i;
    node_t *temp;
    node_t *head;
    node_t *prev;

    char name[5] = "JOHN";
    i = 0;
    head = NULL;
    prev = head;
    while (name[i])
    {
        // temp = create_new_node(name[i]);
        // temp->next =head;
        // head = temp;
        // i++
        temp = create_new_node(name[i]);
        (head == NULL) ? head = temp : insert_after(prev, temp);
        prev = temp;
        i++;
    }
    printlist(head);
}