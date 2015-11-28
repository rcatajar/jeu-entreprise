#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <string>
#include <typeinfo> // a retirer plus tard  http://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c

#include "entite.h"

class Entreprise : public Entite
{
    protected:
        float prix_de_vente;
        float cout_fixe;
        float cout_variable;
        float investissement_realise;
        float qualite_marginale;
        bool ia;

    public:
        Entreprise(const std::string &, float, bool);

        float get_prix_de_vente() const;
        void set_prix_de_vente(float);

        float get_cout_fixe() const;
        void set_cout_fixe(float);

        float get_cout_variable() const;
        void set_cout_variable(float);

        bool is_ia();

        void produire(int);
        void investir(int);

        float get_investissement_realise() const;

        // à appeler avec l'objet vendu. Le retire du stock et augmente la tréso
        void vente_objet(Objet*);

        void phase_de_marketing();
        void phase_de_production();
        void phase_de_recherche();
};

#endif // ENTREPRISE_H
