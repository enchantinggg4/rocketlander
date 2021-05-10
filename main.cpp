#include <iostream>
#include <SFML/Graphics.hpp>

using std::vector;
using namespace std;

#include "rocket.h"




void text(sf::RenderWindow *window, string txt, sf::Font font, int pos){
    sf::Text text;

// set the string to display
    text.setString(txt);

// set the character size
    text.setCharacterSize(24); // in pixels, not points!

    text.setFont(font);

// set the color
    text.setFillColor(sf::Color::Red);

    text.setPosition(windowWidth - 400, 200 + pos * 50);

// inside the main loop, between window.clear() and window.display()
    window -> draw(text);
}

void draw(sf::RenderWindow *window, Rocket rocket, sf::Sprite image, sf::Font font) {
    float scaleY = rocket.height / 3000;
    float scaleX = rocket.width / 791.0f;


    // adjust so thrust is not a bottom of rocket
    image.setPosition(rocket.position.x * pixelDensity, (windowHeight - rocket.position.y - rocket.height + 75) * pixelDensity);
    image.setRotation(rocket.angle * 57.2958);


    image.setScale(
            scaleX,
            scaleY
    );
    window->draw(image);


    text(window, "Height " + to_string(rocket.position.y), font, 0);
    text(window, "V speed " + to_string(rocket.velocity.y), font, 1);
    text(window, "H speed " + to_string(rocket.velocity.x), font, 2);

}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth * pixelDensity, windowHeight * pixelDensity), "SFML works!", sf::Style::Resize);

    sf::Clock clock;

    window.setSize(sf::Vector2u(windowWidth * pixelDensity, windowHeight * pixelDensity));
    sf::Clock deltaClock;

    Rocket rocket{};

    rocket.height = 200;
    rocket.width = 40;
    rocket.angle = 0;
    rocket.acceleration = Vector{
            0,
            0.1
    };
    rocket.velocity = Vector{
            0,
            0
    };
    rocket.position = Vector{
            200, 0
    };


    sf::Texture texture;
    if (!texture.loadFromFile("../rocket.png")) {
        // error...
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Font font;
    if (!font.loadFromFile("../arial.ttf"))
    {
        // error...
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sf::Time elapsed1 = clock.getElapsedTime();
        float deltaTime = elapsed1.asSeconds();

        ProcessUnit pu = tick(rocket, deltaTime);

        if (pu.thrust > 1) {
            pu.thrust = 1;
        } else if (pu.thrust < 0) {
            pu.thrust = 0;
        }

        rocket.angle = pu.angle;

        // adjust so angle = 0 <=> vertical
        rocket.acceleration.x = cos(rocket.angle + 1.5708) * pu.thrust * rocket.maxThrust;
        rocket.acceleration.y = sin(rocket.angle + 1.5708) * pu.thrust * rocket.maxThrust;

        rocket.update(deltaTime);

        clock.restart();
        draw(&window, rocket, sprite, font);
        window.display();
    }
    return 0;
}
