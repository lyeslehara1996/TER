#include <iostream>

#include "es.h"

int main()
{
int a;
int b;
std::cout << "Donner un nombre entier \n";
std::cin>> a;

std::cout << "Donner un nombre entier  \n";
std::cin>> b;


std::cout << somme(a, b) << '\n'; 
return 0;
}
