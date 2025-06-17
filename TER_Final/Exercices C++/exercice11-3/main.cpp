#include <iostream>
#include "NoteMap.hpp"

int main() {
    NoteMap notes{};

	notes["Jamil"] = 15;
	notes["Jamil"] = 25;
	notes["Frank"] = 11;


	std::cout << "Jamil a une note de " << notes["Jamil"] << '\n';
	std::cout << "Frank a une note de " << notes["Frank"] << '\n';
notes.afficher();
    return 0;
}