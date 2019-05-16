#ifndef NOEUD_H
#define NOEUD_H

#include <vector>


#include <string>
#include <vector>

using namespace std;


class Noeud
{
    public:
        Noeud();
        Noeud(Noeud const& n);

        int getId();
        void setId(int i);
        void addChild(Noeud n);
        void addParent(Noeud *n);
        Noeud getParent();
        void setDirection(string s);
        int taille();
        int getNbChild();
        string getDirection();
        vector<Noeud> getChildren();

    protected:

    private:

        int id;
        Noeud* parent;
        string direction;
        vector <Noeud> children;


};

#endif // NOEUD_H
