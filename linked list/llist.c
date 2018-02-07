#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

node_type* new_node(int num) {
    node_type *current = malloc(sizeof *current);
    
    current->data = num;
    current->next = NULL;
    return current;
}

int get_data(node_type *np) {
    return np->data;
}

void set_data(node_type *np, int num) {
    np->data = num;
}

void insert_beg(node_type **startp, int num) {
    node_type *np = malloc(sizeof *np);
    
    np->data = num;
    np->next = NULL;
    
    np->next = *startp;
    *startp = np;
}

void insert_end(node_type **startp, int num) {
    node_type *current = *startp;
    node_type *prev = NULL;
    
    while (current != NULL) {
        prev = current;
        current = current->next;
    }
    
    current = malloc(sizeof *current);
    
    current->data = num;
    current->next = NULL;
    
    if (prev == NULL)
        *startp = current;
    else
        prev->next = current;
}

int delete(node_type **startp, int num) {
    node_type *current = *startp;
    node_type *prev = NULL;
    
    while ((current != NULL) && (current->data != num)) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
        return 0;
    else {
        if (prev == NULL)
            *startp = current->next;
        else
            prev->next = current->next;
        
        free(current);
        return 1;
    }
}

node_type* search(node_type *start, int num) {
    while ((start != NULL) && (start->data != num)) {
        start = start->next;
    }
    return start;
}

void display(node_type *start) {
    printf("Value Address\n");
    
    while (start != NULL) {
        printf("%5d %p\n", start->data, start);
        start = start->next;
    }
}

void display_reverse(node_type *start) {
    if (start == NULL) {
        return;
    }
    display_reverse(start->next);
    printf("%5d %p\n", start->data, start);
}

int length(node_type *start) {
    int len = 0;
    
    while (start != NULL) {
        len++;
        start = start->next;
    }
    return len;
}

void clean(node_type *start) {
    node_type* temp;
    
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
}
