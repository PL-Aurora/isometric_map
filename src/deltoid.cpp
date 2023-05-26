#include "../inc/deltoid.hpp"

/* 
    dla utworzenia deltoidu w rzucie izometrycznym korzystam
    z siatki 4 wierzcholkow, indeksowanie
    wierzcholkow zaczynam od zera
*/
std::vector<sf::Vector2f> Deltoid::calculate_vertices(const sf::Vector2f &pos, int s_len) {
    /* std::vector<sf::Vector2f> v;
    v.push_back(pos);
    v.push_back(sf::Vector2f(
        pos.x + s_len * HALF_SQRT_3,
        pos.y + s_len * 0.5
    ));
    v.push_back(sf::Vector2f(
        pos.x,
        pos.y + s_len
    ));
    v.push_back(sf::Vector2f(
        pos.x - s_len * HALF_SQRT_3,
        pos.y + s_len * 0.5
    )); */

    return std::vector<sf::Vector2f>(4) = {
        pos,
        std::move(sf::Vector2f(
            pos.x + s_len * HALF_SQRT_3, 
            pos.y + s_len * 0.5
        )),
        std::move(sf::Vector2f(
            pos.x,
            pos.y + s_len
        )),
        std::move(sf::Vector2f(
            pos.x - s_len * HALF_SQRT_3,
            pos.y + s_len * 0.5
        ))
    };
}

sf::ConvexShape Deltoid::create_shape() {
    auto d = sf::ConvexShape(4);
    int index = 0;
    for(const auto &i : verts) {
        d.setPoint(index, i);
        index++;
    }
    d.setFillColor(colour);
    return d;
}

/* 
    dla utworzenia sześcianu w rzucie izometrycznym utworze 
    3 deltoidy korzystajac z 7 wierzcholkow, indeksowanie
    wierzcholkow zaczynam od zera
*/
std::vector<sf::Vector2f> Cube::calculate_vertices(const sf::Vector2f &pos, int s_len) {
    return std::vector<sf::Vector2f>(7) = {
        pos,                                    //startowy, 'zerowy' wierzchołek
        std::move(sf::Vector2f(                 //pierwszy wierzchołek
            pos.x + s_len * HALF_SQRT_3, 
            pos.y + s_len * 0.5
        )),
        std::move(sf::Vector2f(                 //drugi wierzchołek
            pos.x + s_len * HALF_SQRT_3, 
            pos.y + s_len * 1.5
        )),
        std::move(sf::Vector2f(                 //trzeci wierzchołek
            pos.x, 
            pos.y + s_len * 2
        )),
        std::move(sf::Vector2f(                 //czwarty wierzchołek
            pos.x - s_len * HALF_SQRT_3, 
            pos.y + s_len * 1.5
        )),
        std::move(sf::Vector2f(                 //piąty wierzchołek
            pos.x - s_len * HALF_SQRT_3,
            pos.y + s_len * 0.5
        )),
        std::move(sf::Vector2f(                 //szósty wierzchołek
            pos.x,  
            pos.y + s_len
        ))
    };
}

std::vector<sf::ConvexShape> Cube::create_shape() {
    auto d = std::vector<sf::ConvexShape>(3);

    /* okreslenie kolejnosc */
    std::array<std::array<int, 4>, 3> deltoids_conf = {
        {{0, 1, 6, 5}, {1, 2, 3, 6}, {6, 3, 4, 5}}
    };

    for(int i = 0; i < 3; ++i) {
        d.at(i).setPointCount(4);
        for(int j = 0; j < 4; ++j) {
            d.at(i).setPoint(j, verts[deltoids_conf[i][j]]);
        }
        d.at(i).setFillColor(colours.at(i));
    }
        
    return d;
}

void Cube::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(const auto &c : cub)
        target.draw(c, states);
}
