#ifndef MEUBLE_H
#define MEUBLE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "ElementCuisine.h"
#include "../option/Option.h"

class Meuble : public ElementCuisine
{
private:
    double largeur, hauteur, profondeur;
    std::vector<std::unique_ptr<Option>> options;

    void copier(const Meuble &orig)
    {
        largeur = orig.largeur;
        hauteur = orig.hauteur;
        profondeur = orig.profondeur;
        for (auto &opt : orig.options)
        {
            options.push_back(opt->clone());
        }
    }

public:
    Meuble(std::string d, double p, double l, double h, double prof)
        : ElementCuisine(d, p), largeur(l), hauteur(h), profondeur(prof)
    {
        if (l <= 0 || h <= 0 || prof <= 0)
        {
            throw std::invalid_argument("Dimensions ne peuvent pas être négatives ou zéro");
        }
    }

    Meuble(const Meuble &orig) : ElementCuisine(orig)
    {
        copier(orig);
    }

    double getLargeur() const
    {
        return largeur;
    }

    double getHauteur() const
    {
        return hauteur;
    }

    double getProfondeur() const
    {
        return profondeur;
    }

    const std::vector<std::unique_ptr<Option>> &getOptions() const
    {
        return options;
    }

    std::unique_ptr<ElementCuisine> clone() const override
    {
        return std::make_unique<Meuble>(*this);
    }

    const Meuble &operator=(const Meuble &op)
    {
        if (this != &op)
        {
            ElementCuisine::operator=(op);
            copier(op);
        }
        return *this;
    }

    void ajouterOption(std::unique_ptr<Option> option)
    {
        options.push_back(std::move(option));
    }

    double getPrixDeBase() const
    {
        return prix;
    }

    double getPrix() const override
    {
        double prixTotal = prix;
        for (const auto &option : options)
        {
            prixTotal += option->getMajoration(*this);
        }
        return prixTotal;
    }

    void affiche(std::ostream &s = std::cout, int indentation = 0, bool dernierElement = false) const override
    {
        s << std::string(indentation, '\t') << "Meuble: " << getDesignation() << "\n"
          << std::string(indentation + 1, '\t') << "Prix(" << getPrix() << "€)\n"
          << std::string(indentation + 1, '\t') << "Largeur(" << getLargeur() << ")\n"
          << std::string(indentation + 1, '\t') << "Hauteur(" << getHauteur() << ")\n"
          << std::string(indentation + 1, '\t') << "Profondeur(" << getProfondeur() << ")\n"
          << std::string(indentation + 1, '\t') << "Options:\n";
        for (const auto &option : options)
        {
            option->affiche(s, indentation + 2);
        }
        if (!dernierElement)
        {
            s << "\n";
        }
    }
};

inline std::ostream &operator<<(std::ostream &s, const Meuble &op)
{
    op.affiche(s);
    return s;
}

#endif