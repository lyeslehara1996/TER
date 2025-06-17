#include "NoteMap.hpp"
#include <iostream>

int& NoteMap::operator[](const std::string& nom) {

    
    auto it = std::find_if(m_map.begin(), m_map.end(),
            [&nom](const NoteEtudiant& etu) {
                return etu.nom == nom;
            });

    if (it != m_map.end()) {
        return it->note;
    }

    m_map.push_back(NoteEtudiant(nom));

    return m_map.back().note;
}

void NoteMap::afficher() const {
    for (const auto& etu : m_map) {
        std::cout << etu.nom << " : " << etu.note << std::endl;
    }
}
