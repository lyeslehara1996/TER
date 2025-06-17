#include <iostream>


bool retourneVrai() {
    static int cpt = 0;
    cpt++;
    if(cpt<=3){
        return true;
    }else{
        return false;
    }
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
