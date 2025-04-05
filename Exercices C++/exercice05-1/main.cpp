#include <iostream>
#include "constante.h"
extern int varmax;

int main (){
int var2;
 std::cout<<"donner une valeur que tu doit comparer \n";
std::cin>>var2;

if(varmax > var2  ){
    std::cout<<"la variable " << var2 << " est plus petite que " << varmax << '\n';
}else{
    
    std::cout<<"la variable " << var2 << " est plus grande que " << varmax << '\n';

}

    return 0;
}