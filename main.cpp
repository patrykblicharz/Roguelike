#include <iostream>
#include <SFML/Graphics.hpp>
#include"Player.h"
#include "World.h"
#include "UDP.h"
#include <thread>

using namespace std;



int main()
{
    Player player;
    World world;
    UDP udp;
    std::thread t_udp(&UDP::run, &udp, 4300, 3);
    world.Run(800, 600, "The game");
    t_udp.join();
    return 0;
}
