#include<iostream>
#include"math.h"

using namespace std;

int bissextile(int a){

if((a % 4 == 0  && a % 100 != 0 ) || (a % 400 == 0  )){

    return 1;

}else{

   
    return 0;
}
}
    


int main(){

int annee;

cout << "Donner une annee valable  \n";
cin>> annee;



double bisex = bissextile(annee);

if(bisex == 1){

    cout << "l'annee " << annee << " est bissextile \n";
}else{

    cout << "l'annee " << annee << " n'est pas pasbissextile \n";
}

    return 0;
}