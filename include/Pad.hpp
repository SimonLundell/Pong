#ifndef PAD_H
#define PAD_H
#include "GameObject.hpp"

class Game;

class Pad : public GameObject {
    public:
        Pad(float x, float y, Game* game);

        void draw_default();

        unsigned int red;
        unsigned int green;
        unsigned int blue;
};
#endif