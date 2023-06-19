#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>//pour sleep
#include "perso.hpp"

void coffreArme(Personnage &joueur){
    srand(time(NULL)); 
    int alea = rand() % 6 + 1, degats;
    std::string nomArme;
    std::cout << joueur.getNom() << " a ouvert un coffre !" << std::endl;
    switch (alea)
    {
    case 1:
        std::cout << joueur.getNom() <<" a obtenu une epee rouillee" << std::endl;
        nomArme = "Epee rouillee";
        break;
    case 2:
        std::cout << joueur.getNom() << " a obtenu une epee aiguisee" << std::endl;
        nomArme = "Epee aiguisee";
        break;
    case 3:
        std::cout << joueur.getNom() << "a obtenu une epee en bois" << std::endl;
        nomArme = "Epee en bois";
        break;
    case 4:
        std::cout << joueur.getNom() << " a obtenu une epee en fer" << std::endl;
        nomArme = "Epee en fer";
        break;
    case 5:
        std::cout << joueur.getNom() << " a obtenu une epee en diamant" << std::endl;
        nomArme = "Epee en diamant";
        break;
    case 6:
        std::cout << joueur.getNom() << " a obtenu l'epee ultime !" << std::endl;
        nomArme = "Epee ultime";
        break;
    }
    degats = alea * 10;
    sleep(1);
    if (joueur.getArme().getDegats() < degats){
        joueur.changerArme(nomArme, degats);
        sleep(1);
        std::cout << joueur.getNom() << " a equipe l'arme : " << nomArme << std::endl;
    }
    else{
        std::cout << joueur.getNom() << " a deja une meilleure arme" << std::endl;
    }
    std::cout << std::endl;
}

void coffrePotion(Personnage &joueur){
    srand(time(NULL));
    int alea = rand() % 7 + 1;
    std::cout << joueur.getNom() << " a ouvert un coffre a potions !" << std::endl;
    sleep(1);
    switch (alea)
    {
    case 1:
        std::cout << joueur.getNom() << " a obtenu une potion inutilisable !" << std::endl;
        break;
    case 2:
        std::cout << joueur.getNom() << " a obtenu une potion de soin de 20 HP !" << std::endl;
        sleep(1);
        joueur.boirePotionDeVie(20);
        break;
    case 3:
        std::cout << joueur.getNom() << " a obtenu une potion de soin de 50 HP !" << std::endl;
        sleep(1);
        joueur.boirePotionDeVie(50);
        break;
    case 4:
        std::cout << joueur.getNom() << " a obtenu une potion de soin de 100 HP !" << std::endl;
        sleep(1);
        joueur.boirePotionDeVie(100);
        break;
    case 5:
        std::cout << joueur.getNom() << " a obtenu une potion de 20 unites de mana !" << std::endl;
        sleep(1);
        joueur.boirePotionDeMana(20);
        break;
    case 6:
        std::cout << joueur.getNom() << " a obtenu une potion de 50 unites de mana !" << std::endl;
        sleep(1);
        joueur.boirePotionDeMana(50);
        break;
    case 7:
        std::cout << joueur.getNom() << " a obtenu une potion de 100 unites de mana !" << std::endl;
        sleep(1);
        joueur.boirePotionDeMana(100);
        break;
    }
    std::cout << std::endl;
}

