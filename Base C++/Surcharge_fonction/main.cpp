#include<iostream>


template <typename T = int> 
T addition(T x, T y) 
{
return x + y ;
}


template <typename T> 
double multiplication(int x, T y) 
{
return x * y ;
}


template <typename T> 
T sustraction(T x, T y) 
{
return x - y ;
}



int main(){
    
    std::cout << "l addition "<<addition<>(5, 2) << '\n'; 
    std::cout << "la multiplication "<< multiplication(5, 2.5) << '\n'; 
    std::cout << "la soustration "<<sustraction<>(5, 2) << '\n'; 

    return 0;
}