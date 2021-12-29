#include <GameObject.hpp>
#include <cmath>
#include <Math.hpp>
#include <Game.hpp>

GameObject::GameObject(float x, float y, Game* game) :
    x(x), 
    y(y), 
    dx(0), 
    dy(0), 
    width(0), 
    height(0), 
    speed(0), 
    game(game) {
}

float GameObject::get_x()
{
    return this->x;
}
float GameObject::get_y()
{
    return this->y;
}
float GameObject::get_width()
{
    return this->width;
}
float GameObject::get_height()
{
    return this->height;
}

void GameObject::push(float direction, float speed) {
    /*
    if(direction > 80.0f && direction <= 90.0f) 
    {
    direction = 75.0f;
    }
    if(direction > 90.0f && direction < 100.0f) 
    {
    direction = 105.0f;
    }
    if(direction > 260 && direction <= 270) 
    {
    direction = 255;
    }
    if(direction > 270 && direction < 280) 
    {
    direction = 285;
    }
    */
    float rad = to_radians(direction);
    this->dx += std::cos(rad) * speed;
    this->dy += std::sin(rad) * speed;
}