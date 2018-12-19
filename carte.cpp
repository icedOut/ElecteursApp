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
#include <iostream>
#include <cstring>

void Carte::ajouter_noeud(long id, const PointST& p){
    noeuds[id] = Noeud();
    noeuds.at(id).point = p;
}

void Carte::ajouter_route(const std::string& nomroute, const std::list<long>& n){
    set<long> routes;
    for(list<long>::const_iterator it = n.begin(), kt = n.begin(), end = n.end(); it != end; ++it) {
        kt++;
        if(*it != *kt && kt != end) {
            auto v = this->noeuds.find(*it);
            v->second.voisins.insert(*kt);
            rues[*kt].insert(nomroute);
        }
    }
}

/////////////////////  PARTIE A /////////////////////////////
double Carte::calculerChemin(const std::string& nomelecteur, const std::string& nomorigine, const std::string& nomdestination,
                             std::list<std::string>& out_cheminnoeuds, std::list<std::string>& out_cheminroutes)
{
    double distanceTotal = 0;
    list<long> chemin = dijkstra(atol(nomorigine.c_str()+1), atol(nomdestination.c_str()+1), &distanceTotal);

    auto kt = chemin.begin();
    for(auto it = chemin.begin() ; it != chemin.end() ; ++it) {
        kt++;
        string s = "n"+to_string(*it);
        out_cheminnoeuds.push_back(s);
        if(kt != chemin.end())
            for(auto jt = rues.find(*it)->second.begin() ; jt != rues.find(*it)->second.end() ; ++jt ) {
                for(auto lt = rues.find(*kt)->second.begin() ; lt != rues.find(*kt)->second.end() ; ++lt ) {
                    if(*lt == *jt && out_cheminroutes.back() != *jt)
                        out_cheminroutes.push_back(*jt);
                }
            }
    }

    // Remplacez les lignes suivantes par votre code.

    return distanceTotal;

}


list<long> Carte::dijkstra(long src, long dest, double *distanceTotal) {
    cout << "------------DIJKSTRA-----------------\n";
    vector<double> distances (21,9999);
    vector<long> parent (21,0);
    distances[src] = 0;
    priority_queue<pair<long, long>, vector<pair<long, long>>, comparer> q;
    auto it = noeuds.find(src);
    q.push(make_pair(it->first, 0));
    //cout << "\nQ ready!\n";
    long max = 9999;

    while(!q.empty()) {
        long v = q.top().first;
        //cout << "\nv : " << v << "\n";
        if(distances[v] == max) {
            //cout << "\nProbleme\n";
            break;
        }
        double dist;
        //cout << "Top : " << q.top() << "\n";
        q.pop();
        for(auto w = noeuds.find(v)->second.voisins.begin() ; w != noeuds.find(v)->second.voisins.end() ; ++w)  {
            //cout << "\nVoisin : " << *jt << " | Parent : " << parent[v];
            dist = distances[v] + (distance(noeuds.find(v)->second.point,noeuds.find(*w)->second.point));
            if(dist < distances[*w]) {
                parent[*w] = v;
                distances[*w] = dist;
                //cout << "\nNouvel élément => " << *w <<" | " << "Le top : " << q.top().first << "\n";
                q.push(make_pair(*w, dist));

            }
        }

    }

    int e = 1;
    list<long> chemin;
    *distanceTotal = distances[dest];
    chemin.push_front(dest);
    while(parent[dest] != 0) {
        chemin.push_front(parent[dest]);
        dest = parent[dest];
        e++;
    }

    return chemin;
}

/////////////////////  PARTIE B /////////////////////////////
int Carte::calculerPancartes(int nbPancartes, std::vector<std::pair<std::string, std::string> >& segmentsroutes){
    // À compléter.
    for(int i=0;i<nbPancartes;i++)
        segmentsroutes[i] = std::make_pair<std::string, std::string>("n1", "n2");
    return 0;
}
