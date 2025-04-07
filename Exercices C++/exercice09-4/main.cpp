#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vect{4, 1, 3, 5, 2, 3, 1, 7};
    auto affiche = [](std::vector<int>& vect) {
        std::for_each(vect.begin(), vect.end(), [](int val) {
            std::cout << val << " ";
        });
        std::cout << std::endl;
    };

    std::cout << "Éléments du vecteur : \n";
    affiche(vect);

 

    auto it = std::find_if(vect.begin(), vect.end(), [](int val){return val>4;});
    if (it != vect.end()) {
        std::cout << "Élément supérieur à 4 trouvé : " << *it << '\n';
    } else {
        std::cout << "Aucun élément supérieur à 4 trouvé." << std::endl;
    }

    auto triDecroissant = [](int a, int b) -> bool {
        return a > b;
    };
    std::sort(vect.begin(), vect.end(), triDecroissant);
    std::cout << "Vecteur trié décroissant : ";
    affiche(vect);


    auto estSuperieurA5 = [](int val) -> bool {
        return val > 5;
    };
    int count = std::count_if(vect.begin(), vect.end(), estSuperieurA5);
    std::cout << "Nombre d'éléments > 5 : " << count << std::endl;


    return 0;
}