// Classe (abstraite) representant une Entité.
// Une entité est un acteur du marché (client ou entreprise)
// avec:
//      - un nom (constant)
//      - une tresorerie (variable)
//      - un stock (vecteur d'Objets)


#ifndef ENTITE_H
#define ENTITE_H

#include <vector>
#include <QString>

//  forward-declaration de la classe.
// On ne peux pas include "objet.h", car ça cause un import circulaire
class Objet;

class Entite
{
    protected:
        QString nom;
        float tresorerie;
        std::vector <Objet*> stock;

    public:
        Entite(const QString &, float);

        const QString & get_nom() const;
        float get_tresorerie() const;

        void set_tresorerie(float);

        std::vector <Objet*> get_stock() const;
        void ajouter_au_stock(Objet*);
        void retirer_au_stock(Objet*);

        void gestion_des_stocks();
};

#endif // ENTITE_H
