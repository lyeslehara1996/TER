#include<iostream>



template <typename T> 
double multiplication(T x, int n) 
{
    double mul,somme=0;
    for(int i = 1 ; i <= n ; ++i){
        
         mul = x * i ;
         return somme+=mul;
    }
}





int main(){
    
  
    std::cout << "la multiplication "<< multiplication(5, 5) << '\n'; 


    return 0;
}