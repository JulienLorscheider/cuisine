#ifndef ILOT_H
#define ILOT_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "ElementCuisine.h"

class Ilot : public ElementCuisine
{
private:
    std::vector<std::unique_ptr<ElementCuisine>> elements;

public:
    Ilot(std::string d) : ElementCuisine(d, 0) {}

    void ajouterElement(std::unique_ptr<ElementCuisine> element)
    {
        elements.push_back(std::move(element));
    }

    const std::vector<std::unique_ptr<ElementCuisine>> &getElements() const
    {
        return elements;
    }

    double getPrix() const override
    {
        double prixTotal = 0;
        for (const auto &element : elements)
        {
            prixTotal += element->getPrix();
        }
        return prixTotal * 0.9; // Applique une réduction de 10%
    }

    void affiche(std::ostream &s = std::cout, int indentation = 0, bool dernierElement = false) const override
    {
        s << std::string(indentation, '\t') << "Ilot: " << getDesignation() << "\n"
          << std::string(indentation + 1, '\t') << "Prix: " << getPrix() << "\n"
          << std::string(indentation + 1, '\t') << "Éléments :\n";
        for (size_t i = 0; i < elements.size(); ++i)
        {
            bool estDernierElement = (i == elements.size() - 1);
            elements[i]->affiche(s, indentation + 2, estDernierElement);
        }
    }
};

inline std::ostream &operator<<(std::ostream &s, const Ilot &op)
{
    op.affiche(s);
    return s;
}

#endif