#include <algorithm> // pour std::sort
#include <array>
#include<iostream>
int main(){
    
std::array<int, 3> tab1{ 5, 6, 2 }; // paramètres template : type et taille
std::array<int,3> tab2{ 5, 6, 2 }; // depuis C++17 -> std::array<int, 3>
std::array<double,2> tab3{ 2.3, 8.7 }; // depuis C++17 -> std::array<double, 2>
std::cout << tab3[1] << '\n'; // 2ème élément du tableau
std::cout << tab3.at(1) << '\n'; // idem avec test des limites d'indice
// lève une exception de type std::out_of_range
std::cout << tab2.size() << '\n'; // taille du tableau
std::sort(tab1.begin(), tab1.end()); // tri du tableau

return 0;
}
