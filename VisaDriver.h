#ifndef VISADRIVER_H
#define VISADRIVER_H



#include <visa.h>
#include<string>

class VisaDriver
{
public:
    ViSession rm;
    ViSession instrument;

    VisaDriver();
    ~VisaDriver();

    bool connecter(std::string adresse);
    void deconnecter();
    void envoyer(std::string commande);
    std::string lire();
};

#endif
