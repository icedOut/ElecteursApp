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
#include <cstdlib>
#include <cmath>
#include "carte.h"

using namespace std;

void tp3b(Carte& carte, int nbPancartes, istream& iselecteurs){
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

        //double longueur =
        carte.calculerChemin(personne, origine, destination, cheminnoeuds, cheminnomroutes);
    }
    vector<pair<string, string> > segroutes(nbPancartes);
    int nbPersonnes = carte.calculerPancartes(nbPancartes, segroutes);
    for(int i=0;i<nbPancartes;i++)
        cout << segroutes[i].first << " -> " << segroutes[i].second << endl;
    cout << nbPersonnes << endl;
}

int main(int argc, const char** argv)
{
    // Vérification d'un appel à tp3b avec la bonne syntaxe.
    if(argc<=2 || argc>4){
        cout << "Syntaxe: ./tp3b carte.txt nbPersonnes [electeurs.txt]" << endl;
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

    int nbPancartes = atoi(argv[2]);

    if(argc>3){
        // Lecture des électeurs depuis un fichier.
        ifstream is(argv[3]);
        if(is.fail()){
            cout << "Erreur ouverture du fichier : " << argv[3] << endl;
            return 1;
        }
        tp3b(carte, nbPancartes, is);
    }else{
        // Lecture des électeurs depuis l'entrée standard.
        tp3b(carte, nbPancartes, cin);
    }
    return 0;
}
