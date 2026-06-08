#include "GBF.h"
#include <string>

GBF::GBF()
{
}

void GBF::setForme(std::string forme)
{
    std::string commande = "SOURce1:FUNCtion " + forme;
    driver.envoyer(commande);
}

void GBF::setFrequence(double frequence)
{
    std::string commande = "SOURce1:FREQuency " + std::to_string(frequence);
    driver.envoyer(commande);
}

void GBF::setAmplitude(double amplitude)
{
    std::string commande = "SOURce1:VOLTage " + std::to_string(amplitude);
    driver.envoyer(commande);
}

void GBF::activerSortie(bool actif)
{
    if (actif)
        driver.envoyer("OUTPut1:STATe ON");
    else
        driver.envoyer("OUTPut1:STATe OFF");
}

void GBF::activerSortie2(bool actif)
{
    if (actif)
        driver.envoyer("OUTPut2:STATe ON");
    else
        driver.envoyer("OUTPut2:STATe OFF");
}

void GBF::coupleFrequence(bool actif)
{
    if (actif)
        driver.envoyer("SOURce1:FREQuency:CONCurrent ON");
    else
        driver.envoyer("SOURce1:FREQuency:CONCurrent OFF");
}

void GBF::coupleAmplitude(bool actif)
{
    if (actif)
        driver.envoyer("SOURce1:VOLTage:CONCurrent ON");
    else
        driver.envoyer("SOURce1:VOLTage:CONCurrent OFF");
}

void GBF::alignerPhases()
{
    driver.envoyer("SOURce1:PHASe:INITiate");
}
