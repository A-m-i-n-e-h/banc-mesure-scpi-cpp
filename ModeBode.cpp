#include "ModeBode.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cmath>
#include <limits>

ModeBode::ModeBode(GBF* gbf_, Oscillo* oscillo_)
{
    gbf = gbf_;
    oscillo = oscillo_;
    freqMin = 100.0;
    freqMax = 1000.0;
    nbPoints = 10;
    amplitude = 1.0;
}

void ModeBode::configurer()
{
    std::cout << "\nConfiguration du diagramme de Bode" << std::endl;
    std::cout << "Frequence de depart (Hz) : "; std::cin >> freqMin;
    std::cout << "Frequence de fin (Hz) : ";    std::cin >> freqMax;
    std::cout << "Nombre de mesures : ";         std::cin >> nbPoints;
    std::cout << "Amplitude Ve (V) : ";          std::cin >> amplitude;
}

void ModeBode::executer()
{
    std::cout << "\nDebut du diagramme de Bode..." << std::endl;
    std::cout << "Ve = " << amplitude << " V (fixe)" << std::endl;

    frequences.clear();
    tensions.clear();
    gains.clear();

    gbf->setForme("SINusoid");
    gbf->setAmplitude(amplitude);
    gbf->activerSortie(true);

    double pas = (freqMax - freqMin) / (nbPoints - 1);

    for (int i = 0; i < nbPoints; i++)
    {
        double freq = freqMin + pas * i;

        // 1. Changer la frequence
        gbf->setFrequence(freq);
        Sleep(500);

        // 2. Demander a l'utilisateur de regler l'oscillo
        std::cout << "\n--- Point " << (i + 1) << "/" << nbPoints
            << " | Frequence = " << freq << " Hz ---" << std::endl;
        std::cout << "Reglez l'echelle de l'oscilloscope." << std::endl;
        std::cout << "Appuyez sur ENTREE quand c'est pret...";
        std::cin.ignore(1000, '\n');
        std::cin.get();

        // 3. Lire la mesure
        double vs = oscillo->mesurerVpp(1);

        double gainDB = 0.0;
        if (amplitude > 0.0 && vs > 0.0)
            gainDB = 20.0 * log10(vs / amplitude);

        frequences.push_back(freq);
        tensions.push_back(vs);
        gains.push_back(gainDB);

        std::cout << "Vs = " << vs << " V  |  Gain = " << gainDB << " dB" << std::endl;
    }

    gbf->activerSortie(false);
    std::cout << "\nBode termine." << std::endl;
}

void ModeBode::sauvegarderCSV(std::string nomFichier)
{
    std::ofstream file(nomFichier);
    file << "Frequence (Hz);Vs (V);Gain (dB)\n";

    for (int i = 0; i < (int)frequences.size(); i++)
    {
        file << frequences[i] << ";"
            << tensions[i] << ";"
            << gains[i] << "\n";
    }

    file.close();
    std::cout << "Resultats enregistres dans : " << nomFichier << std::endl;
}