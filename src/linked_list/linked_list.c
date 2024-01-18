//

#include <malloc.h>
#include "linked_list.h"

Node *new_node(void *value) {
    Node* self = (Node*)malloc(sizeof(Node));
    self->value = value;
    self->next = NULL;
    return self;
}

LinkedList *new_linked_list(void) {
    LinkedList *self = (LinkedList*)malloc(sizeof(LinkedList));
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
    return self;
}

void prepend(LinkedList *self, void *value) {
    Node *node = new_node(value);
    self->size++;

    if(self->head == NULL){
        self->head = node;
        self->tail = node;
        return;
    }

    node->next = self->head;
    self->head = node;
}

void append(LinkedList *self, void *value) {
    Node *node = new_node(value);
    self->size++;

    if(self->head == NULL){
        self->head = node;
        self->tail = node;
        return;
    }

    self->tail->next = node;
    self->tail = node;
}

void *insert_into(LinkedList *self, void *value, int index) {
    if(index<0 || index >= self->size)
        return NULL;

    if(index==0){
        prepend(self, value);
        return value;
    }

    self->size++;
    Node *node = new_node(value);
    Node *before = get_node_at(self, index-1);
    Node *current = before->next;

    before->next = node;
    node->next = current;
    return value;
}

void *get_head(LinkedList *self) {
    return self->head->value;
}

void *get_tail(LinkedList *self) {
    return self->tail->value;
}

void *get(LinkedList *self, int index) {
    Node *node = get_node_at(self, index);

    if(node == NULL)
        return NULL;

    return node->value;
}

void *pop(LinkedList *self) {
    if(self->head == NULL){
        return NULL;
    }

    Node *node = self->tail;
    void *value = node->value;
    self->size--;

    if(self->head == self->tail){
        self->head = NULL;
        self->tail = NULL;
        free(node);
        return value;
    }

    Node *before_last = get_node_at(self, self->size-1);

    self->tail = before_last;
    self->tail->next = NULL;

    free(node);
    return value;
}

void *unshift(LinkedList *self) {

    if(self->head == NULL){
        return NULL;
    }

    Node *node = self->head;
    void *value = node->value;
    self->size--;

    if(self->head == self->tail){
        self->head = NULL;
        self->tail = NULL;
        free(node);
        return value;
    }

    self->head = self->head->next;

    free(node);
    return value;
}

void *remove_from(LinkedList *self, int index) {
    if(index<0 || index >= self->size)
        return NULL;

    if(index==0)
        return unshift(self);

    if(index== self->size-1)
        return pop(self);

    Node *before_node = get_node_at(self, index - 1);
    Node *current_node = before_node->next;
    Node *next_node = current_node->next;

    before_node->next = next_node;
    void *value = current_node->value;

    self->size--;
    free(current_node);
    return value;
}


static Node *get_node_at(LinkedList *self, int index){
    if(index<0 || index >= self->size)
        return NULL;

    Node *node = self->head;

    for(int i=0; i<index; i++){
        node = node->next;
    }

    return node;
}
