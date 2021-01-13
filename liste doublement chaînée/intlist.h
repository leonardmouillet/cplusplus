#pragma once
// vr: protège ton header file contre l'inclusion multiple du header
#include<iostream>

class IntCell { 

    friend class IntList;

private:

  IntCell (int i) : 
      value (i), 
      previous_cell (nullptr), 
      next_cell (nullptr) {}

    int value;
    IntCell* previous_cell;
    IntCell* next_cell;

};

class IntList {

public:

    // vr: utilise la liste d'initialisation
    IntList () : head(nullptr), tail(nullptr) {}

    void add_front (int i) {
        IntCell* new_cell = new IntCell (i);
        if (head == nullptr) {
            head = new_cell;
            tail = new_cell;
        }
        else {
            (*new_cell).next_cell = head;
            (*head).previous_cell = new_cell;
            head = new_cell;
        }
    }
   
    void add_back (int i) {
        IntCell* new_cell = new IntCell (i);
        if (tail == nullptr) {
            head = new_cell;
            tail = new_cell;
        }
        else {
            (*new_cell).previous_cell = tail;
            (*tail).next_cell = new_cell;
            tail = new_cell;
        }
    }
   
    void remove_front () {
        if (head != nullptr) {
            IntCell* past_head = head;
            head = (*head).next_cell;
            if (head != nullptr) {
                (*head).previous_cell = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete past_head;           
        }
        else {
            throw ("la file est vide");
        }
    }
   
    void remove_back () {
        if (tail != nullptr) {
            IntCell* past_tail = tail;
            tail = (*tail).previous_cell;
            if (tail != nullptr){
                (*tail).next_cell=nullptr;
            }
            else{
                head = nullptr;
            }
            delete past_tail;            
        }
        else {
            throw ("la file est vide");
        }
    }
   
    void print () {
        std::cout<<"[";
        IntCell* top = head;
        while (top != nullptr){
            std::cout<<(*top).value<<" ";
            top = (*top).next_cell;
        }
        std::cout<< "]" << std::endl;
    }

    bool search (int i) {
        IntCell* top = head;
        bool result = false;
        while (top != nullptr and result !=true) {
            result = ( (*top).value == i );
            top = (*top).next_cell;
        } 
        return result;
    }

    bool is_empty() {
        return head==nullptr;
    }

    void remove(int i) {
        IntCell* top = head;
        bool test = false;
        while (top != nullptr and test !=true) {
            test = ( (*top).value == i );
            if (test == true) {
                if ((*top).previous_cell != nullptr){
                    (*((*top).previous_cell)).next_cell=(*top).next_cell;
                }
                else {
                    head = (*top).next_cell;
                }
                if((*top).next_cell != nullptr){
                    (*((*top).next_cell)).previous_cell=(*top).previous_cell;
                }
                else {
                    tail = (*top).previous_cell;
                }
                delete top ;
            } // vr: attention ici tu viens de faire delete top et
	      // ensuite tu fais top->next_cell donc un segfault
	    // tu dois mettre un else 
            top = (*top).next_cell;
        }
        if (test==false){
            throw ("pas de tel élément dans la liste");
        }         
    }

private:
   IntCell* head;
   IntCell* tail;

};
