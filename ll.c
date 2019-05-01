#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int value;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *create_list(void)
{
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    return ll;
}

void free_list(LinkedList *ll)
{
    if (ll) {
        free(ll);
    }
}

Node *create_node(int value, Node *next)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = next;

    return node;
}

void free_node(Node *node)
{
    if (node) {
        free(node);
    }
}

void list_insert(LinkedList *ll, int value)
{
    Node *new_node = create_node(value, NULL);
    ll->tail->next = new_node;
    ll->tail = new_node;
    ll->size++;
}

int list_search(LinkedList *ll, int target)
{
    Node *current = ll->head;
    while (current) {
        if (current->value == target) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

int list_delete(LinkedList *ll, int target)
{
    int found = 0;
    Node *previous = NULL;
    Node *current = ll->head;

    while (current && !found) {
        if (current->value == target) {
            found = 1;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (current == NULL) {
        return -1;
    }

    if (previous == NULL) {
        Node *node_to_delete = ll->head;
        ll->head = current->next;
        free_node(node_to_delete);
    } else {
        Node *node_to_delete = current;
        previous->next = current->next;
        free_node(node_to_delete);
    }

    ll->size--;
}