#ifndef APPAREIL_H
#define APPAREIL_H

#include "VisaDriver.h"
#include<string>


class Appareil
{
protected:
    VisaDriver driver;
    std::string nom;

public:
    Appareil();

    bool connecter(std::string adresse);
    void deconnecter();
    std::string getNom();
};

#endif
