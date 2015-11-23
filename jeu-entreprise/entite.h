// Classe (abstraite) representant une Entité.
// Une entité est un acteur du marché (client ou entreprise)
// avec un nom (constant) et une tresorerie (variable)


#ifndef ENTITE_H
#define ENTITE_H

#include <string>

//  forward-declaration de la classe.
// On ne peux pas include "objet.h", car ça cause un import circulaire
class Objet;

class Entite
{
    protected:
        std::string nom;
        float tresorerie;

    public:
        Entite(const std::string &, float);

        const std::string & get_nom() const;
        float get_tresorerie() const;

        void set_tresorerie(float);

        // Retire un objet de l'entité.
        // La méthode est virtuelle et doit être redéfinie par les classes filles
        // on fait ça car la gestion des objets est différente selon les classes filles:
        // Objet utilise un pointeur, Entreprise utilise un vecteur de pointeur
        // FIXME: on devrait utiliser des vecteurs partout
        //        et remonter les méthodes associés dans cette classe
        virtual void remove_objet(Objet*) = 0;

        virtual void gestion_des_stocks() = 0;
};

#endif // ENTITE_H
