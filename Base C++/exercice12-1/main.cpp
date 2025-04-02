#include <iostream>
#include "fruit.h"
#include "Pomme.h"
#include "Banane.h"


int main()
{
	Pomme a{ "rouge" };
	Banane b{};

	std::cout << "Ma " << a.getnom() << " est " << a.getcouleur() << ".\n";
	std::cout << "Ma " << b.getnom() << " est " << b.getcouleur() << ".\n";


    return 0;
}