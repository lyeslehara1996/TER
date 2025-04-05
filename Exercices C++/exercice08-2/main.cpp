#include<iostream>
#include<vector>

#include <cstdlib> // pour rand
#include <ctime> 


//remplir tableau dynamique 

std::vector<int> randomVectorInt(int size) {
    std::vector<int> vec(size);
    for (int& val : vec) {
        val = std::rand() % 20;
    }
    return vec;
}

// Affiche un std::vector<int>
void afficheVectorInt(const std::vector<int>& vec) {
    for (const int& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}


template<typename T>
std::vector<T> randomArrayVectorTemplate(size_t size) {
    std::vector<T> array(size);
    for (T& val : array) {
        val = static_cast<T>(std::rand() % 20);  // cast pour support de types génériques
    }
    return array;
}

// Fonction template pour afficher un vecteur
template<typename T>
void afficherTableauTemplate(const std::vector<T>& array) {
    for (const T& val : array) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}


int main(){
    std::srand(std::time(nullptr));
    int size ;
    std::cout<<"donner la tailler a allouer au tableau vector \n";
    std::cin>> size;

    std::vector<int> arr = randomVectorInt(size);
    afficheVectorInt(arr);


    std::vector<float> arr2 = randomArrayVectorTemplate<float>(size);
    std::cout << "Tableau de floats : ";
    afficherTableauTemplate(arr2);
    return 0;
}