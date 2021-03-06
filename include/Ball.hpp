#ifndef BALL_H
#define BALL_H
#include <GameObject.hpp>
#include <Draw.hpp>

class Game;

class Ball : public GameObject {
  public:
    Ball(float x, float y, Game* game);

    void update();
    void draw();
    void move(float dx, float dy, float speed);

  private:
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    float direction;
};

#endif
