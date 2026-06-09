# banc-mesure-scpi-cpp
Banc de mesure automatisé C++ - Pilotage instruments Tektronix via VISA/SCPI

# Banc de mesure automatisé — VISA/SCPI — C++

Développé dans le cadre d'un stage de BUT2 GEII au sein du département
Systèmes Embarqués et Électronique de l'**ISTP Saint-Etienne** (avril – juin 2026).

## Description

Logiciel de pilotage automatique d'instruments de mesure Tektronix pour
les travaux pratiques d'électronique analogique. Le programme pilote un
**générateur de fonctions AFG1022** et un **oscilloscope MSO2012B** via
le protocole **VISA/SCPI**, et permet de tracer des diagrammes de Bode
sur les filtres Sallen-Key du second ordre de la carte de TP EA de l'ISTP.

## Fonctionnalités

- **ModeBode** : balayage fréquentiel automatique, lecture Vpp à chaque point, export CSV
- **ModeMesure** : mesure ponctuelle de tension crête-à-crête, fréquence et période
- Architecture orientée objet en C++ (7 classes)
- Gestion des erreurs VISA et du code d'erreur Tektronix `9.9e37`

## Architecture

```
VisaDriver       → communication VISA bas niveau (viWrite / viRead)
Appareil         → classe de base commune aux instruments
├── GBF          → pilotage générateur de fonctions AFG1022
└── Oscillo      → mesures oscilloscope MSO2012B
IMode            → interface abstraite des modes de mesure
├── ModeBode     → balayage fréquentiel + export CSV
└── ModeMesure   → mesure ponctuelle
```

## Dépendances

- **NI-VISA** 64-bit — [National Instruments](https://www.ni.com/fr-fr/support/downloads/drivers/download.ni-visa.html)
- **Compilateur MSVC** (Visual Studio 2022) — MinGW est incompatible avec `visa64.lib`
- Windows 10/11

## Compilation

1. Ouvrir le projet dans **Visual Studio 2022**
2. Vérifier que le chemin vers `visa64.lib` est correct dans les propriétés du projet :
   `C:\Program Files\IVI Foundation\VISA\Win64\Lib_x64\msc\visa64.lib`
3. Vérifier le chemin vers les headers VISA :
   `C:\Program Files\IVI Foundation\VISA\Win64\Include`
4. Compiler en **Release x64**

## Utilisation

Brancher les instruments en USB, identifier leurs adresses VISA via **NI-MAX**,
puis renseigner les adresses dans `main.cpp` avant compilation.

```
1. Mesure simple
2. Diagramme de Bode
```

Le résultat du diagramme de Bode est exporté dans un fichier `bode.csv`
(colonnes : fréquence Hz, tension Vs V, gain dB).


Vous pouvez ainsi tracé un diagramme de bode avec matplotlib et pyhton avec les données en format csv ( ajout du programme de Bode ultérieurement ) 


## Auteur

Amine Hamdoun — BUT2 GEII, IUT Jean Monnet Saint-Etienne et stagiaire à l'ISTP Dpt SEE
