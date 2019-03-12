#include <iostream>
#include <SFML/Graphics.hpp>
#include"Player.h"
#include "World.h"
#include "UDP.h"

using namespace std;



int main()
{
    Player player;
    World world;
    UDP udp;
    world.Run(800, 600, "The game");
    udp.run(4300, 3);
    return 0;
}
