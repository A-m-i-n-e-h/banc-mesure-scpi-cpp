#include "VisaDriver.h"
#include <iostream>
#pragma comment(lib, "C:\\Program Files\\IVI Foundation\\VISA\\Win64\\Lib_x64\\msc\\visa64.lib")
#include<string>
#include<Windows.h>

// ───── Constructeur : ouvre le Resource Manager ─────
VisaDriver::VisaDriver()
{
    rm = 0;
    instrument = 0;
    viOpenDefaultRM(&rm);
}

// ───── Destructeur : ferme tout proprement ─────
VisaDriver::~VisaDriver()
{
    if (instrument != 0)
    {
        viClose(instrument);
        instrument = 0;
    }
    if (rm != 0)
    {
        viClose(rm);
        rm = 0;
    }
}

// ───── Connexion à un instrument via son adresse VISA ─────
bool VisaDriver::connecter(std::string adresse)
{
    if (rm == 0)
    {
        return false;
    }

    ViStatus status = viOpen(rm, (ViRsrc)adresse.c_str(), VI_NULL, VI_NULL, &instrument);
    if (status < VI_SUCCESS)
    {
        return false;
    }
    return true;
}

// ───── Déconnexion de l'instrument ─────
void VisaDriver::deconnecter()
{
    if (instrument != 0)
    {
        viClose(instrument);
        instrument = 0;
    }
}

// ───── Envoi d'une commande SCPI ─────
void VisaDriver::envoyer(std::string commande)
{
    if (instrument == 0)
    {
        return;
    }

    commande = commande + "\n";
    ViUInt32 nbEcrits;
    viWrite(instrument, (ViBuf)commande.c_str(), (ViUInt32)commande.size(), &nbEcrits);
}

// ───── Lecture de la réponse de l'instrument ─────
std::string VisaDriver::lire()
{
    if (instrument == 0) return "";

    Sleep(500);  // <- ajoute ca, attendre que l'oscillo reponde

    char buffer[256] = { 0 };
    ViUInt32 nbLus = 0;
    viRead(instrument, (ViBuf)buffer, 255, &nbLus);

    if (nbLus > 0 && nbLus < 256)
        buffer[nbLus] = '\0';

    return std::string(buffer);
}