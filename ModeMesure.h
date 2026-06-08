#ifndef MODEMESURE_H
#define MODEMESURE_H

#include "IMode.h"
#include "Oscillo.h"

class ModeMesure : public IMode
{
public:
    int    canal = 1;
    double tension = 0.0;
    double frequence = 0.0;
    double periode = 0.0;

    ModeMesure(Oscillo* osc);

    void configurer();
    void executer();
    void sauvegarderCSV(std::string nomFichier);

private:
    Oscillo* oscillo;
};

#endif