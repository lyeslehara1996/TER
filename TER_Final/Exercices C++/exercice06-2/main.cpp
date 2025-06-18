/*
 abort() =>
 Termine immédiatement le programme et Il ne nettoie rien (pas de sauvegarde, pas de message, pas de destruction d’objets) comme il tue le prgramme 

 terminate()=> est appelé lorsque Une exception est levée mais non attrapée
                utilisé lorsque on lances une erreur avec throw, mais tu ne fais pas de try/catch pour la gérer.

assert() => assert() affiche une erreur puis appelle abort() et le programme s’arrête immédiatement (si la logique dans assert n'est pas correct)
*/

#include<iostream>
#include<math.h>
#include <cassert>
bool premier(int val) {
    if (val <= 1) return false;
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) return false;
    }
    return true;
}



int main(){
    /*
    si la logique ecrite dans assert est juste ca passe 
    sinon elle stop le programme (appelle la fonction abort)
    */
    assert(!premier(0));
    assert(!premier(1));
    assert(premier(2));
    assert(premier(3));
    assert(!premier(4));
    assert(premier(5));
    assert(premier(7));
    assert(!premier(9));
    assert(premier(11));
    assert(premier(13));
    assert(!premier(15));
    assert(!premier(16));
    assert(premier(17));
    assert(premier(19));
    assert(premier(97));
    assert(!premier(99));
    assert(premier(13417));

    std::cout << "Success!\n";

    return 0;
}