
# Système de Gestion de Meubles de Cuisine

## Description
Ce projet est un système de gestion de meubles de cuisine écrit en C++, permettant de créer des éléments de cuisine personnalisés avec des options variées telles que matériaux, poignées, et pieds. Il offre la possibilité de calculer le prix total des configurations de meubles et d'imprimer une facture détaillée.

## Installation et Configuration

### Prérequis
- Compilateur C++ supportant la norme C++17 (GCC, Clang, MSVC, etc.)
- CMake (optionnel) pour la compilation automatisée

### Comment installer
Pour installer ce projet, clonez le dépôt depuis GitHub ou téléchargez l'archive du code source, puis extrayez-le dans un dossier de votre choix.

## Utilisation

### Comment compiler
Pour compiler ce projet, vous pouvez utiliser la ligne de commande suivante si vous avez un Makefile ou un CMakeLists.txt configuré :

```sh
g++ -std=c++17 Main.cpp -o cuisineManager
```

Pour les utilisateurs de CMake, suivez ces étapes :

```sh
cmake .
make
```

### Comment exécuter
Après la compilation, vous pouvez exécuter le programme en utilisant :

```sh
./cuisineManager
```

## Fonctionnalités

### Classes principales
- `ElementCuisine`: Classe de base pour tous les éléments de cuisine.
- `Meuble`: Dérivé d'`ElementCuisine`, représente un meuble avec des dimensions et des options.
- `Ilot`: Regroupe plusieurs éléments de cuisine pour former un îlot.
- `Option`: Classe abstraite pour les options qui peuvent être ajoutées à un meuble.
- `Poignee`, `Materiau`, `Pieds`: Options concrètes qui peuvent être ajoutées aux meubles.

### Ajouter des options
Les options peuvent être ajoutées aux meubles en utilisant la méthode `ajouterOption()` de la classe `Meuble`, qui accepte un pointeur vers un objet `Option`.

## Contributions

Pour contribuer à ce projet, veuillez suivre ces étapes :

1. Fork le projet
2. Créez votre branche de fonctionnalités (`git checkout -b feature/AmazingFeature`)
3. Committez vos changements (`git commit -m 'Add some AmazingFeature'`)
4. Push sur la branche (`git push origin feature/AmazingFeature`)
5. Ouvrez une Pull Request

## Licence
Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus d'informations.

## Contact
LORSCHEIDER Julien - [julien.lorscheider@icloud.com](mailto:julien.lorscheider@icloud.com)
