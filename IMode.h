#ifndef IMODE_H
#define IMODE_H

#include<string>


class IMode
{
public:
    // Destructeur virtuel (obligatoire pour une classe abstraite)
    virtual ~IMode() {}

    // Méthodes que CHAQUE mode devra obligatoirement coder
    virtual void configurer() = 0;          // demande les paramètres à l'utilisateur
    virtual void executer() = 0;            // lance la mesure
    virtual void sauvegarderCSV(std::string nomFichier) = 0;  // sauvegarde résultats
};

#endif
