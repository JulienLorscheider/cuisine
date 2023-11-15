#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../elementCuisine/Meuble.h"

class Meuble;

class Option
{
protected:
    std::string description;

public:
    Option(const std::string &s) : description(s) {}
    virtual ~Option() {}
    virtual double getMajoration(const Meuble &meuble) const = 0;
    virtual void affiche(std::ostream &s = std::cout, int indentation = 0) const
    {
        s << std::string(indentation, '\t') << "Option: " << description << "\n";
    }

    std::string getDescription() const
    {
        return description;
    }

    virtual std::unique_ptr<Option> clone() const = 0;
};

inline std::ostream &operator<<(std::ostream &s, const Option &op)
{
    op.affiche(s);
    return s;
}

#endif