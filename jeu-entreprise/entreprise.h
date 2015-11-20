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
        std::vector <Objet> stock;
        float cout_fixe;
        float cout_variable;
        
    public:
        Entreprise(const std::string &, float);
        Entreprise(const std::string &, float, float, float);

        float get_prix_de_vente() const;
        void set_prix_de_vente(float);

        float get_cout_fixe() const;
        void set_cout_fixe(float);

        float get_cout_variable() const;
        void set_cout_variable(float);
        
        std::vector <Objet> get_stock() const;

        std::vector <Objet> produire(int);
};

#endif // ENTREPRISE_H
