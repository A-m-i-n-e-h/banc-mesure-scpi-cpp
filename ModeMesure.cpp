#include "ModeMesure.h"
#include <iostream>
#include <windows.h>

ModeMesure::ModeMesure(Oscillo* osc)
{
    oscillo = osc;
    canal = 1;
    tension = 0.0;
    frequence = 0.0;
    periode = 0.0;
}

void ModeMesure::configurer()
{
    std::cout << "Canal (1 ou 2) : ";
    std::cin >> canal;
}

void ModeMesure::executer()
{
    Sleep(300);

    tension = oscillo->mesurerVpp(canal);
    frequence = oscillo->mesurerFrequence(canal);
    periode = 1.0 / frequence;

    std::cout << "Tension   = " << tension << " V" << std::endl;
    std::cout << "Frequence = " << frequence << " Hz" << std::endl;
    std::cout << "Periode   = " << periode << " s" << std::endl;
}

void ModeMesure::sauvegarderCSV(std::string nomFichier)
{
    // non implemente
}