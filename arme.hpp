#pragma once

#include <iostream>
#include <string>

class Arme
{
    private:
    std::string m_nom;
    int m_degats;

    public:
    Arme() : m_nom("Epee rouillee"), m_degats(10){}

    Arme(std::string nom, int degats) : m_nom(nom), m_degats(degats){}

    ~Arme(){}

    void changer(std::string nom, int degats){
        m_nom = nom;
        m_degats = degats;
    }

    void afficher() const{
        std::cout << "Arme : " << m_nom << " (degats : " << m_degats << ")" << std::endl;
    }
    int getDegats() const {return m_degats;}
    std::string getNom() const {return m_nom;}
};