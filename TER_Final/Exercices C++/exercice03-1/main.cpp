#include<iostream>

using namespace std;



void saisie(float &x, float &y, char &oper) {
    std::cout << "Entrez deux valeurs  : ";
    std::cin >> x >> y;

    std::cout << "Entrez l'opération (+, -, *, /) : ";
    std::cin >> oper;
}


float calucle(float x, float y, char oper){


    switch (oper)
    {
         case '+': return x + y;
         break;
        case '-': return x - y;
        break;
        case '*': return x * y;
        break;
        case '/':
            if (y != 0) return x / y;
            std::cout << "Erreur : division par zéro !" << std::endl;
            return 0;
        break;
        default:
            std::cout << "Opérateur non valide !" << std::endl;
            return 0;
        break;
    }
}

void affichage(float x, float y, char oper, float result) {
    std::cout << x << " " << oper << " " << y << " = " << result << std::endl;
}


int main(){

float a;
float b;
char oper;
saisie(a,b,oper);
float result = calucle(a,b,oper);
affichage(a,b,oper,result);

    return 0;
}