Multi purpose list - Can be used as stack, queue or linked list;

Operations/functions implemented:


//---------------------------------------------------------------------------------------------
//--------------------------------  UTILS FUNCTIONS  ------------------------------------------
//---------------------------------------------------------------------------------------------

// Allocs new node, return "NULL" if not possible
struct node *alloc_new_node();

// Set an node with its variables
void set_node(struct node *node, void *element, struct node *previous, struct node *next);

//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
//------------------------------  DATA STRUCTURE FUNCTIONS  -----------------------------------
//---------------------------------------------------------------------------------------------

//Initialize an new list
struct list *init_list();

//Return true if empty list, else reurns false
int is_empty(struct list *list);

// Put an element at beginning of the list, return 1 if successful else return 0
int push_left(struct list *list, void *element);

// Put an element at end of the list and return 1 if successful, else return 0
int push_right(struct list *list, void *element);

// Push element at given index
int list_add(struct list *list, unsigned int index, void *element);

// Remove and returns an element from the beginning of the list
struct node *pop_left(struct list *list);

// Remove and returns an element from ending of the list
struct node *pop_right(struct list *list);

// Remove and return element from the list in given index
struct node *list_remove(struct list *list, unsigned int index);

// Returns element pointer at given index
void *list_get_elt(struct list *list, unsigned int index);

// Returns node pointer at given index
struct node *list_get_node(struct list *list, unsigned int index);

// Destroy the list without freeing elements inside nodes
void destroy_list(struct list **list);

// Destroy the list freeing elements inside nodes
void destroy_list_free(struct list **list);

// Clear the list whitout freeing elements inside nodes
void clear_list(struct list *list);

// Clear the list freeing the elements inside nodes
void clear_list_free(struct list *list);

//Reset the list whitout freeing elements inside nodes
void reset(struct list **list);

//Reset the list freeing elements inside nodes
void reset_free(struct list **list);

// Return and remove an sublist in the range given
struct list *slice(struct list *list, unsigned int index_begin, unsigned int index_end);

// Copy list in given range, with the same pointers to elements
struct list *copy_p_list(struct list *list);

//---------------------------------------------------------------------------------------------
