#ifndef STRUCTS_H_
#define STRUCTS_H_

struct data_type{
    int type; 
    int value;
};

typedef struct data_type data_type;

void print_data_type(data_type *data){
    if(data->type == 0){
            printf("+");
        }else if(data->type == 7){
            printf("%d", data->value);
        }else if(data->type == 1){
            printf("-");
        }else if(data->type == 2){
            printf("*");
        }else if(data->type == 3){
            printf("/");
        }else if(data->type == 4){
            printf("mod");
        }else if(data->type == 5){
            printf(")");
        }else if(data->type == 6){
            printf("(");
        }else{
            printf("Not valid value in data_list!");
            exit(1);
        }
}

#endif