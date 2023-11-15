#ifndef POIGNEE_H
#define POIGNEE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Option.h"
#include "../elementCuisine/Meuble.h"

class Poignee : public Option
{
private:
    double prix;

public:
    Poignee(const std::string &description, double p) : Option(description), prix(p)
    {
        if (p < 0)
        {
            throw std::invalid_argument("Prix ne peut pas être négatif");
        }
    }

    double getMajoration(const Meuble &meuble) const override
    {
        return prix;
    }

    std::unique_ptr<Option> clone() const override
    {
        return std::make_unique<Poignee>(*this);
    }

    void affiche(std::ostream &s = std::cout, int indentation = 0) const override
    {
        s << std::string(indentation, '\t') << "Poignée:\n";
        Option::affiche(s, indentation + 1);
        s << std::string(indentation + 1, '\t') << "Prix: " << prix << "€\n";
    }
};

inline std::ostream &operator<<(std::ostream &s, const Poignee &op)
{
    op.affiche(s);
    return s;
}

#endif