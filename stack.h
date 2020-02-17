#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

struct Stack{
    data_type* item;
    struct Stack *next;
};

struct Stack *create_Snode(data_type* item){
    struct Stack *new = malloc(sizeof(struct Stack));
    new -> item = item; new -> next = NULL;
    return new;
}

void push(struct Stack **head_pointer, data_type* item){
    struct Stack *new = create_Snode(item);
    new -> next = *head_pointer;
    *head_pointer = new;
}

struct Stack *pop(struct Stack **head_pointer){
    struct Stack *to_pop = *head_pointer;
    *head_pointer = (*head_pointer) -> next;
    return to_pop;
}

int is_stack_empty(struct Stack *head){
     return head == NULL;
}

void print_stack(struct Stack *head){
    struct Stack *curr = head;
    if(is_stack_empty(head)){
        printf("Stack is empty!\n");
        return;
    }
    while(curr != NULL){
        print_data_type(curr -> item);
        curr = curr -> next;
    }
}