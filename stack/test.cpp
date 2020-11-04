#include<iostream>
#include"stack.h"

int main (){
    Stack pile(3); // on crée la pile
    pile.print(); // [
    std::cout<<pile.pop()<<std::endl; // 0 (résultat par défaut du pop lorsque la pile est vide)
    std::cout<<pile.is_empty()<<pile.is_full()<<std::endl; // 10 (la pile est vide et non pleine)
    pile.push(1); // on ajoute 1
    pile.print(); // [1,
    pile.push(2); // on ajoute 2
    pile.print(); // [1, 2
    pile.push(3); // on ajoute 3
    pile.print(); // [1, 2, 3
    pile.push(4); // on essaie d'ajouter 4 mais la pile est pleine donc rien n'est ajouté
    pile.print(); // [1, 2, 3
    std::cout<<pile.is_empty()<<pile.is_full()<<std::endl; // 01 (la pile est non vide et plein)
    std::cout<<pile.pop()<<std::endl; // 3
    pile.print(); // [1, 2
    std::cout<<pile.pop()<<std::endl; // 2
    pile.print(); // [1,
    return 0;
}