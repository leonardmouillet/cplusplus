#include<iostream>
#include "test.h"

int main (int argn, char* argv []){
    if (argn > 1){ // n'importe quel caractère passé en argument permet de tester la fonction print
        std::cout<<"test de la fonction print"<<std::endl;
        test_print();
    }
    else{ // en l'absence d'argument, on teste toutes les autres fonctions
        std::cout<<"test du constructeur"<<std::endl;
        test_list_constructor();
        std::cout<<"test de la fonction add_front"<<std::endl;
        test_add_front();
        std::cout<<"test de la fonction add_back"<<std::endl;
        test_add_back();
        std::cout<<"test de la fonction is_empty"<<std::endl;
        test_is_empty();
        std::cout<<"test de la fonction search"<<std::endl;
        test_search();
        std::cout<<"test de la fonction remove_front"<<std::endl;
        test_remove_front();
        std::cout<<"test de la fonction remove_back"<<std::endl;
        test_remove_back();
        std::cout<<"test de la fonction remove"<<std::endl;
        test_remove();
    }
    return 0;
}
