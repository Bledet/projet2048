#include "mcts.h"

Mcts::Mcts()
{
    game = new Game();
    root = new Noeud();
}


double UCT(Noeud n, int visitTotal){ //variable global pour le nb de visit TOTAL tout noeud confondu

    double nodeWinScore = n.getNbWin();
    int nbVisit = n.getNbVisit();

    if(nbVisit == 0){
        return Integer.MAX_VALUE;
    }

    return ((double) nodeWinScore / (double) nbVisit) + 1.41 * Math.sqrt(Math.log(totalVisit) / (double) nbVisit);

} // ok tiers

/*
Noeud findBestNode(Noeud node){

    int parentVisit = node.getNbVisit();


}
*/

string mcts::press_touch(){

    std::string touche = "";



    return touche;
}

void playMcts(){

    bool win = false;
    bool lost = false;

    game.init();

    string enh = "";
    game.print();

    do{
        enh = press_touch(g);
        g.print();
        win = g.checkWin();
        lost = g.isLost();

        /* MCTS parameters */

        // root.nbvisit ++
        // nb visitTotal ++






        /* --------------- */



    }while(win == false || lost == false);

    if(win){
        cout<<"GG t'as gagné !"<<endl;
    }


}

Noeud Mcts::selectNode(Noeud rootNode){

    Noeud node = rootNode;

    while(node.getChildren().size() !=0){
        node = findBestNode(node);
    }

    return node;

}// ok



void Mcts::expansion(Noeud n){}


void Mcts::backPropagation(Noeud n){}


void Mcts::simulate(Noeud n){}
