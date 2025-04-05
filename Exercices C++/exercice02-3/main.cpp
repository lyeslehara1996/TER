#include <iostream>

int somme(int x, int y); 

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


int somme(int x, int y)
{
return x + y;
}