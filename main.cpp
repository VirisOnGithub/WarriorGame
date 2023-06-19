#include <iostream>
#include <string>
#include <unistd.h>//pour sleep
#include "perso.hpp"
#include "fonctions.hpp"

using namespace std;

int main()
{
    string nom;
    Personnage goliath("Goliath","Epee aiguisee", 20);
    int tour = 1,choix = 0;

    cout << "Quel est votre nom ?" << endl;
    getline(cin, nom);
    Personnage joueur(nom,"Epee rouillee",10); //Création d'un objet de type Personnage : joueur
    joueur.afficherEtat();
    cout << "Appuyez sur entree pour commencer le combat" << endl;

    cin.ignore();

    cout << "C'est l'heure du combat !"<< endl;
    cout << "Vous etes face a Goliath !" << endl;
    while (joueur.estVivant() && goliath.estVivant())
    {
        cout << endl << "Tour " << tour << endl;
        cout << "Que voulez-vous faire ?" << endl;
        cout << "1. Attaquer" << endl;
        cout << "2. Se defendre" << endl;
        cout << "3. Ouvrir un coffre d'armes" << endl;
        cout << "4. Ouvrir un coffre de potions" << endl;
        cout << "5. Voir l'etat du combat" << endl << endl;
        cin >> choix;
        cout << endl;
        switch (choix)
        {
        case 1:
            joueur.attaquer(goliath);
            break;
        case 2:
            joueur.defendre();
            break;
        case 3:
            coffreArme(joueur);
            break;
        case 4:
            coffrePotion(joueur);
            break;
        case 5:
            joueur.afficherEtat();
            goliath.afficherEtat();
            sleep(1);
            break;
        }
        if (choix != 5 && goliath.estVivant()){
            if (goliath.getMana() > goliath.getArme().getDegats() && goliath.getVie() > 50){
                goliath.attaquer(joueur);
            }
            else{
                srand(time(NULL));
                int choixBot = rand() % 2;
                if (choixBot == 0){
                    coffrePotion(goliath);
                }
                else{
                    goliath.defendre();
                }
            }
            if (tour % 5 == 0){
                cout << "Goliath est enerve ! Il attaque deux fois !" << endl;
                sleep(1);
                goliath.attaquer(joueur);
            }
            if(tour % 7 == 0){
                cout << "Goliath trouve un coffre d'armes !" << endl;
                sleep(1);
                coffreArme(goliath);
            }
            tour++;
        }
        sleep(2);
    }
    if (joueur.estVivant()){
        cout << "Vous avez vaincu Goliath !" << endl;
    }
    else{
        cout << "Vous etes mort, GOliath vous a vaincu !" << endl;
    }
    

    return 0;
}