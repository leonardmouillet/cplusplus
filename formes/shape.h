#pragma once 
#include <iostream>

class Shape {

protected :

    Shape (int x, int y) : x(x), y(y) {}

public :

    void moove (int a, int b) {
        x = a;
        y = b;
    }

    void print_location(){
        std::cout <<"("<< x <<","<< y <<")"<< std::endl;
    }

    virtual int area()=0;

private:

    int x;
    int y;

};

class Circle : public Shape{

        public :

        Circle(int x, int y, int r) : Shape(x,y), r(r) {}

        int area () {return 3*(r*r);}

        private :

        int r;
    
    };

class Square : public Shape{

        public :

        Square(int x, int y,int c) : Shape(x,y) , c(c) {}
        int area() { return c*c ;}

        private :

        int c;
    
    };