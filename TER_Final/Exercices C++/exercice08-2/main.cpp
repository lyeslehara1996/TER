#include<iostream>
#include<vector>
#include <cstdlib>  
#include <ctime>   

void randomArrayCInt(int* tab, int size) {
    for (int i = 0; i < size; ++i) {
        tab[i] = std::rand() % 100;
    }
}

int maxArrayCInt(const int* tab, int size) {
    int max = tab[0];
    for (int i = 1; i < size; ++i) {
        if (tab[i] > max) max = tab[i];
    }
    return max;
}
template <typename T>
void randomArrayC(T* tab, int size) {
    for (int i = 0; i < size; ++i) {
        tab[i] = static_cast<T>(std::rand() % 100);
    }
}

template <typename T>
T maxArrayC(const T* tab, int size) {
    T max = tab[0];
    for (int i = 1; i < size; ++i) {
        if (tab[i] > max) max = tab[i];
    }
    return max;
}

void randomArrayInt(std::vector<int>& vec) {
    for (int& val : vec) {
        val = std::rand() % 100;
    }
}

int maxArrayInt(const std::vector<int>& vec) {
    int max = vec[0];
    for (int val : vec) {
        if (val > max) max = val;
    }
    return max;
}
template <typename T>
void randomArray(std::vector<T>& vec) {
    for (T& val : vec) {
        val = static_cast<T>(std::rand() % 100);
    }
}

template <typename T>
T maxArray(const std::vector<T>& vec) {
    T max = vec[0];
    for (const T& val : vec) {
        if (val > max) max = val;
    }
    return max;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int taille;
    std::cout << "Entrez la taille du tableau : ";
    std::cin >> taille;

    //  Tableau dynamique de type C
    int* tabC = new int[taille];
    randomArrayCInt(tabC, taille);
    std::cout << "Max tableau C (int*) : " << maxArrayCInt(tabC, taille) << "\n";
    delete[] tabC;  // SLibération de mémoire

    //  Template tableau C
    double* tabCT = new double[taille];
    randomArrayC(tabCT, taille);
    std::cout << "Max tableau C (template) : " << maxArrayC(tabCT, taille) << "\n";
    delete[] tabCT;

    //  std::vector<int>
    std::vector<int> vecInt(taille);
    randomArrayInt(vecInt);
    std::cout << "Max std::vector<int> : " << maxArrayInt(vecInt) << "\n";

    //  std::vector<T>
    std::vector<float> vecT(taille);
    randomArray(vecT);
    std::cout << "Max std::vector<float> : " << maxArray(vecT) << "\n";

    return 0;
}
