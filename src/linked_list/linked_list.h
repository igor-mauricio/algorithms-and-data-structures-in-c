//
// Created by automaniac on 1/17/24.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_IN_C_LINKED_LIST_H
#define ALGORITHMS_AND_DATA_STRUCTURES_IN_C_LINKED_LIST_H

#endif //ALGORITHMS_AND_DATA_STRUCTURES_IN_C_LINKED_LIST_H

typedef struct Node{
    struct Node *next;
    void *value;
}Node;

Node *new_node(void *value);

typedef struct{
    Node *head;
    Node *tail;
    int size;
}LinkedList;

LinkedList *new_linked_list(void);

void prepend(LinkedList *self, void *value);
void append(LinkedList *self, void *value);
void *insert_into(LinkedList *self, void *value, int index);
void *get_head(LinkedList *self);
void *get_tail(LinkedList *self);
void *get(LinkedList *self, int index);
void *pop(LinkedList *self);
void *unshift(LinkedList *self);
void *remove_from(LinkedList *self, int index);

static Node *get_node_at(LinkedList *self, int index);



