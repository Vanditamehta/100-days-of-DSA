#include <stdlib.h>

/* Node structure */
struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;   // dummy head
    int size;
} MyLinkedList;


/* ===== Function Prototypes ===== */
MyLinkedList* myLinkedListCreate();
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);


/* ===== Implementation ===== */

/* Create linked list */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    
    obj->head = (struct Node*)malloc(sizeof(struct Node)); // dummy node
    obj->head->next = NULL;
    obj->size = 0;

    return obj;
}


/* Get value at index */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    struct Node* curr = obj->head->next;
    for(int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}


/* Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}


/* Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}


/* Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)
        return;

    struct Node* prev = obj->head;

    for(int i = 0; i < index; i++)
        prev = prev->next;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = prev->next;

    prev->next = newNode;
    obj->size++;
}


/* Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return;

    struct Node* prev = obj->head;

    for(int i = 0; i < index; i++)
        prev = prev->next;

    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);

    obj->size--;
}


/* Free entire list */
void myLinkedListFree(MyLinkedList* obj) {
    struct Node* curr = obj->head;

    while(curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(obj);
}