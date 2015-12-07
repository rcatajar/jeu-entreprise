#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <QString>
#include <typeinfo> // a retirer plus tard  http://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c

#include "entite.h"

class Entreprise : public Entite
{
    protected:
        float prix_de_vente;
        float cout_fixe;
        float cout_variable;
        float investissement_realise;
        int qualite_marginale;
        bool ia;
        bool max_recherche;
        float investissement_max;

    public:
        Entreprise(const QString &, float, bool);

        float get_prix_de_vente() const;
        void set_prix_de_vente(float);

        float get_cout_fixe() const;
        void set_cout_fixe(float);

        float get_cout_variable() const;
        void set_cout_variable(float);

        bool is_ia() const;

        bool recherche_max_atteinte() const;
        void investir(int);
        float get_investissement_realise() const;
        int get_qualite_marginale() const;
        int get_investissement_restant_avant_max() const;

        void produire(int);

        // à appeler avec l'objet vendu. Le retire du stock et augmente la tréso
        void vente_objet(Objet*);

        void phase_de_marketing(int);
        void phase_de_production(int);
        void phase_de_recherche(int);
};

#endif // ENTREPRISE_H
