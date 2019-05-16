#ifndef GAME_H
#define GAME_H

#include <vector>


class Game
{
    public:
        Game();
        void print();
        void init();
        void top();
        void down();
        void left();
        void right();
        bool checkWin();
        bool isLost();
        void randomAI();
        void getPossibleMoves();




    protected:


    private:
        int tab[4][4];
        std::vector <char> possibleMoves;
        int nbPlayed = 0;

        bool possibleTop();
        void decalageTop();
        void additionTop();

        bool possibleDown();
        void decalageDown();
        void additionDown();

        bool possibleRight();
        void decalageRight();
        void additionRight();

        bool possibleLeft();
        void decalageLeft();
        void additionLeft();


        void alea();
};

#endif // GAME_H
