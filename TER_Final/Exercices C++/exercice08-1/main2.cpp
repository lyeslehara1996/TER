

#include<iostream>
int main(){

    int valeur = 20;
    int* v=  &valeur;

    int* ptr = v;
std::cout<<"valeur = "<< valeur <<'\n';
std::cout<<"&valeur = "<< v <<'\n';
std::cout<<"*valeur = "<< *v <<'\n';

std::cout<<"valeur = "<< *ptr <<'\n';
std::cout<<"&ptr = "<< &ptr <<'\n';
std::cout<<"&valeur = "<< ptr <<'\n';
//std::cout<<"*valeur = "<< ptr <<'\n';

    return 0;
}