#include<iostream>
#include<cstdlib>

// Implémentation d'une pile //

void push (int* stack, int* top, int token) {
    stack[*top] = token; 
    *top = *top + 1;
}

int pop (int* stack, int* top) {
    *top = *top - 1;
    return stack[*top];
}

int* init_stack (int n) {
    return new int[n];
}

void delete_stack (int* stack) {
    delete [] stack;
}

void print_stack (int* stack, int* top) {
    std::cout << "[ ";
    for (int i = 0; i < *top; i++) {
        std::cout<<stack[i]<<", ";
    }
    std::cout << "\n";
}

// Implémentation de la calculatrice //

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

// Test de la calculatrice //

int main (int argc, char* argv []) {
    std::cout << rpn_calc(argc-1, argv+1) << std::endl;
    return 0;
}