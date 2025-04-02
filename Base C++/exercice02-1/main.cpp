#include<iostream>


float somme (int a, float b) {
float somme =0;
somme = a +b;

return somme;


}

int main(){

int a ;
float b ;


std::cout << "Donner deux valeur a et b "<<std::endl;
std::cin >> a;
std::cin >> b;


std::cout <<"la somme de deux nombre a et b est : "<< somme(a,b) <<std::endl;


    return 0;

}