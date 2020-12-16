#include<iostream>

class IntCell { 
    friend class IntList;
private:
    IntCell (int i) {
        value = i;
        previous_cell = 0;
        next_cell = 0;
    }  

    int value;
    IntCell* previous_cell;
    IntCell* next_cell;

};

class IntList {

public:

    IntList () {
        head = 0;
        tail = 0;
    }

    void add_front (int i) {
        IntCell new_cell (i);
        if (head == 0) {
            head = &new_cell;
            tail = &new_cell;
        }
        else {
            new_cell.next_cell = head;
            (*head).previous_cell = &new_cell;
            head = &new_cell;
        }
    }
   
    void add_back (int i) {
        IntCell new_cell (i);
        if (tail == 0) {
            head = &new_cell;
            tail = &new_cell;
        }
        else {
            new_cell.previous_cell = tail;
            (*head).next_cell = &new_cell;
            tail = &new_cell;
        }
    }
   
    void remove_front () {
        if (head != 0) {
            head = (*head).next_cell;
            (*head.previous_cell) = 0;           
        }
        else {
            throw ("la file est vide")
        }
    }
   
   void remove_back () {
        if (tail != 0) {
            tail = (*tail).previous_cell;
            (*tail.next_cell)=0;            
        }
        else {
            throw ("la file est vide")
        }
    }
   
   void print () {
       std::cout<<"[";
       IntCell* top = head;
       while (top != 0){
           std::cout<<(*top).value<<" ";
           top = (*top).next_cell;
        }
        std::cout<< "]" << std::endl;
    }

private:

   IntCell* head;
   IntCell* tail;

};