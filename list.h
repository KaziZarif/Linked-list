#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

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
void update_node(Node **head, int index, int value);

#endif // LIST_H