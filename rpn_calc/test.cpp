#include<iostream>
#include"rpn_calc.h"

int main (int argc, char* argv []) {
    std::cout << rpn_calc(argc-1, argv+1) << std::endl;
    return 0;
}