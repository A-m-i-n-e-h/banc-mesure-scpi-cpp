#ifndef GBF_H
#define GBF_H

#include "Appareil.h"



class GBF : public Appareil
{
public:
    GBF(); //   

    void setForme(std::string forme);
    void setFrequence(double frequence);
    void setAmplitude(double amplitude);
    void activerSortie(bool actif);
    void activerSortie2(bool actif);
    void coupleFrequence(bool actif);
    void coupleAmplitude(bool actif);
    void alignerPhases();
};

#endif
