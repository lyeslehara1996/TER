#ifndef TEMPLATE_IMAGE_H
#define TEMPLATE_IMAGE_H

#include <cstddef>
#include <vector>           
#include <iostream>      


namespace v1_1{

    
template<typename T>
class Image {
public:
Image(int largeur, int hauteur);
Image();

int getlargeur() const;
int gethauteur() const;

const std::vector<T>& getData() const;
void setData(const std::vector<T>& image);

void creerImageBlache();
void creerSinusoidale(double frequence);
void creerDamier(int tailleCase);

void sauvegarderPGM(const std::string& fichier) const;
void ecrireFichierRaw(const std::string& fichier) const;

void printImage() const;

static Image<T> lireImageRAW(const std::string& fichier, size_t largeur, size_t hauteur, bool bigEndian = false);


template<typename Dst>
Image<Dst> convertirImage(bool ajuster = false) const;

T& operator()(int x, int y);
const T& operator()(int x, int y) const;

protected:
size_t _largeur, _hauteur;
std::vector<T> _image;
};

}

#endif

