#ifndef PAIRECHAINEVALEUR_HPP
#define PAIRECHAINEVALEUR_HPP

#include <string>
#include "Paire2.hpp"

template<typename T>
class PaireChaineValeur : public Paire2<std::string, T> {
public:
    PaireChaineValeur(const std::string& chaine, T valeur);
};


template<typename T>
PaireChaineValeur<T>::PaireChaineValeur(const std::string& chaine, T valeur)
    : Paire2<std::string, T>(chaine, valeur) {}

#endif 
