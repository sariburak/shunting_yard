#include <stdlib.h> 
#include <stdio.h> 
#include "structs.h"
  
struct QNode 
{ 
    data_type* item; 
    struct QNode *next; 
}; 
  
struct Queue 
{ 
    struct QNode *front, *rear; 
}; 
  
struct QNode* newNode(data_type* item) 
{ 
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->item = item; 
    temp->next = NULL; 
    return temp;  
} 
   
struct Queue *createQueue() 
{ 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
void enQueue(struct Queue *q, data_type* item) 
{ 
    struct QNode *temp = newNode(item); 
  
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 
  
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
struct QNode *deQueue(struct Queue *q) 
{ 
    if (q->front == NULL) 
       return NULL; 
  
    struct QNode *temp = q->front; 
    q->front = q->front->next; 
   
    if (q->front == NULL) 
       q->rear = NULL; 
    return temp; 
} 

void print_queue(struct Queue *q){
    struct QNode *curr;
    curr = q -> front;
    while(curr != q -> rear){
        print_data_type(curr -> item);
        curr = curr -> next;
    }
    print_data_type(curr -> item);
}