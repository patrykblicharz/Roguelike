#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Map : public sf::Drawable, public sf::Transformable
{
public:
    Map();
    ~Map();
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // MAP_H
