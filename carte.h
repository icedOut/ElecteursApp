/*  INF3105 - Structures de données et algorithmes
    UQAM | Faculté des sciences | Département d'informatique
    TP3
    Fichier de départ carte.h © Éric Beaudry (beaudry.eric@uqam.ca).
    http://ericbeaudry.ca/INF3105/tp3/
*/
#if !defined(_CARTE__H_)
#define _CARTE__H_
#include <istream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "pointst.h"

using namespace std;

class Carte{
  public:
    void ajouter_noeud(long id, const PointST& c);
    void ajouter_route(const std::string& nom, const std::list<long>& noms);
    void getNoeuds();
    void dijkstra(long src);
    double calculerChemin(const std::string& nomelecteur, const std::string& origine, const std::string& destination,
                          std::list<std::string>& out_cheminnoeuds, std::list<std::string>& out_cheminroutes);

    int calculerPancartes(int nbPancartes, std::vector<std::pair<std::string, std::string> >& solution);


    private:
        struct Noeud{ // Un noeud est un sommet dans le graphe
            PointST point; // variable inutile pour le Lab12, mais utile pour le TP3.
            set<long> voisins; // ensemble des noeuds liés par un segment (tronçon) de route (arête).

        };
        map<long, Noeud> noeuds; // dictionnaire identifiant de noeud --> objet Noeud
        int nbNoeuds;
        long plusPetiteDistance(vector<long> distance, vector<long> parent, priority_queue<long> q);

};

// Déclaration opérateur (fonction) global
std::istream& operator >> (std::istream& is, Carte& carte);

#endif
