/*  INF3105 - Structures de données et algorithmes
    UQAM / Département d'informatique
    Hiver 2014 / TP3
    Eric Beaudry - beaudry.eric@uqam.ca - ericbeaudry.ca

    En principe, vous ne devriez pas modifier ce fichier.
    Si vous ne le modifiez pas, SVP ne l'imprimez pas!
*/
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include "carte.h"

using namespace std;

void tp3a(Carte& carte, istream& iselecteurs){
    // Tant qu'il existe des électeurs dans l'entrée
    while(iselecteurs && !iselecteurs.eof()){
        iselecteurs >> std::ws; // provoquera un échec si fin du fichier
        if(!iselecteurs) break; // échec lecture
        string personne, origine, destination;
        char pointvirgule=0;
        iselecteurs >> personne >> origine >> destination >> pointvirgule;
        if(!iselecteurs) break; // échec lecture
        assert(pointvirgule==';');

        std::list<string> cheminnoeuds, cheminnomroutes;

        personne=""; // pas utile pour la partie A
        double longueur = carte.calculerChemin(personne, origine, destination, cheminnoeuds, cheminnomroutes);
        // Affichage du chemins (liste de noeuds)
        for(std::list<string>::iterator iter=cheminnoeuds.begin();iter!=cheminnoeuds.end();++iter)
            cout << *iter << " ";
        cout << endl;
        // Affichage du chemins (liste de routes)
        for(std::list<string>::iterator iter=cheminnomroutes.begin();iter!=cheminnomroutes.end();++iter)
            cout << *iter << " ";
        cout << endl;
        // Affichage de la distance
        cout << round(longueur) << " m" << endl;
    }
}

int main(int argc, const char** argv)
{
    // Vérification d'un appel à tp3a avec la bonne syntaxe.
    if(argc<=1 || argc>3){
        cout << "Syntaxe: ./tp3a carte.txt [electeurs.txt]" << endl;
        return 1;
    }
    // Lecture de la carte.
    Carte carte;
    {
        ifstream fichiercarte(argv[1]);
        if(fichiercarte.fail()){
            cout << "Erreur ouverture du fichier : " << argv[1] << endl;
            return 1;
        }
        fichiercarte >> carte;
    }

    if(argc>2){
        // Lecture des électeurs depuis un fichier.
        ifstream is(argv[2]);
        if(is.fail()){
            cout << "Erreur ouverture du fichier : " << argv[2] << endl;
            return 1;
        }
        tp3a(carte, is);
    }else{
        // Lecture des électeurs depuis l'entrée standard.
        tp3a(carte, cin);
    }
    return 0;
}
