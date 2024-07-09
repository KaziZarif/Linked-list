#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;


int list_length(Node *head);
void add_node_at_end(Node **head, int data);
void print_list(Node *head);
void delete_list(Node **head);
void reverse_list(Node **head);
Node *get_node(Node *head, int index);
void insert_node(Node **head, int index, int data);
void delete_node(Node **head, int index);


int list_length(Node *head) {
    int length = 0;

    Node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void add_node_at_end(Node **head, int data) {
    Node *current = *head;

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(Node *head) {

    Node *current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void delete_list(Node **head) {
    Node *current = *head;
    Node *next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(next);
    *head = NULL;
}

// void reverse_list(Node **head) {
//     Node *prev = NULL;
//     Node *current = *head;
//     Node *next = NULL;

//     while(current != NULL) {

//     }
// }