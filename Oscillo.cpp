#include "Oscillo.h"
#include <string>
#include <iostream>
#include <windows.h>    

Oscillo::Oscillo()
{
}

// ── Fonction utilitaire interne ──────────────────────────
// Protege stod contre les chaines vides ou invalides
// Retourne 0.0 si la reponse est vide ou non convertible
static double lireDouble(const std::string& reponse)
{
    if (reponse.empty())
    {
        std::cout << "Attention : reponse vide de l'oscilloscope" << std::endl;
        return 0.0;
    }

    try
    {
        double valeur = std::stod(reponse);

        // 9.9e37 = code erreur Tektronix (mesure impossible)
        if (valeur > 1e30)
        {
            std::cout << "Attention : mesure invalide (signal non stable ?)" << std::endl;
            return 0.0;
        }

        return valeur;
    }
    catch (...)
    {
        std::cout << "Attention : conversion impossible pour : "
            << reponse << std::endl;
        return 0.0;
    }
}

// ── Autoset ──────────────────────────────────────────────
void Oscillo::autoset()
{
    driver.envoyer("AUToset EXECute");
}

// ── Echelles ─────────────────────────────────────────────
void Oscillo::setEchelleVerticale(int canal, double echelle)
{
    std::string commande = "CH" + std::to_string(canal)
        + ":SCAle " + std::to_string(echelle);
    driver.envoyer(commande);
}
void Oscillo::setEchelleHorizontale(double echelle)
{
    std::string commande = "HORizontal:SCAle "
        + std::to_string(echelle);
    driver.envoyer(commande);
}

// ── Mesure Vpp ───────────────────────────────────────────
double Oscillo::mesurerVpp(int canal)
{
    driver.envoyer("SELect:CH" + std::to_string(canal) + " ON");
    Sleep(200);
    driver.envoyer("MEASUrement:IMMed:SOURce CH" + std::to_string(canal));
    Sleep(100);
    driver.envoyer("MEASUrement:IMMed:TYPe PK2pk");
    Sleep(100);
    driver.envoyer("MEASUrement:IMMed:VALue?");
    Sleep(500);

    std::string reponse = driver.lire();
    return lireDouble(reponse);  
}

// ── Mesure Frequence ─────────────────────────────────────
double Oscillo::mesurerFrequence(int canal)
{
    driver.envoyer("MEASUrement:IMMed:SOURce CH"
        + std::to_string(canal));
    driver.envoyer("MEASUrement:IMMed:TYPe FREQuency");
    driver.envoyer("MEASUrement:IMMed:VALue?");

    std::string reponse = driver.lire();
    return lireDouble(reponse);
}

// ── Mesure Moyenne ───────────────────────────────────────
double Oscillo::mesurerMoyenne(int canal)
{
    driver.envoyer("MEASUrement:IMMed:SOURce CH"
        + std::to_string(canal));
    driver.envoyer("MEASUrement:IMMed:TYPe MEAN");
    driver.envoyer("MEASUrement:IMMed:VALue?");

    std::string reponse = driver.lire();
    return lireDouble(reponse);
}

// ── Mesure Tension ───────────────────────────────────────
double Oscillo::mesurerTension(int canal)
{
    driver.envoyer("MEASUrement:IMMed:SOURce CH"
        + std::to_string(canal));
    driver.envoyer("MEASUrement:IMMed:TYPe AMPlitude");
    driver.envoyer("MEASUrement:IMMed:VALue?");

    std::string reponse = driver.lire();
    return lireDouble(reponse);
}