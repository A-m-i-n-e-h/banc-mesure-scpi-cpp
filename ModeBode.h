#ifndef MODEBODE_H
#define MODEBODE_H

#include "IMode.h"
#include "GBF.h"
#include "Oscillo.h"
#include <vector>

class ModeBode : public IMode
{
public:
    GBF* gbf;
    Oscillo* oscillo;

    double freqMin;
    double freqMax;
    int    nbPoints;
    double amplitude;

    // Resultats
    std::vector<double> frequences;
    std::vector<double> tensions;   // Vpp sortie (CH1)
    std::vector<double> gains;      // Gain en dB

    ModeBode(GBF* gbf_, Oscillo* oscillo_);

    void configurer();
    void executer();
    void sauvegarderCSV(std::string nomFichier);
};

#endif