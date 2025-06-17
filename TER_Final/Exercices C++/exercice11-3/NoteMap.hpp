#ifndef NOTE_MAP_HPP
#define NOTE_MAP_HPP

#include <vector>
#include <algorithm>
#include "NoteEtudiant.hpp"

class NoteMap {
private:
    std::vector<NoteEtudiant> m_map;

public:
   
    int& operator[](const std::string& nom);

  
    void afficher() const;
};

#endif 
