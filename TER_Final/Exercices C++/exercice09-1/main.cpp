#include<iostream>

int find(const int tab[], int valeur, int gauche, int droite)
{

    while (gauche <= droite)
    {
    int mediane =  (droite + gauche) / 2 ;

    if(tab[mediane] == valeur){
        return mediane ;
    }else if (tab[mediane] < valeur ){
        gauche = mediane +1 ;
    }else{
        droite = mediane - 1;
    }

}
return -1;

}

int main(){



    const int tab[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // Test du résultat sur un ensemble de valeurs
    const int numValeursTest{ 9 };
    const int valeursTest[numValeursTest]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    int resultatAttendu[numValeursTest]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Boucle sur les valeurs de test
    for (int i{ 0 }; i < numValeursTest; ++i)
    {
        int index = find(tab, valeursTest[i], 0,  static_cast<int>(sizeof(tab)) - 1);
        if (index == resultatAttendu[i])
             std::cout << "valeur test " << valeursTest[i] << " OK\n";
        else
             std::cout << "valeur test " << valeursTest[i] << " NOK\n";
    }

    return 0;
}