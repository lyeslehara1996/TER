#include<iostream>
#include "somme.h"

using namespace std;





int main(){

int a;
float b;

cout << "Donner un nombre entier \n";
cin>> a;

cout << "Donner un nombre floattant  \n";
cin>> b;

cout << "la somme de deux nombre est "<< somme(a,b)<<"\n";

    return 0;
}