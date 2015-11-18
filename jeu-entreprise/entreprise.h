#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include "entite.h"

class Entreprise : public virtual Entite
{
    protected:
        float prix_de_vente;
    public:
        Entreprise(const std::string &, float);

        float get_prix_de_vente() const;
        void set_prix_de_vente(float);
};

#endif // ENTREPRISE_H
