#ifndef _DELTOID_HPP_
#define _DELTOID_HPP_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

/* 
    wczesniej obliczona wartosc sqrt(3)/2
    która jest wysokością trojkąta równoramiennego
 */
#define HALF_SQRT_3 0.866

class RawDeltoid {
public:
    virtual ~RawDeltoid() = default;
    virtual std::vector<sf::Vector2f> calculate_vertices(const sf::Vector2f &pos, int s_len) = 0;
    // virtual sf::ConvexShape create_shape() = 0;
    // virtual sf::ConvexShape get_shape() = 0;
};

class Deltoid : public RawDeltoid {
public:
    Deltoid(const sf::Vector2f &pos, int s_len, sf::Color c): 
        side_len(s_len),
        colour(c),
        position(pos),
        verts(calculate_vertices(pos, s_len)),
        delt(create_shape()) {}

    std::vector<sf::Vector2f> calculate_vertices(const sf::Vector2f &pos, int s_len) override;
    sf::ConvexShape create_shape();

    sf::ConvexShape get_shape() { return delt; }
    
private:
    int side_len;
    sf::Color colour;
    sf::Vector2f position;
    std::vector<sf::Vector2f> verts;
    sf::ConvexShape delt;
};

class Cube : public RawDeltoid, public sf::Drawable {
public:
    using Cub = std::vector<sf::ConvexShape>;
    using CubePtr = std::unique_ptr<Cub>;
    Cube(const sf::Vector2f &pos, int s_len, const std::array<sf::Color, 3> &c) :
        side_len(s_len),
        colours(c),
        position(pos),
        verts(calculate_vertices(pos, s_len)),
        cub(create_shape()) {}

    std::vector<sf::Vector2f> calculate_vertices(const sf::Vector2f &pos, int s_len) override;
    Cub create_shape();

    Cub get_shape() { return cub; }

    std::vector<sf::Vector2f> return_verts() { return this->verts; }

    // CubePtr get_shape_ptr() const { return }


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int side_len;
    std::array<sf::Color, 3> colours;
    sf::Vector2f position;
    std::vector<sf::Vector2f> verts;
    Cub cub;
};

#endif //_DELTOID_HPP_