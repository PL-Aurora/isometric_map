#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "deltoid.hpp"

class WorldMap : public sf::Drawable {
    /* default constructor -> 800x600 */
    WorldMap() :
        world_size_x(800),
        world_size_y(600)
        {}

    WorldMap(uint16_t x, uint16_t y) :
        world_size_x(x),
        world_size_y(y)
        {}

    

private:

    // std::vector<Cube> create_map();

    uint16_t world_size_x;
    uint16_t world_size_y;
};

#endif //_MAP_HPP_