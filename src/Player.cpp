#include "Player.h"

Player::Player()
{
    //ctor
    if(!texture.loadFromFile("Sprites/Player.png"))
    {
        std::cout<<"Error! Texture not found!" <<std::endl;
    }
    else
    {
        sprite.setTexture(texture);
    }

}

Player::~Player()
{
    //dtor
}

void Player::RenderPlayer(sf::RenderWindow &window)
{
    sprite.setPosition(position);
    window.draw(sprite);
}

void Player::PlayerMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x--;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x++;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y--;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y++;
    }
}




