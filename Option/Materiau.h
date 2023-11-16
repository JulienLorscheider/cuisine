#ifndef MATERIAU_H
#define MATERIAU_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../elementCuisine/ElementCuisine.h"
#include "Option.h"

class Materiau : public Option
{
private:
    double pourcentage;

    void copier(const Materiau &orig)
    {
        pourcentage = orig.pourcentage;
    }

    ~Materiau()
    {
    }

public:
    Materiau(const std::string &description, double p) : Option(description), pourcentage(p)
    {
        if (p < 0)
        {
            throw std::invalid_argument("Pourcentage ne peut pas être négatif");
        }
    }

    Materiau(const Materiau &orig) : Option(orig)
    {
        copier(orig);
    }

    double getMajoration(const Meuble &meuble) const override
    {
        return meuble.getPrixDeBase() * pourcentage; // Utilise le prix de base du meuble
    }

    std::unique_ptr<Option> clone() const override
    {
        return std::make_unique<Materiau>(*this);
    }

    void affiche(std::ostream &s = std::cout, int indentation = 0) const override
    {
        s << std::string(indentation, '\t') << "Matériau:\n";
        Option::affiche(s, indentation + 1);
        s << std::string(indentation + 1, '\t') << "Pourcentage: " << pourcentage << "%\n";
    }
};

#endif