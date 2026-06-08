#ifndef OSCILLO_H
#define OSCILLO_H

#include "Appareil.h"


class Oscillo : public Appareil
{
public:
    Oscillo();

    void autoset();
    void setEchelleVerticale(int canal, double echelle);
    void setEchelleHorizontale(double echelle);

    double mesurerVpp(int canal);
    double mesurerFrequence(int canal);
    double mesurerMoyenne(int canal);
    double mesurerTension(int canal);
};

#endif
