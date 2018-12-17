/*  INF3105 - Structures de données et algorithmes
    UQAM | Faculté des sciences | Département d'informatique
    TP3
    Fichier de départ carte.cpp © Éric Beaudry (beaudry.eric@uqam.ca).
    http://ericbeaudry.ca/INF3105/tp3/

    Vos noms + codes permanents :
    Vous pouvez modifier ce fichier autant que vous le voulez.
*/
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <sstream>
#include "carte.h"

void Carte::ajouter_noeud(long id, const PointST& p){
    noeuds[id] = Noeud();
    noeuds.at(id).point = p;
}

void Carte::ajouter_route(const std::string& nomroute, const std::list<long>& n){
    auto kt = n.begin();
    for(list<long>::const_iterator it = n.begin(), kt = n.begin(), end = n.end(); it != end; ++it) {
        kt++;
        if(*it != *kt && kt != end) {
            auto v = this->noeuds.find(*it);
            v->second.voisins.insert(*kt);
        }
    }
    cout << "\n";
}

void Carte::getNoeuds() {
    int i = 0;
    for(auto it = noeuds.begin() ; it != noeuds.end() ; ++it) {
        cout << it->first << " : " << it->second.point << " : ";
        for(auto jt = it->second.voisins.begin() ; jt != it->second.voisins.end() ; ++jt)  {
            cout << *jt << "|";
        }
        cout << "\n";
        i++;
    }
    cout <<"i : " << i << "\n";
}

/////////////////////  PARTIE A /////////////////////////////
double Carte::calculerChemin(const std::string& nomelecteur, const std::string& nomorigine, const std::string& nomdestination,
                             std::list<std::string>& out_cheminnoeuds, std::list<std::string>& out_cheminroutes)
{
    //cout << "Nom du lecteur : " << nomelecteur << " | Nom d'origine : " << nomorigine  << " | Nom destination : " << nomdestination;
    //cout << "\n Chemin : ";
    for(auto jt = out_cheminnoeuds.begin() ; jt != out_cheminnoeuds.end() ; ++jt)  {
        //cout << *jt << "|";
    }
    //cout << "\n";
    dijkstra(atol(nomorigine.c_str()+1));
    /***  Conseils pour l'implémentation de Dijkstra *************************************************
    - Utilisez un std::priority_queue.
    - À noter qu'un priority_queue trie les éléments en ordre décroissant alors qu'il faut visiter les noeuds en ordre croissant de mindistance.
    - À chaque itération (bouche while):
     -- Affichez temporairement le nom du noeud visité avec sa distance (affichage à enlever avant la remise).
     -- Le premier devrait être le noeud d'origine avec 0.
     -- L'ordre des mindistance des noeuds visités doit être croissant (et strictement croissant si chemins unique).
     -- Pour chaque noeud connecté au noeud visité (deuxième boucle), affichez son nom et sa distance.
    - Vérifiez le bon fonctionnement avec une petite carte (ex: uqam-carte.txt).
    - Une fois la boucle while terminée, le chemin peut être construit en partant du noeud de destination jusqu'à origine en utilisant le parent.
    - Si aucun chemin n'existe, retournez +infini (dans les tests fournis, il existe toujours un chemin optimal unique).
    **************************************************************************************************/

    // Remplacez les lignes suivantes par votre code.
    out_cheminnoeuds.push_back(nomorigine);
    out_cheminnoeuds.push_back(nomdestination);
    out_cheminroutes.push_back("(vol_d'oiseau)");

    return 0;

}

long Carte::plusPetiteDistance(vector<long> distances, vector<long> parent, priority_queue<long> q) {
    priority_queue<long> p(q);
    long v = 9999;
    cout << "\nQueue : ";
    while(!p.empty()) {

        if(distances[p.top()] < v) {
            v = p.top();
        }
        cout << p.top() << " | ";
        p.pop();
    }
    cout << "\n";
    return v;
}

void Carte::dijkstra(long src) {
    cout << "------------DIJKSTRA-----------------\n";
    vector<long> distances (21,9999);
    vector<long> parent (21,0);

    distances[src] = 0;
    priority_queue<long> q;
    auto it = noeuds.find(src);
    q.push(it->first);
    cout << "\nQ ready!\n";
    int comp = 0;
    long max = 9999;
    while(!q.empty() && comp < 30) {
        long v = plusPetiteDistance(distances, parent,q);
        cout << "\nv : " << v << "\n";
        if(v == max) {
            cout << "\nProbleme\n";
            break;
        }
        int dist;
        q.pop();
        for(auto jt = noeuds.find(v)->second.voisins.begin() ; jt != noeuds.find(v)->second.voisins.end() ; jt++)  {
            cout << "\nJT : " << *jt << " | Parent : " << parent[v];
            dist = distances[v] + (distance(noeuds.find(v)->second.point,noeuds.find(*jt)->second.point));
            if(dist < distances[*jt]) {
                parent[*jt] = v;
                distances[*jt] = dist;
                cout << "\nNouvel élément => " << *jt <<" | " << "Le top : " << q.top() << "\n";
            }
            int c = *jt;
            cout << "\nON POUSSE : " << c << "\n";
            if(*jt != parent[v])
                q.push(c);
        }

        comp++;

    }


    cout << "\nCompteur : "<< comp << "\nDistance : ";
    for(int i = 1 ; i < distances.size() ; i++) {
        cout << distances[i] << " | ";
    }
    cout << "\nParent : ";
    for(int i = 1 ; i < parent.size() ; i++) {
        cout << parent[i] << " | ";
    }
    cout << "\n--------------------------------------\n";
}

/////////////////////  PARTIE B /////////////////////////////
int Carte::calculerPancartes(int nbPancartes, std::vector<std::pair<std::string, std::string> >& segmentsroutes){
    // À compléter.
    for(int i=0;i<nbPancartes;i++)
        segmentsroutes[i] = std::make_pair<std::string, std::string>("n1", "n2");
    return 0;
}

