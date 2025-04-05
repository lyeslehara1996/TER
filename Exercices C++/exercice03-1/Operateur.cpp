#include<iostream>
#include "Operateur.h"
using namespace std;


void operateur(int a, float b){

int n;
cout <<"choisi 1 => + || 2 => - || 3 => * || 4=> / \n";
cin >> n;
switch (n){

    case 1:  cout<<" a + b =  "<< a + b <<"\n";
    break;

    case 2 : cout<<"a - b = " << a - b <<"\n";
    break;
    
    case 3 : cout<<"a * b = " << a * b <<"\n";
   break;

    case 4 :  cout<<"a / b = " << a / b <<"\n";
    break;

default: cout<< "choisir entre 1 et 4 seulemnt \n";
}

}