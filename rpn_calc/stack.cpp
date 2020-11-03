#include<iostream>

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