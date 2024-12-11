#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Animation {
private:
    std::vector<sf::Texture> m_textures; // Textures for each frame
    sf::Sprite m_sprite;                 // Sprite to display the current frame
    sf::Clock m_clock;                   // Clock to track frame duration
    sf::Time m_frameDuration;            // Duration per frame
    size_t m_currentFrame;               // Index of the current frame
    sf::Vector2f m_position;             // Position to render the sprite


public:
    // Constructor to load textures
    Animation(const std::string& texturePrefix, int frameCount, const sf::Vector2f& position, int frameDurationMs = 200) 
        : m_position(position), m_frameDuration(sf::milliseconds(frameDurationMs)), m_currentFrame(0)
        {
        
        // Load textures for animation frames
        for (int i = 1; i <= frameCount; ++i) 
        {
            sf::Texture texture;

            if (!texture.loadFromFile(texturePrefix + std::to_string(i) + ".png")) 
            {
                std::cerr << "Error loading " << texturePrefix + std::to_string(i) + ".png" << std::endl;
                throw std::runtime_error("Error loading textures");
            }
            m_textures.push_back(texture);
        }

        // Initialize sprite with the first texture
        m_sprite.setTexture(m_textures[0]);
        m_sprite.setPosition(m_position);
    }

    // Update the animation based on time
    void update() {
        if (m_clock.getElapsedTime() >= m_frameDuration) 
        {
            m_clock.restart(); // Reset the clock
            m_currentFrame = (m_currentFrame + 1) % m_textures.size(); // Loop back to the first frame
            m_sprite.setTexture(m_textures[m_currentFrame]);
        }
    }

    // Render the animation on the window
    void render(sf::RenderWindow& window) 
    {
        window.draw(m_sprite);
    }
};

