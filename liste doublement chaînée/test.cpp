#include "intlist.h"

void test_list_constructor(){
    IntList l ;
    std::cout << l.is_empty() << std::endl;
}

void test_add_front(){
    IntList l;
    l.add_front (10);
    std::cout << l.search(10);
    l.add_front (20);
    std::cout << l.search(10);
    std::cout << l.search(20) << std::endl;
}

void test_add_back(){
    IntList l;
    l.add_back (10);
    std::cout << l.search(10);
    l.add_back (20);
    std::cout << l.search(10);
    std::cout << l.search(20) << std::endl;
}

void test_is_empty(){
    IntList l ;
    std::cout << l.is_empty();
    l.add_back(20);
    std::cout << !(l.is_empty()) << std::endl;
}



void test_remove_front(){
    IntList l;
    l.add_back(10);
    l.add_back(20);
    l.remove_front();
    std::cout << !(l.search(10));
    std::cout << l.search(20);
    l.remove_front();
    std::cout << !(l.search(20));
    std::cout << l.is_empty();
    try {
        l.remove_front();
    }
    catch (const char* e) {
            std::cout << true << std::endl;
    }
}

void test_remove_back(){
    IntList l;
    l.add_back(10);
    l.add_back(20);
    l.remove_back();
    std::cout << !(l.search(20));
    std::cout << l.search(10);
    l.remove_back();
    std::cout << !(l.search(10));
    std::cout << l.is_empty();
    try {
        l.remove_back();
    }
    catch (const char* e) {
        std::cout << true << std::endl;
    }
}

void test_search(){
    IntList l;
    l.add_front(10);
    l.add_front(20);
    std::cout<<l.search(10);
    std::cout<<!(l.search(30))<<std::endl;
}

void test_remove(){
    IntList l;
    try{
        l.remove(10);
    }
    catch (const char* e) {
        std::cout << true;
    }
    l.add_front(10);
    l.add_front(20);
    l.remove(10);
    std::cout << l.search(20);
    std::cout << !(l.search(10));
    try{
        l.remove(10);
    }
    catch (const char* e) {
        std::cout << true;
    }  
    l.remove(20);
    std::cout << l.is_empty() << std::endl;
}

void test_print(){
    IntList l;
    l.print();
    l.add_back(1);
    l.print();
    l.add_back(2);
    l.print();
    l.add_back(3);
    l.print();
    l.remove_back();
    l.print();
    l.remove_back();
    l.print();
    l.remove_back();
    l.print();
}

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