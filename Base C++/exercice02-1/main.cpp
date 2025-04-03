#include<iostream>

void saisie(int &a, int &b){


        std::cout << "Donner deux valeurs a et b :" << std::endl;
        std::cin >> a;
        std::cin >> b;
  
}


float somme (int a, int b) {
float somme =0;
somme = a +b;

return somme;


}

void affichage(float somme){
    std::cout << "La somme des deux nombres a et b est : " << somme << std::endl;

}
int main(){

int a ;
int b ;


saisie(a,b);
float s = somme(a,b);
affichage(s);


    return 0;

}