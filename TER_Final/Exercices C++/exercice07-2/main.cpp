#include<iostream>

template <typename T>
T sommeMultiplication(T x, int n) {
    T somme = 0;  
    
    for (int i = 1; i <= n; ++i) {
        somme += i * x;  
    }
    
    return somme;  
}


int main(){
  
    std::cout << "la multiplication "<< sommeMultiplication(5, 5) << '\n'; 

    return 0;
}