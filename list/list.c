#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//---------------------------------------------------------------------------------------------
//--------------------------------  UTILS FUNCTIONS  ------------------------------------------
//---------------------------------------------------------------------------------------------

// Allocs new node, return "NULL" if not possible
struct node *alloc_new_node(){
    
    struct node *newNode = malloc(sizeof(struct node));

    if(newNode)
        return newNode;

    return NULL;
}

// Set an node with its variables
void set_node(struct node *node, void *element, struct node *previous, struct node *next){
    node->element = element;
    node->next = next;
    node->previous = previous;
}

//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
//------------------------------  DATA STRUCTURE FUNCTIONS  -----------------------------------
//---------------------------------------------------------------------------------------------

//Initialize an new list
struct list *init_list(){

    struct list *newList = malloc(sizeof(struct list));
    if(!newList) {return NULL;}
    
    newList->head = NULL;
    newList->last = NULL;
    newList->lenght = 0;
    
    return newList;
}

//Return true if empty list, else returns false
int is_empty(struct list *list){
    
    if (list->head == NULL)
        return 1;
    
    return 0;
}


// Put an element at beginning of the list, return 1 if successful else return 0
int push_left(struct list *list, void *element){
    
    struct node *newNode = alloc_new_node();
    if(!newNode) {return 0;}
    
    if(is_empty(list))
    {
        set_node(newNode, element, NULL, NULL);
        list->head = newNode;
        list->last = newNode;
        list->lenght++;
        return 1;
    }

    struct node *i = list->head;
    
    i->previous = newNode;
    set_node(newNode, element, NULL, i);
    list->head = newNode;
    list->lenght++;
   
    return 1;
}

// Put an element at end of the list, return 1 if successful else return 0
int push_right(struct list *list, void *element){
    
    struct node *newNode = alloc_new_node();
    if(!newNode) {return 0;}
    
    if(is_empty(list))
    {
        set_node(newNode, element, NULL, NULL);
        list->head = newNode;
        list->last = newNode;
        list->lenght++;
        return 1;
    }

    struct node *i = list->head;

    while(i->next) {i = i->next;}

    set_node(newNode, element, i, NULL);
    i->next = newNode;
    list->last = newNode;
    list->lenght++;
   
    return 1;
}

// Push element at given index
int list_add(struct list *list, unsigned int index, void *element){
    
    if(index > list->lenght-1) {return 0;}

    if(index == 0) {return push_left(list, element);}
     
    struct node *newNode = alloc_new_node();
    if(!newNode) {return 0;}
    
    unsigned int i = 0;
    struct node *node = list->head;
    
    while(i != index)
    {
        node = node->next;
        i++;
    }
    
    set_node(newNode, element, node->previous, node);
    node->previous->next = newNode;
    node->previous = newNode;
    list->lenght++;
    return 1;
}

// Remove and returns an element from the beginning of the list
struct node *pop_left(struct list *list){
    
    if(is_empty(list)) {return NULL;}

    struct node *i = list->head;
   
    list->head = list->head->next;
    
    if(list->head) 
        list->head->previous = NULL;
    else 
        list->last = NULL;

    list->lenght--;
    return i;
}

// Remove and returns an element from the end of list
struct node *pop_right(struct list *list){
    
    if(is_empty(list)) {return NULL;}

    struct node *i = list->head;
    
    while(i->next) {i = i->next;}
    
    if(i == list->head) 
    {
        list->head = NULL;
        list->last = NULL;
        list->lenght--;
        return i;
    }

    i->previous->next = NULL;
    list->last = i->previous;
    list->lenght--;
    return i;
}

// Remove and return element from the list in given index
struct node *list_remove(struct list *list, unsigned int index){
    
    if(index > list->lenght-1) {return NULL;}

    if(is_empty(list)) {return NULL;}

    if(index == 0) {return pop_left(list);}
    
    if(index == list->lenght-1) {return pop_right(list);}

    unsigned int i = 0;
    struct node *node = list->head;
    
    while (i !=  index)
    {
        node = node->next;
        i++;
    }
    
    node->previous->next = node->next;
    node->next->previous = node->previous;
    list->lenght--;

    return node;
}

