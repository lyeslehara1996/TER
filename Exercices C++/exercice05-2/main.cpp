#include <iostream>


bool retourneVrai() {
    static int cpt = 0;
    cpt++;
    return cpt <= 3;
}

int main() {
    for (int i = 0; i < 20; i++) {
        if (retourneVrai()) {
            std::cout << "Appel " << i << ": Vrai " << '\n';
        } else {
            std::cout << "Appel " << i << ": Faux " << '\n';
        }
    }
    return 0;
}
