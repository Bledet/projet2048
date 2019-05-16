#include "noeud.h"

Noeud::Noeud()
{
    // const
}


Noeud::Noeud(Noeud const& n)
{
    id = n.id;
    direction = n.direction;

}

vector<Noeud> Noeud::getChildren(){

    return children;
}

void Noeud::addChild(Noeud n){
    children.push_back(n);
}

void Noeud::setDirection(string s){
    direction = s;
}

int Noeud::getNbChild(){

    return children.size();
}


int Noeud::taille(){
    int compteur = 1;
    for(int i=0; i<(int)children.size(); i++){
        compteur += children[i].taille();
    }
    return compteur;
}

string Noeud::getDirection(){
    return direction;
}


Noeud Noeud::getParent(){
    return *parent;
}

int Noeud::getId(){
    return id;
}

void Noeud::setId(int i){
    id = i;
}


void Noeud::addParent(Noeud *n){
    parent = n;
}



