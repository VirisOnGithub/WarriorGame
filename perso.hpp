#pragma once

//il faut éviter de mettre des using namespace dans les .hpp
#include <string>
#include <stdlib.h>
#include <iostream>
#include "arme.hpp"

class Personnage {

    private:
    std::string m_nom;
    int m_vie;
    int m_mana;
    Arme m_arme;

    public:

    //Personnage::Personnage(){
    //    vie = 100;
    //    mana = 100;
    //    nomArme = "Epée rouillee";
    //    degatsArme = 10;
    //}

    //plus rapide :
    Personnage() : m_nom("Bot"), m_vie(100), m_mana(100), m_arme("Epee rouillee", 10) {
        //Rien à mettre dans le corps du constructeur, tout a déjà été fait !
    }

    Personnage(std::string nom,std::string nomArme, int degatsArme) : m_nom(nom), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme) {}

    ~Personnage() {
        //Rien à mettre ici car aucun new dans le constructeur
        //Ceci est le destructeur par défaut que le compilateur aurait écrit à notre place
    }

    void recevoirDegats(int nbDegats){
        m_vie -= nbDegats;
        std::cout << m_nom << " a ete attaque ! Il perd " << nbDegats << " points de vie" << std::endl << std::endl;
        std::cout << m_nom << " a maintenant " << m_vie << " points de vie" << std::endl << std::endl;
        if (m_vie < 0)
            std::cout << m_nom << " est mort..." << std::endl;
            m_vie = 0;
    }

    void defendre(){
        m_vie += 10;
        if (m_vie > 100)
            m_vie = 100;
        std::cout << m_nom << " se defend et recupere 10 points de vie" << std::endl;
        sleep(1);
        std::cout << m_nom << " a maintenant " << m_vie << " points de vie" << std::endl << std::endl;
        m_mana += 10;
        if (m_mana > 100)
            m_mana = 100;
        std::cout << m_nom << " recupere 10 points de mana" << std::endl;
        sleep(1);
        std::cout << m_nom << " a maintenant " << m_mana << " points de mana" << std::endl << std::endl;
    }

    void attaquer(Personnage &cible){
        if (m_mana >= m_arme.getDegats()){
            cible.m_vie -= m_arme.getDegats();
            std::cout << m_nom << " attaque " << cible.m_nom << " avec son " << m_arme.getNom() << std::endl;
            sleep(1);
            std::cout << "Il inflige " << m_arme.getDegats() << " points de degats" << std::endl;
            sleep(1);
            if(cible.m_vie < 0){
                cible.m_vie = 0;
                std::cout << cible.m_nom << " est mort..." << std::endl;
                std::cout << m_nom << " a gagne !" << std::endl;
                sleep(1);
                exit(EXIT_SUCCESS);
            }
            std::cout << cible.getNom() << " a maintenant " << cible.getVie() << " points de vie" << std::endl;
            m_mana -= m_arme.getDegats();
            sleep(1);
            std::cout << m_nom << " a maintenant " << m_mana << " points de mana" << std::endl << std::endl;
        }
        else 
            std::cout << m_nom << " n'a pas assez de mana pour attaquer" << std::endl << std::endl;
            sleep(1);
    }

    void boirePotionDeVie(int quantitePotion){
        m_vie += quantitePotion;
        std::cout<< m_nom << " boit une potion de vie et recupere " << quantitePotion << " points de vie" << std::endl;
        if (m_vie > 100)
            m_vie = 100;
        sleep(1);
        std::cout << "Il a maintenant " << m_vie << " points de vie" << std::endl << std::endl;
    }

    void boirePotionDeMana(int quantiteMana){
        m_mana += quantiteMana;
        std::cout<< m_nom << " boit une potion de mana et recupere " << quantiteMana << " points de mana" << std::endl;
        if (m_mana > 100)
            m_mana = 100;
        sleep(1);
        std::cout << "Il a maintenant " << m_mana << " points de mana" << std::endl << std::endl;
    }

    bool estVivant() const{
        return m_vie > 0;
    }

    //méthode constante : ne modifie pas l'objet
    void afficherEtat() const {
        std::cout << "Nom : " << m_nom << std::endl;
        std::cout << "Vie : " << m_vie << std::endl;
        std::cout << "Mana : " << m_mana << std::endl;
        m_arme.afficher();
        std::cout << std::endl;
    }

    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme){
        m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
        std::cout << m_nom << " a trouve une nouvelle arme : " << nomNouvelleArme << std::endl;
        sleep(1);
        std::cout << "Les degats de son arme sont maintenant de " << degatsNouvelleArme << std::endl << std::endl;
    }

    Arme getArme() const {
        return m_arme;
    }

    std::string getNom() const {
        return m_nom;
    }
    int getVie() const {
        return m_vie;
    }
    int getMana() const {
        return m_mana;
    }
};