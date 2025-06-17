#include<iostream>
#include<array>
#include<algorithm>


bool plusGrand(int a, int b)
{
// a placé avant b, si a plus grand que b
return (a > b);
}




int main(){
//compter nombre de fois apparait un element dans un tableau


std::array<int, 7> tab{10,11,10,10,5,2,10};
int cherche=1;
int remplace = 11;
std::cout<< cherche << " apparait " << std::count(tab.begin(),tab.end(),cherche) << " fois \n";

//trouver un element dans un array 

auto trouve = std::find(tab.begin(), tab.end(), cherche);

if(trouve == tab.end()){

    std::cout<<"ne pas trouver " << cherche<< " ! \n";

 } else{

    std::cout<< "j ai trouver " << cherche << " il est apparait "<< std::count(tab.begin(),tab.end(),cherche) << " fois \n";
 }

 //retourn plus grands 
  std::sort(tab.begin(), tab.end(), plusGrand) ;
 
  std::sort(tab.begin(), tab.end(), plusGrand);  // juste trier

  // Ensuite afficher les éléments
  for (const auto& val : tab) {
      std::cout << val << ' ';
  }
  std::cout << '\n';

  
  return 0;
}