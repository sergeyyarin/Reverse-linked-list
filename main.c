#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node * next;
} node_t;

void print_node(const node_t * node)
{
    printf("%d", node->data);
}

void print_list(const node_t * node)
{
    while (node)
    {
        print_node(node);
        node = node->next;
    }
    printf("\n");
}

void add_node(node_t * head, int data)
{
    node_t * new = (node_t *)malloc(sizeof(node_t));
    assert(new != NULL);

    new->next = NULL;
    new->data = data;

    node_t * node = head;
    while (node->next)
    {
        node = node->next;
    }
    node->next = new;
}

node_t * reverse_list(node_t ** head)
{
    node_t * prev = NULL;
    node_t * curr = *head;
    node_t * next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;

    return *head;
}

int main()
{
    node_t * head = (node_t *)malloc(sizeof(node_t));

    assert(head != NULL);

    head->next = NULL;
    head->data = 0;

    for (int i = 1; i <= 9; ++i)
    {
        add_node(head, i);
    }

    print_list(head);

    node_t * r_head = reverse_list(&head);

    print_list(r_head);

    node_t * node = r_head->next;
    while(node)
    {
        node_t * waste = node;
        node = node->next;
        free(waste);
    }
    free(r_head);

    return 0;
}
