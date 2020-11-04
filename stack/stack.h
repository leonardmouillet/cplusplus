#include<iostream>

class Stack {

    public:

        Stack (int n) : size(n), top(0) {
            if (n > 0){
                tab = new int [n];
            }
            else {
                tab = new int [1]; // choix arbitraire
            }
        }

        void push(int i){
            if (top < size){
                tab[top] = i;
                top = top + 1;
            }
            // sinon, on ne fait rien
        }

        int pop(){
            if (top > 0){
                top = top - 1;
                return tab[top];
            }
            else {
                return 0; // choix arbitraire
            }
        }

        void print(){
            std::cout<<"[ ";
            for (int i=0 ; i < top ; i++){
                std::cout << tab[i] << ", ";
            }
            std::cout << "\n";
        }

        void delete_stack () {
            delete [] tab ;
        }

        bool is_empty () {
            return (top == 0);
        }

        bool is_full () {
            return (top == size);
        }


    private:
        int size ;
        int top ;
        int* tab ;
    };