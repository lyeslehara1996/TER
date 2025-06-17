#include<iostream>
#include<math.h>
#include<array>
#include <cstdlib>
#include <ctime>

const int size = 10;

void randomArrayCInt(int (&arr)[size]){

    for(int i = 0 ; i<size ; ++i){
        arr[i]= std::rand() % 10 ;
    }
}
void afficheTable(int  (&arr)[size]){

    for(int i=0; i< size; ++i){

        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
int maxArrayCInt(const int  (&arr)[size] ){
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// tableau statique  type c avec Template
template <typename T, size_t N>
void randomArrayC(T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        arr[i] = std::rand() % 100;
    }
}

template <typename T, size_t N>
T maxArrayC(const T (&arr)[N]) {
    T max = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
template<typename T, size_t N>
void afficheTableau(const T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
//tableau statique sd::array type c (int )
std::array<int, size> randomArrayInt() {
    std::array<int, size> arr;
    for (int& val : arr) {
        val = std::rand() % 10;
    }
    return arr;
}

int maxArrayInt(const std::array<int, size>& arr) {
    int max = arr[0];
    for (const int& val : arr) {
        if (val > max) max = val;
    }
    return max;
}
void afficheTableau3(const std::array<int,size>&arr){
    for(const int& val:arr){
        std::cout << val  << ' ';
    }
    std::cout << std::endl;
}
//tableau statique std::array template 
template <typename T, size_t N>
std::array<T, N> randomArray() {
    std::array<T, N> arr;
    for (T& val : arr) {
        val = std::rand() % 100;
    }
    return arr;
}

template <typename T, size_t N>
T maxArray(const std::array<T, N>& arr) {
    T max = arr[0];
    for (const T& val : arr) {
        if (val > max) max = val;
    }
    return max;
}
template<typename T, size_t N>
void afficheTableau4(const std::array<T,N>&arr){

 for(const int& val:arr){
        std::cout << val  << ' ';
    }
    std::cout << std::endl;

}

int main(){

    std::srand(static_cast<unsigned>(std::time(nullptr)));

int arr[size];
//avec un tableau c statique 
randomArrayCInt(arr);
afficheTable(arr);
int max = maxArrayCInt(arr);
std::cout<<"le maximum dans ce tableau est : " << max <<'\n';

    //avec un tabeau C template
double arr2[size];
randomArrayC(arr2);
afficheTableau(arr2);
std::cout << "Max (C template): " << maxArrayC(arr2) << std::endl;

//avec tableau statique std::array (int)

auto arr3 = randomArrayInt();
afficheTableau3(arr3);
std::cout << "Max (std::array int ): " << maxArrayInt(arr3) << std::endl;

//avec tableau statique std::array (template)

auto arr4 = randomArray<float, size>();
afficheTableau4(arr4);
std::cout << "Max (std::array templkate ): " << maxArray(arr4) << std::endl;
return 0;
}