
/*
1- les variable locale => Portée : valable seulement dans la fonction ou le bloc où elle est déclarée.
                       => Durée  : de l’entrée dans le bloc {} jusqu’à la fin du bloc

2- la variable globale est déclaré en dehors de toute fonction 
                       => Porté : elle est accissible dans tout les fichiers 
                       => Durée : toute l'éxecution du programme 
                       
3 - lien interne utilisé dans le fichier spécifique (locale par defaut) exp: static int cpt = 0;
                      => Porté: Cette variable n’est visible que dans ce fichier (.cpp)
                      => Durée: Même si un autre fichier essaie d’y accéder → ce n’est pas possible (utilisé seulement dans le fichier ou elle est déclarer)

4- lien extern visible dans tout le programme (visible dans le fichier est déclarer ou en dehors )
                     => Porté:  cette variable est accessible dans n'importe quel fichier car elle extern 
                                mais on utilise extern pour dire que cette variable est déclaré dans un autre ficher mais on veut juste y accéder 
*/

#include <iostream>
#include "constante.h"
extern int varmax; //variable globale extern 

int main (){
int var2; //variable locale 
 std::cout<<"donner une valeur que tu doit comparer \n";
std::cin>>var2;

if(varmax > var2  ){
    std::cout<<"la variable " << var2 << " est plus petite que " << varmax << '\n';
}else{
    
    std::cout<<"la variable " << var2 << " est plus grande que " << varmax << '\n';

}

    return 0;
}