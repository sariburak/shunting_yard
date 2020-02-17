#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "structs.h"


#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3
#define MOD 4
#define RIGHT 5
#define LEFT 6
#define NUM 7



int is_operator(data_type* curr){
    if(curr->type != NUM && curr->type != RIGHT && curr->type != LEFT)
    {
        return 1;
    }
    return 0;
}

int precedence(data_type* curr){
    switch (curr->type)
    {
    case PLUS:
    case MINUS:
        return 1;
    default:
        return 2;
    }
}

struct Queue *to_postfix(data_type **my_list){
    struct Stack *head = NULL;
    data_type *curr;
    struct Queue *Qout;
    int i = 0;
    Qout = createQueue();
    while(curr = my_list[i++]){
        if(curr -> type == NUM){
            enQueue(Qout, curr);
        }
        if(is_operator(curr)){
            if(head == NULL){
                push(&head, curr);
            }else{
                while(head != NULL && precedence(head -> item) >= precedence(curr) && head -> item -> type != LEFT){
                    enQueue(Qout, pop(&head) -> item);
                }
                push(&head, curr);
            }
        }
        if(curr -> type == LEFT){
            push(&head, curr);
        }
        if(curr -> type == RIGHT){
            while(head -> item -> type != LEFT){
                enQueue(Qout, pop(&head) -> item);
            }
            pop(&head);
        }
    }
    while(!is_stack_empty(head)){
        enQueue(Qout, pop(&head) -> item);
    }
    free(head);
    return Qout;
}

void print_parsed_inputs(data_type **list){
    data_type *curr = *list;
    while(curr != NULL){
        if(curr->type == PLUS){
            printf("+");
        }else if(curr->type == NUM){
            printf("%d", curr->value);
        }else if(curr->type == MINUS){
            printf("-");
        }else if(curr->type == MULTIPLY){
            printf("*");
        }else if(curr->type == DIVIDE){
            printf("/");
        }else if(curr->type == MOD){
            printf("mod");
        }else if(curr->type == LEFT){
            printf("(");
        }else if(curr->type == RIGHT){
            printf(")");
        }else{
            printf("Not valid value in data_list!");
            exit(1);
        }
        curr++;
    }
}

int main(){
    data_type **input, **tmp;
    int input_count = 0, capacity = 500, c;
    struct Queue output;
    input = malloc(capacity * sizeof(data_type*));
    while((c = getchar()) != EOF){
        if(c == '\n'){
            continue;
        }
        if(input_count >= capacity){
            capacity *= 2;
            tmp = realloc(input, capacity * sizeof(data_type*));
            if(tmp == NULL){
                printf("Realloc Failed!");
                exit(1);
            }
            input = tmp;
        }
        if(c >= '0' && c <= '9'){
            ungetc(c, stdin);
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = NUM;
            scanf("%d", &(input[input_count]->value));
        }else if(c == '+'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = PLUS;
        }else if(c == '-'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = MINUS;
        }else if(c == '*'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = MULTIPLY;
        }else if(c == '/'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = DIVIDE;
        }else if(c == '%'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = MOD;
        }
        else if(c == '('){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = LEFT;
        }
        else if(c == ')'){
            input[input_count] = malloc(sizeof(data_type));
            input[input_count]->type = RIGHT;
        }
        else{
            printf("Input type or format not allowed!");
        }
        input_count++;
    } 
    if(input_count > 0){
        tmp = realloc(input, (input_count+1) * sizeof(data_type*));
        if(tmp == NULL){
            printf("Realloc Failed!");
            exit(1);
        }
        tmp[input_count] = NULL;
        input = tmp;
        print_queue(to_postfix(input));
    }
    return 0;
}