#include<iostream>

class Stack {

    public:

        Stack (int n) : size(n), top(0) {
            if (n > 0){
                tab = new int [n];
            }
            else {
                throw("la taille de la pile doit être positive");
            }
        }

        Stack (const Stack& ref) : size(ref.size), top(ref.top), tab(new int [size]){
            for (int i = 0 ; i < top; ++i) {
                tab[i] = ref.tab[i];
            }
        }

        void push(int i){
            if (top < size){
                tab[top] = i;
                top = top + 1;
            }
            else{
                throw("la pile est pleine");
            }
        }

        int pop(){
            if (top > 0){
                top = top - 1;
                return tab[top];
            }
            else {
                throw("la pile est vide");
            }
        }

        void print(){
            std::cout<<"[ ";
            for (int i=0 ; i < top ; i++){
                std::cout << tab[i] << ", ";
            }
            std::cout << "\n";
        }

        bool is_empty () {
            return (top == 0);
        }

        bool is_full () {
            return (top == size);
        }

        ~Stack() {
            delete [] tab;
        }

    private:
        int size ;
        int top ;
        int* tab ;
    };