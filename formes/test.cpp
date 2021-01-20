#include "shape.h"
#include <iostream>
#include <vector>

void test_constructor(){
    Circle c (10,10,2);
    Square s (10,10,2);
}

void test_area(){
    Circle c (10,10,2);
    std::cout<<c.area();
    Square s (10,10,2);
    std::cout<<s.area();
}

void test_vector(){
    Circle c (10,10,2);
    std::vector<Shape*> v;
    v.push_back(&c);
    v[0] -> moove(5,5);
    v[0] -> area();
}