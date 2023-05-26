#include <iostream>
#include "../inc/textboxes.hpp"


sf::Font TextBoxes::set_font(const std::string &font) {
    sf::Font f;
    if(!f.loadFromFile(font))
        std::cerr << "Blad w ladowaniu czcionki!" << std::endl;
    return f;
}

void TextBoxes::set_boxes(int pos_x, int pos_y) {
    auto initial_pos = sf::Vector2f(pos_x, pos_y);
    int font_size = 8;

    sf::Text mouse_pos;
    sf::Text fps;

    this->t_boxes.push_back(mouse_pos);
    this->t_boxes.push_back(fps);

    for(auto &it : this->t_boxes){
        it.setFont(this->font);
        it.setFillColor(sf::Color::Red);
        it.setCharacterSize(8);
        // it.setPosition(initial_pos);
    }

    // for()

    this->t_boxes.at(0).setPosition(initial_pos);
    initial_pos = sf::Vector2f(initial_pos.x + font_size + 2, initial_pos.y);
    this->t_boxes.at(1).setPosition(initial_pos);

}