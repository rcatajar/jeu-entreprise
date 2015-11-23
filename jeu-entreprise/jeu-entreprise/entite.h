// Classe (abstraite) representant une Entité.
// Une entité est un acteur du marché (client ou entreprise)
// avec un nom (constant) et une tresorerie (variable)


#ifndef ENTITE_H
#define ENTITE_H

#include <string>

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
};

#endif // ENTITE_H
