#include "TextBar.h"
#include <iostream>

int main() {

    //--creation--//
    sf::Texture textboxTexture;
    textboxTexture.loadFromFile("../text_field.png");
    sf::Font f;
    f.loadFromFile("../18341.ttf");
    TextBar txt_field_one(400,250, 242, 68,textboxTexture, f, "23", 12);
    TextBar txt_field_two(400,650, 242, 68,textboxTexture, f, "345", 12);
    //----------//

    sf::RenderWindow window(sf::VideoMode(800, 950), "Set properties");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //--event loop--//
            txt_field_one.event_holder(event);
            txt_field_two.event_holder(event);
            //--------------//

        }
        window.clear(sf::Color::White);

        //--displays it--//
        txt_field_one.displayBox(window);
        txt_field_two.displayBox(window);
        //---------------//

        window.display();
    }

    std::cout << txt_field_one.returnText() << std::endl;

    return 0;
}
