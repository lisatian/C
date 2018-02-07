#ifndef llist_h
#define llist_h

typedef struct node {
    int data;
    struct node *next;
} node_type;

node_type *new_node(int);
int get_data(node_type *);
void set_data(node_type *, int);
void insert_beg(node_type **, int);
void insert_end(node_type **, int);
node_type * search(node_type *, int);
int delete(node_type **, int);
void display(node_type *);
void display_reverse(node_type *);

void clean(node_type *);
int length(node_type *);

#endif /* llist_h */
