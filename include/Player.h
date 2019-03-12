#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>



class Player
{
public:
    Player();
    ~Player();
    void PlayerMovement();
    void RenderPlayer(sf::RenderWindow &window);


protected:

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool alive {false};
    int playerSpeed { 5 };
    sf::Vector2f position;

};

#endif // PLAYER_H
