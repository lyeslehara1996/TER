

#include<iostream>


int main(){

int var{ 5 };
int* ptr{ &var };

std::cout <<"var "<< var << '\n'; // indirection donne un int
std::cout <<"&var "<< &var << '\n'; // indirection donne un int
std::cout <<"ptr "<< ptr << '\n'; // indirection donne un int
std::cout <<"*ptr "<< *ptr << '\n'; // indirection donne un int

int** ptrptr { &ptr };
std::cout <<"ptrptr"<< ptrptr << '\n';
std::cout <<"*ptrptr"<< *ptrptr << '\n';
std::cout <<"**ptrptr"<< **ptrptr << '\n';
std::cout << **ptrptr << '\n';

    return 0;
}