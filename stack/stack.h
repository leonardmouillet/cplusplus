#include<iostream>

class Stack {

    public:

        Stack (int n) : size(n), top(0) {
            if (n > 0){
                tab = new int [n];
            }
            else {
                std::cout<<"la taille de la pile doit être positive"<<std::endl;
                throw("la taille de la pile doit être positive");
            }
        }

        void push(int i){
	  if (top < size){ // vr: utilise is_full 
                tab[top] = i;
                top = top + 1;
            }
            else{
                std::cout<<"la pile est pleine"<<std::endl;
                throw("la pile est pleine");
            }
        }

        int pop(){
            if (top > 0){ // vr: utilise is_empty
                top = top - 1;
                return tab[top];
            }
            else {
                std::cout<<"la pule est vide"<<std::endl;
                throw("la pile est vide");
            }
        }

        void print(){
            std::cout<<"[ ";
            for (int i=0 ; i < top ; i++){
                std::cout << tab[i] << ", ";
            }
            std::cout << "]\n";
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
