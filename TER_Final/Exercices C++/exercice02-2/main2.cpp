
/*
1: Quand tu passes un argument par valeur, la fonction reçoit une copie de la variable.
Donc toute modification dans la fonction ne change pas la variable originale.
    On vois que la valeur obtenue dans la fonction et la valeeur obtenue aprés la fonction n'est la meme 


2: Quand tu passes une variable par référence avec &, la fonction reçoit l'adresse de la variable originale.
Donc, toute modification modifie vraiment la variable d'origine.

*/
#include<iostream>

int somme(int a , int b)
{

    int somme = a + b ;
    std::cout<<"dans la fonction , la somme de deux valeur est " << somme<<std::endl;
}

int main(){

int a, b,s;
    std::cout<<"donner la valeur de a"<<std::endl;
    std::cin>>a;

    std::cout<<"donner la valeur de b"<<std::endl;
    std::cin>>b;
s = somme(a,b);

std::cout<<"la somme de a et b est : "<< s <<std::endl;
    return 0;
}