#include "intlist.h"

void test_list_constructor(){
    IntList l ;
    std::cout << std::boolalpha << true << std::endl;
}

void test_add_front(){
    IntList l;
    l.add_front (10);
    //l.add_front (20);
    l.print();
    std::cout << std::boolalpha << true << std::endl;
}

int test_add_back(){
    IntList l;
    //l.add_back (10);
    //l.add_back (20);
    l.print();
    std::cout << std::boolalpha << true << std::endl;
}

int main (){
    test_list_constructor();
    test_add_front();
    test_add_back();
    return 0;
}