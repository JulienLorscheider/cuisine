#ifndef PIEDS_H
#define PIEDS_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Option.h"

class Pieds : public Option
{
private:
    double prixParPied;

    void copier(const Pieds &orig)
    {
        prixParPied = orig.prixParPied;
    }

    ~Pieds()
    {
    }

public:
    Pieds(const std::string &description, double p) : Option(description), prixParPied(p)
    {
        if (p < 0)
        {
            throw std::invalid_argument("Prix par pied ne peut pas être négatif");
        }
    }

    Pieds(const Pieds &orig) : Option(orig)
    {
        copier(orig);
    }

    double getMajoration(const Meuble &meuble) const override
    {
        int nombrePieds = (meuble.getLargeur() >= 80) ? 6 : 4;
        return nombrePieds * prixParPied;
    }

    std::unique_ptr<Option> clone() const override
    {
        return std::make_unique<Pieds>(*this);
    }

    void affiche(std::ostream &s = std::cout, int indentation = 0) const override
    {
        s << std::string(indentation, '\t') << "Pieds:\n";
        Option::affiche(s, indentation + 1);
        s << std::string(indentation + 1, '\t') << "Prix par pied: " << prixParPied << "€\n";
    }
};

#endif