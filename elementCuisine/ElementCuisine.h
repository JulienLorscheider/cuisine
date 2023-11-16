#ifndef ELEMENTCUISINE_H
#define ELEMENTCUISINE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class ElementCuisine
{
protected:
    std::string designation;
    double prix;
    double reduction;

    void copier(const ElementCuisine &orig)
    {
        designation = orig.designation;
        prix = orig.prix;
        reduction = orig.reduction;
    }

    virtual ~ElementCuisine()
    {
    }

public:
    ElementCuisine(std::string d, double p, double r) : designation(d), prix(p), reduction(r)
    {
        if (p < 0)
        {
            throw std::invalid_argument("Prix ne peut pas être négatif");
        }
        if (r < 0)
        {
            throw std::invalid_argument("Réduction ne peut pas être négative");
        }
        if (d.empty())
        {
            throw std::invalid_argument("La désignation est vide");
        }
    }

    ElementCuisine(const ElementCuisine &orig)
    {
        copier(orig);
    }

    virtual double getPrix() const
    {
        return prix - (prix * reduction);
    }

    void setPrix(double p)
    {
        if (p < 0)
        {
            throw std::invalid_argument("Prix ne peut pas être négatif");
        }
        prix = p;
    }

    void appliquerReduction(double r)
    {
        if (r <= 0)
        {
            throw std::invalid_argument("Réduction doit être supérieure à zéro");
        }
        reduction = r;
    }

    std::string getDesignation() const
    {
        return designation;
    }

    virtual std::unique_ptr<ElementCuisine> clone() const = 0;

    virtual void affiche(std::ostream &s = std::cout, int indentation = 0, bool dernierElement = false) const
    {
        s << std::string(indentation, '\t') << "Element de cuisine : " << getDesignation() << "\n"
          << std::string(indentation + 1, '\t') << "Prix : " << getPrix() << "€";
        if (!dernierElement)
        {
            s << "\n\n";
        }
    }
};

inline std::ostream &operator<<(std::ostream &s, const ElementCuisine &op)
{
    op.affiche(s);
    return s;
}
#endif