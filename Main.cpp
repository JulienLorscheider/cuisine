#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "./elementCuisine/ElementCuisine.h"
#include "./elementCuisine/Meuble.h"
#include "./elementCuisine/Ilot.h"
#include "./Option/Materiau.h"
#include "./Option/Poignee.h"
#include "./Option/Pieds.h"

int main()
{
    std::cout << "Facture:\n";
    // Étape 1 : Créez quatres objets Meuble pour les éléments « FA 120 »
    auto fa120_1 = std::make_unique<Meuble>("FA 120", 67, 120, 70, 56);
    auto fa120_2 = std::make_unique<Meuble>("FA 120", 67, 120, 70, 56);
    auto fa120_3 = std::make_unique<Meuble>("FA 120", 67, 120, 70, 56);
    auto fa120_4 = std::make_unique<Meuble>("FA 120", 67, 120, 70, 56);

    // Étape 2 : Ajoutez les options « Chene » et « Pieds inox » à ces meubles
    fa120_1->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa120_1->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    fa120_2->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa120_2->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    fa120_3->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa120_3->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    fa120_4->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa120_4->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    // Étape 3 : Affichez le prix total des meubles
    std::cout << "\n"
              << *fa120_1
              << *fa120_2
              << *fa120_3
              << *fa120_4;

    // Étape 4 : Créez un objet Meuble pour l'éléments « FD 40 » (angle)
    auto fd40_1 = std::make_unique<Meuble>("FD 40", 23, 40, 70, 112);

    // Étape 5 : Ajoutez les options « Chene » et « Pieds inox » à ce meuble
    fd40_1->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fd40_1->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    // Étape 6 : Affichez le prix total du meuble d'angle
    std::cout << *fd40_1;

    // Étape 7 : Créez deux objets Meuble pour les éléments « FA 80 »
    auto fa80_1 = std::make_unique<Meuble>("FA 80", 49, 80, 70, 56);
    auto fa80_2 = std::make_unique<Meuble>("FA 80", 49, 80, 70, 56);

    // Étape 8 : Ajoutez les options « Chene » et « Pieds inox » à ces meubles
    fa80_1->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa80_1->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    fa80_2->ajouterOption(std::make_unique<Materiau>("Chene", 0.1));
    fa80_2->ajouterOption(std::make_unique<Pieds>("Inox", 5));

    // Étape 9 : Créez un objet ElementCuisine pour le plan de travail « NUMERAR 160 »
    auto numerar160 = std::make_unique<ElementCuisine>("NUMERAR 160", 100);

    // Étape 10 : Créez un autre objet ElementCuisine pour la console « CAPITA 160 »
    auto capita160 = std::make_unique<ElementCuisine>("CAPITA 160", 50);

    // Étape 11 : Créez un objet Ilot pour BX 160
    Ilot bx160("BX 160");

    // Étape 12 : Ajoutez les éléments de cuisine et les meubles à l'îlot
    bx160.ajouterElement(std::move(fa80_1));
    bx160.ajouterElement(std::move(fa80_2));
    bx160.ajouterElement(std::move(numerar160));
    bx160.ajouterElement(std::move(capita160));

    // Étape 13 : Affichez le prix total de l'îlot
    std::cout << bx160 << std::endl;

    return 0;
}