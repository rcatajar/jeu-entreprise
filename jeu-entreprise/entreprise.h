#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <string>
#include <vector>

#include "entite.h"
#include "objet.h"

class Entreprise : public virtual Entite
{
    protected:
        float prix_de_vente;
    public:
        Entreprise(const std::string &, float);

        float get_prix_de_vente() const;
        void set_prix_de_vente(float);

        std::vector <Objet> produire(int);

        void remove_objet(Objet*);
};

#endif // ENTREPRISE_H
