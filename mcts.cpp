#include "mcts.h"
#include <iostream>
#include <sys/time.h>
#include <math.h>


using namespace std;


Mcts::Mcts()
{
	
}

void Mcts::updateScore(Noeud *n){
		
	Noeud* courant = n;
	float s = n->getScore();
	cout<<"score de n = "<<n->getScore()<<endl;
	
	while(courant->parent != nullptr){
		cout<<courant->getScore()<<endl;
		courant->parent->setScore(s);
		courant->parent->incrIter();
		calculUct(courant);
		courant = courant->parent;
	}
	
}

Noeud* Mcts::selectBestChild(Noeud * n){
	float best = 0;
	int place = 0;
	
	for(int i = 0; i<n->getNbChild(); i++){
		if(n->children[i]->getUct() > best){
			best = n->children[i]->getUct();
			place = i;
		}
	}
	
	return n->getChildren()[place];
}

void Mcts::addAllChildren(Noeud *n){
	n->g.searchPossibleMoves();

	cout<<"nb coups possible : "<<n->g.getPossibleMoves().size();

	for(int i = 0; i<(int)n->g.getPossibleMoves().size(); i++){
		Noeud newN;
		n->addChild(newN);
	}
}

void Mcts::calculUct(Noeud *n){
	
	n->scoreUct = (n->scoreNoeud/n->getNbIt()) + sqrt(2) * (log(n->parent->getNbIt())/n->getNbIt());
		
}

void Mcts::playMcts(Noeud &n){
	
	Game newGame(n.g);
	newGame.print();
	n.g.print();
	
	
	n.incrIter();
	n.setGame(newGame);
	
	//n.g.print();
	
	cout<<n.getScore()<<endl;
	
	newGame.searchPossibleMoves();
	
	Noeud * courant = &n;
		
	for(int i=0; i<(int)newGame.getPossibleMoves().size(); i++){
		
		/* Creation du noeud */
	Noeud newNode;
        newNode.setDirection(newGame.getPossibleMoves()[i]);
        Noeud* node = new Noeud(newNode);
        node->addParent(courant);
        courant->addChild(newNode);
        node->setGame(courant->g);
        
        /* On joue une fois */
        node->g.press_touch_auto(newGame.getPossibleMoves()[i]);
		
        /* On copie la grille et fini la partie */
        Game copie(node->g);
        node->setScore(node->g.playAI(1));
        node->incrIter();
        node->setGame(copie);
        updateScore(node);
        
        addAllChildren(node);
        cout<<"nb child : " << node->getNbChild()<<endl;
        
        cout<<"score uct du noeud = "<<node->scoreUct<<endl;
        cout<<"score parent = "<<node->parent->getScore()<<endl;
        cout<<"nbit noeud = "<<node->getNbIt()<<endl;
        cout<<"nbit parent = "<<node->parent->getNbIt()<<endl;
	node->g.print();
	}
}

