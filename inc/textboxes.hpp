#ifndef _TEXTBOXES_HPP_
#define _TEXTBOXES_HPP_

#include <SFML/Graphics.hpp>

class FPS;

class TextBoxes : public sf::Drawable {
public:
    TextBoxes() :
    font(std::move(set_font())) {
        set_boxes();
    };

    sf::Font set_font(const std::string &f = "PcSeniorRegular-OEnd.ttf");
    void set_boxes(int pos_x = 10, int pos_y = 10);

    friend class FPS;

private:
    sf::Font font;
    std::vector<sf::Text> t_boxes;
    /* sf::Text mouse_pos_text_box;
    sf::Text fps_text_box; */
};

class FPS {

};

#endif // _TEXTBOXES_HPP_