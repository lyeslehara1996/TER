#include <iostream>

int somme(int x, int y); 

int main()
{
int a;
int b;
int c=65539;
std::cout <<  "c  "<<c<<'\n';
std::cout << "Donner un nombre entier \n";
std::cin>> a;

std::cout << "Donner un nombre entier  \n";
std::cin>> b;


std::cout << somme(a, c) << '\n'; 
return 0;
}


int somme(int x, int y)
{
return x + y;
}