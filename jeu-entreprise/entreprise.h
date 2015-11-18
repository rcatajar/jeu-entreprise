#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include "entite.h"

class Entreprise : public virtual Entite
{
    public:
        Entreprise(const std::string &, float);
};

#endif // ENTREPRISE_H
