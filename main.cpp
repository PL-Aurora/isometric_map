#include "deltoid.hpp"
#include "map.hpp"
#include "matrix.hpp"
#include "textboxes.hpp"

int main(int, char**) {

    sf::RenderWindow window(sf::VideoMode(800, 600), "isometric_view");
    std::array<sf::Color, 3> test_color_array = {sf::Color::Red, sf::Color::Blue, sf::Color::Green};
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(30, 30);

    sf::Font f;
    f.loadFromFile("PcSeniorRegular-OEnd.ttf");

    sf::Text mouse_pos;
    mouse_pos.setPosition(15, 15);
    mouse_pos.setCharacterSize(8);
    mouse_pos.setFont(f);
    
    mouse_pos.setFillColor(sf::Color::Red);

    Cube c1(std::move(sf::Vector2f(500, 300)), 20, test_color_array);
    

    sf::Vector2f t_pos_left = c1.return_verts().at(2);
    sf::Vector2f t_pos_right = c1.return_verts().at(4);
    
    Cube c2(std::move(t_pos_left), 20, test_color_array);
    Cube c3(std::move(t_pos_right), 20, test_color_array);

    while (window.isOpen())
    {
        sf::Vector2i m_pos = sf::Mouse::getPosition(window);

        mouse_pos.setString("Mouse pos -> x: " + std::to_string(m_pos.x) + ", y: " + std::to_string(m_pos.y));

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.draw(shape);
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        window.draw(mouse_pos);
        window.display();
    }

    /* Matrix m1(3,3);
    m1.print();

    std::cout << "\n\n";

    Matrix m2 = m1 * 10;
    m2.print();

    std::cout << "\n\n"; */

    return 0;
}
