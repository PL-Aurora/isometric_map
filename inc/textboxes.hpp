#ifndef _TEXTBOXES_HPP_
#define _TEXTBOXES_HPP_

#include <SFML/Graphics.hpp>
#include <string>

class FPS; //optional

class TextBoxes : public sf::Drawable {
public:
    TextBoxes() :
    font(std::move(set_font())) {
        set_boxes();
    };

    sf::Font set_font(const std::string &f = "misc/PcSeniorRegular-OEnd.ttf");
    void set_boxes(int pos_x = 10, int pos_y = 10);

    void set_mouse_caption(const sf::Vector2i &m_pos);
    void set_fps_caption(const float &time);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Font font;
    std::vector<sf::Text> t_boxes;
};


#endif // _TEXTBOXES_HPP_