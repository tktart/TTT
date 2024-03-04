#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <time.h>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1600, 900), "Main Menu");

    Font font;
    if (!font.loadFromFile("C:/Users/User/Desktop/gameprojtea/font/Sobiscuit.ttf")) {
        std::cerr << "Error loading font\n";
        return 1;
    }

    RectangleShape background;
    background.setSize(Vector2f(1600, 900));
    Texture Maintexture;
    Maintexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/welovetheking.jpg");
    background.setTexture(&Maintexture);

    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(1600, 900));
    Texture back_texture;
    back_texture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/welovetheking.jpg");
    Pbackground.setTexture(&back_texture);

    Text title("WELOVEKING", font, 100);
    title.setPosition(520.f, 200.f);

    Text playOption("Play", font, 50);
    playOption.setPosition(750.f, 400.f);

    Text exitOption("Exit", font, 50);
    exitOption.setPosition(750.f, 500.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                if (playOption.getGlobalBounds().contains(mousePos))
                {
                    cout << "Play option clicked!\n";

                    srand(static_cast<unsigned int>(time(nullptr)));
                    Game game;
                    game.run();

                    return 0;

                }
                else if (exitOption.getGlobalBounds().contains(mousePos))
                {
                    cout << "Exit option clicked!\n";
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(playOption);
        window.draw(exitOption);

        window.display();


    }

    return 0;
}
