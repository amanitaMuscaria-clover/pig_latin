#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

Node *node_make(int value) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = n->prev = NULL;
    
    return n;
}

Node *list_insert(Node *prev_node, int value) {
   Node *newNode = node_make(value);
   newNode->next = prev_node->next;
   prev_node->next = newNode;
   return newNode;

}

void list_print(const Node *head) {
    int count = 0;
    Node *print_this = head;
    while(print_this->next != NULL) {
        printf("%d\n", print_this->value, "Index: %d\n", count);
        print_this = print_this->next;
        count ++;
    }
  
}

Node *list_find(Node *head, int value) {
    Node *check_this = calloc(1, sizeof(Node));
    check_this = head;
    while(check_this->next != NULL) {
        if(check_this->value == value){
            return check_this;
        }
        else {
            check_this = check_this->next;
        }
    }
    return NULL;
}

void list_remove(Node *n) {
    
    n->next->prev = n->prev;
    n->prev->next = n->next;

    free(n);
}

void list_free(Node *head) {
    Node *h = calloc(1, sizeof(Node));
    h = head;
    free(head);
    while(h->next!= NULL) {
        Node *g = calloc(1, sizeof(Node));
        g = h->next;
        h = g;
        free(g);
    }
}




