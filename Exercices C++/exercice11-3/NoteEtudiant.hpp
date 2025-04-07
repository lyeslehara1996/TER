#ifndef NOTE_ETUDIANT_HPP
#define NOTE_ETUDIANT_HPP

#include <string>

struct NoteEtudiant {
    std::string nom;
    int note;

    // Constructeur avec initialisation
    NoteEtudiant(const std::string& nom_, int note_ = 0);
};

#endif 