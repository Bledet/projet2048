#ifndef MCTS_H
#define MCTS_H

#include "noeud.h"
#include "game.h"

#include <string>


class Mcts
{
    public:
        Mcts();

    protected:

    private:
        Game game;
        Noeud root;

        void selectNode(Noeud n);
        void expansion(Noeud n);
        void backPropagation(Noeud n);
        void simulate(Noeud n);
};

#endif // MCTS_H
