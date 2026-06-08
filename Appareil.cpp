#include "Appareil.h"
#include <iostream>
#include<string>

Appareil::Appareil()
{
    nom = "";
}

bool Appareil::connecter(std::string adresse)
{
    if (driver.connecter(adresse) == false)
    {
        return false;
    }

    driver.envoyer("*IDN?");
    nom = driver.lire();
    return true;
}

void Appareil::deconnecter()
{
    driver.deconnecter();
}

std::string Appareil::getNom()
{
    return nom;
}
