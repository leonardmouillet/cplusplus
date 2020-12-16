#include<iostream>
#include"stack.h"

int main (int argn, char* argv []){
  
  // vr: mettre les tests dans une fonction test_intstack et non
  // directement dans le main afin de pouvoir réutiliser cette
  // fonction de test lorsque nous modifier le code de votre pile
  
   
    if ( (argn > 1) and (argv[1][0]=='1') ){ // l'argument "1" permet de tester le premier cas d'erreur (taille négative)
        Stack pile_de_taille_negative (-2) ;
    }
    if ( (argn > 1) and (argv[1][0]=='2') ){ // l'argument "2" permet de tester le deuxième cas d'erreur (pile pleine)
        Stack pile(1);
        pile.push(3);
        pile.push(4);
    }
    if ( (argn > 1) and (argv[1][0]=='3') ){ // l'argument "3" permet de tester le troisième cas d'erreur (pile vide)
        Stack pile(3);
        pile.pop();
    }
    if ( (argn > 1) and (argv[1][0]=='0') ){ // l'argument "0" permet de déclencher un test complet sans erreur
        Stack pile(3); // on crée la pile
        pile.print(); // [
        std::cout<<pile.is_empty()<<pile.is_full()<<std::endl; // 10 (la pile est vide et non pleine)
        pile.push(1); // on ajoute 1
        pile.print(); // [1,
        pile.push(2); // on ajoute 2
        pile.print(); // [1, 2
        pile.push(3); // on ajoute 3
        pile.print(); // [1, 2, 3
        pile.print(); // [1, 2, 3
        std::cout<<pile.is_empty()<<pile.is_full()<<std::endl; // 01 (la pile est non vide et plein)
        std::cout<<pile.pop()<<std::endl; // 3
        pile.print(); // [1, 2
        std::cout<<pile.pop()<<std::endl; // 2
        pile.print(); // [1,
    }
    return 0;
}
