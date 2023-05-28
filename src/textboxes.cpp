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

    for(auto &it : this->t_boxes) {
        it.setFont(this->font);
        it.setFillColor(sf::Color::Red);
        it.setCharacterSize(8);
    }

    this->t_boxes.at(0).setPosition(initial_pos);
    initial_pos = sf::Vector2f(initial_pos.x, initial_pos.y + font_size + 2);
    this->t_boxes.at(1).setPosition(initial_pos);

}

void TextBoxes::set_mouse_caption(const sf::Vector2i &m_pos) {
    this->t_boxes.at(0).setString("Mouse pos x: " + std::to_string(m_pos.x) + ", y: " + std::to_string(m_pos.y));
}

void TextBoxes::set_fps_caption(const float &time) {
    float elapsed_time = 1.f / time;
    this->t_boxes.at(1).setString("FPS = " + std::to_string(static_cast<int>(elapsed_time)));
}

void TextBoxes::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(const auto &box : t_boxes)
        target.draw(box, states);
}