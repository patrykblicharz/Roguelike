#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include"Player.h"
#include "Map.h"


class World
{
    public:
        World();
        ~World();
        void Run(int width,int height,std::string name);


    protected:

    private:
};

#endif // WORLD_H
