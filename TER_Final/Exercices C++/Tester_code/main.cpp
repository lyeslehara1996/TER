
#include<iostream>
int main()
{
    int tab[5] { 6, 3, 1, 9, 4 };
    std::cout << tab[0] << '\n'; // valeur du premier élément
    std::cout << &tab[0] << '\n'; // adresse du premier élément
    std::cout << tab << '\n'; // pointeur contenant l'adresse du
    // du premier élément
    std::cout << *tab << '\n';
return 0;
}