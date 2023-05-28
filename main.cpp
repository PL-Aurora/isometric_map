#include "inc/deltoid.hpp"
#include "inc/map.hpp"
#include "inc/matrix.hpp"
#include "inc/textboxes.hpp"

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "isometric_view");
    window.setFramerateLimit(60); //max 60 FPS
    sf::Clock Clock;
    std::array<sf::Color, 3> test_color_array = {sf::Color::Red, sf::Color::Blue, sf::Color::Green};
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(30, 30);

    /* inicjalizacja textboxow */
    TextBoxes t;

    Cube c1(std::move(sf::Vector2f(500, 300)), 20, test_color_array);
    

    sf::Vector2f t_pos_left = c1.return_verts().at(2);
    sf::Vector2f t_pos_right = c1.return_verts().at(4);
    
    Cube c2(std::move(t_pos_left), 20, test_color_array);
    Cube c3(std::move(t_pos_right), 20, test_color_array);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        t.set_mouse_caption(sf::Mouse::getPosition(window));
        t.set_fps_caption(Clock.getElapsedTime().asSeconds());
        Clock.restart();

        window.clear();
        
        window.draw(shape);
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        window.draw(t);

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