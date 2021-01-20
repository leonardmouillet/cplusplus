#pragma once 

class Shape {

protected :

    Shape (int x, int y) : x(x), y(y) {}

public :

    void moove (int x, int y) {
        x = x;
        y = y;
    }

    virtual int area()=0;

private:

    int x;
    int y;

};

class Circle : public Shape{

        public :

        Circle(int x, int y, int r) : Shape(x,y), r(r) {}

        int area () {return 3*(r^2);}

        private :

        int r;
    
    };

class Square : public Shape{

        public :

        Square(int x, int y,int c) : Shape(x,y) , c(c) {}
        int area() { return c^2 ;}

        private :

        int c;
    
    };