// Returns element pointer at given index
void *list_get_elt(struct list *list, unsigned int index){
    
    if(index > list->lenght-1) {return NULL;}   
    
    if (is_empty(list)) {return NULL;}

    if(index == 0) {return list->head->element;}
    
    if(index == list->lenght-1) {return list->last->element;}

    unsigned int i;
    struct node *node = list->head;
    
    if (index > (list->lenght / 2))
    {
        i = list->lenght-1;
        
        while (i != index)
        {
            node =  node->previous;
            i--;
        }

        return node->element;
    }
    
    i=0;
    
    while (i != index)
    {
        node =  node->next;
        i++;
    }
    
    return node->element;
}

// Returns node pointer at given index
struct node *list_get_node(struct list *list, unsigned int index){
    
    if(index > list->lenght-1) {return NULL;}   
    
    if (is_empty(list)) {return NULL;}

    if(index == 0) {return list->head->element;}
    
    if(index == list->lenght-1) {return list->last->element;}

    unsigned int i;
    struct node *node = list->head;
    
    if (index > (list->lenght / 2))
    {
        i = list->lenght-1;
        
        while (i != index)
        {
            node =  node->previous;
            i--;
        }

        return node->element;
    }
    
    i=0;
    
    while (i != index)
    {
        node =  node->next;
        i++;
    }
    
    return node;
}

// Destroy the list without freeing elements inside nodes
void destroy_list(struct list **list){
    
    struct node *i = (*list)->head;
    struct node *j;
    
    while(i)
    {   
        free(i->element);
        j = i->next;
        free(i);
        i = j;
    }
    
    free(*list);
    *list = NULL;  
};

// Destroy the list freeing elements inside nodes
void destroy_list_free(struct list **list){
    
    struct node *i = (*list)->head;
    struct node *j;
    
    while(i)
    {   
        free(i->element);
        j = i->next;
        free(i);
        i = j;
    }
    
    free(*list);
    *list = NULL;  
};

// Clear the list whitout freeing the elements inside nodes
void clear_list(struct list *list){
    if(is_empty(list)) {return;}
    struct node *i = list->head;
    while (i->next)
    {
        i->element = NULL;
        i = i->next;
    }
}

// Clear the list freeing the elements inside nodes
void clear_list_free(struct list *list){
    if(is_empty(list)) {return;}
    struct node *i = list->head;
    while (i->next)
    {
        free(i->element);
        i->element = NULL;
        i = i->next;
    }
}

//Reset the list whitout freeing elements inside nodes
void reset(struct list **list){
    
    destroy_list(list);
    *list = init_list();
}

//Reset the list freeing elements inside nodes
void reset_free(struct list **list){
    
    destroy_list_free(list);
    *list = init_list();
}

// Return and remove an sublist in the range given
struct list *slice(struct list *list, unsigned int index_begin, unsigned int index_end){
    
    if(is_empty(list)) {return NULL;}
    if((index_begin > list->lenght-1) | (index_end > list->lenght-1)) {return NULL;}
    if(index_begin > index_end) {return NULL;}

    unsigned int i = 0;
    unsigned int j = list->lenght-1;
    struct node *node_b = list->head;
    struct node *node_e = list->last;
    
    //find the nodes
    while ((i != index_begin) | (j != index_end))
    {
        if(i != index_begin)
        {
            node_b = node_b->next;
            i++;
        }

        if(j != index_end)
        {
            node_e = node_e->previous;
            j--;
        }
    }
    // Set new nodes pointers also the head and last if needed
    if(node_b->previous)
        node_b->previous->next = node_e->next;
    else
    {
        list->head = node_e->next;
        if(node_e->next) {node_e->next->previous = NULL;}
    }

    if(node_e->next)
        node_e->next->previous = node_b->previous;
    else
    {
        list->last = node_b->previous;
        if(node_b->previous) {node_b->previous->next = NULL;}
    }

    node_b->previous = NULL;
    node_e->next = NULL;

    // Allocs new list and returns it
    struct list *newList = init_list();
    if(!newList) {return NULL;}
    newList->head = node_b;
    newList->last = node_e;
    newList->lenght = index_end - index_begin + 1;
    return newList;
}

// Copy list in given range, with the same pointers to elements
struct list *copy_p_list(struct list *list)
{
    struct list *newList = init_list();
    if (!newList) {return NULL;}
    if (is_empty(list)) {return NULL;}

    struct node *node = list->head;
    void *elt;
    while (node)
    {
        elt = node->element;
        if(!push_right(newList, elt)){return NULL;}
        node = node->next;
    }

    return newList;
}

//---------------------------------------------------------------------------------------------