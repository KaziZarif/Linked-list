#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int list_length(Node *head);
void add_node_at_end(Node **head, int value);
void print_list(Node *head);
void delete_list(Node **head);
void reverse_list(Node **head);
Node *get_node(Node *head, int index);
void insert_node(Node **head, int index, int value);
void delete_node(Node **head, int index);
void update_node(Node **head, int index, int value);


int list_length(Node *head) {
    int length = 0;

    Node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void add_node_at_end(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node *current = *head;

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
    printf("\n");
}

void delete_list(Node **head) {
    Node *current = *head;
    Node *next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void reverse_list(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

Node *get_node(Node *head, int index) {
    Node *current = head;
    int i = 0;

    while(current != NULL) {
        if (i == index) {
            return current;
        }
        current = current->next;
        i++;
    }

    return NULL;
}

void insert_node(Node **head, int index, int value) {
    if(index < 0 || list_length(*head) < index) {
        printf("Index out of range\n");
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current != NULL) {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_node(Node **head, int index) {
    if (*head == NULL) {
        return;
    }

    if (index < 0 || list_length(*head) <= index) {
        printf("Index out of range\n");
        return;
    }

    Node *current = *head;

    if (index == 0) {
        *head = current->next;
        free(current);
    }

    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current != NULL && current->next != NULL) {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}


void update_node(Node **head, int index, int value) {
    if (index < 0 || list_length(*head) <= index) {
        printf("Index out of range\n");
        return;
    }

    if (index == 0) {
        (*head)->data = value;
        return;
    }

    Node *current = *head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current != NULL) {
        current->data = value;
    }
}

