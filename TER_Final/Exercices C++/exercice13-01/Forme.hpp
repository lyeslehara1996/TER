#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>

class Forme {
public:
    virtual std::ostream& affiche(std::ostream& os) const = 0;
    virtual ~Forme();

    friend std::ostream& operator<<(std::ostream& os, const Forme& f) {
        return f.affiche(os);
    }
};

#endif
