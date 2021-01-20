#include "shape.h"
#include <iostream>
#include <vector>

void test_constructor(){
    Circle c (10,10,2);
    Square s (10,10,2);
}

void test_area(){
    Circle c (10,10,2);
    std::cout<<c.area()<<std::endl;
    Square s (10,10,2);
    std::cout<<s.area()<<std::endl;
}

void test_vector(){
    Circle c (10,10,2);
    std::vector<Shape*> v;
    v.push_back(&c);
    v[0] -> moove(5,5);
    std::cout<<v[0] -> area()<<std::endl;
}

void test_print_location(){
    Circle c (10,10,2);
    c.print_location();
}

void test_moove(){
    Circle c (10,10,2);
    c.print_location();
    c.moove(10,20);
    c.print_location();
}
