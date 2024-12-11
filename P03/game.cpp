#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include "animation.hpp"
#include "grid.hpp"

using namespace std;

srand(time(0));

class dice
{
private:
    int roll

public:
    static int roll()
    {
        roll = rand() % 6 + 1;

        // play dice animation 

        // change Dice frame to appropriate frame

        return roll;
    }

}


int main() {

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Knucle Bones");

    // Create a Grid object
    Grid gameGrid(3, 3, 100.f, 200.f, 100.f, 10.f); // 3x3 grid with cell size 100, starting at (200, 100), 10px spacing

    // Create an Animation object
    Animation diceAnimation("frame", 6, sf::Vector2f(300.f, 200.f));

    // Main game loop
    while (window.isOpen()) 
    {
        sf::Event event;
    
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

                // Detect mouse clicks
        if (event.type == sf::Event::MouseButtonPressed) 
        {
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
                // Get mouse position relative to the window
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if the rectangle was clicked
                if (rectangle.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))



            }


        // Update the animation
        diceAnimation.update();

        // Render the window
        window.clear(sf::Color::White);
        diceAnimation.render(window);
        gameGrid.render(window); // Render the grid
        window.display();
        }
    }
    return 0;
}
