#include<iostream>
#include<cstdlib>
#include"stack.h"

bool is_operand (char* token) {
    return ((token[0] >= '0') and (token[0] <= '9'));
}

int rpn_calc (int n, char* tab []) {
    int* stack = init_stack(n) ;
    int k = 0 ;
    int* top = &k ;
    int i = 0 ;
    for (int i; i < n; i++) {
        char* token = tab[i];
        if (is_operand(token)){
            push(stack, top, atoi(token));
        } 
        else {
            if (token[0] == '!') {
                int a = pop(stack, top);
                push(stack, top, -a);
            } 
            else if (token[0] == '+') {
                int b = pop(stack, top);
                int a = pop(stack, top);
                push(stack, top, a+b);
            }
            else if (token[0] == '-') {
                int b = pop(stack, top);
                int a = pop(stack, top);
                push(stack, top, a-b);
            }
            else if (token[0] == 'x') {
                int b = pop(stack, top);
                int a = pop(stack, top);
                push(stack, top, a*b);
            }
            else if (token[0] == '/') {
                int b = pop(stack, top);
                int a = pop(stack, top);
                push(stack, top, a/b);
            }
        }
        print_stack(stack,top);
    }
    //int result = stack[0];
    //delete (stack);
    //return result;
    return stack[0];
}