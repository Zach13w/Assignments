#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Grid 
{
private:
    int m_rows;                         // Number of rows in the grid
    int m_cols;                         // Number of columns in the grid
    float m_cellSize;                   // Size of each cell
    float m_startX, m_startY;           // Starting position of the grid
    float m_cellSpacing;                // Spacing between cells
    std::vector<sf::RectangleShape> m_grid; // Vector to hold grid cells

public:
    // Constructor to initialize grid configuration
    Grid(int rows, int cols, float cellSize, float startX, float startY, float cellSpacing)
        : m_rows(rows), m_cols(cols), m_cellSize(cellSize), m_startX(startX), m_startY(startY), m_cellSpacing(cellSpacing) {

        // Create the grid cells
        for (int row = 0; row < m_rows; ++row) 
        {
            for (int col = 0; col < m_cols; ++col) 
            {
                sf::RectangleShape cell(sf::Vector2f(m_cellSize, m_cellSize));
                cell.setFillColor(sf::Color::White); // Default cell color
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(2.f);

                // Calculate cell position
                float x = m_startX + col * (m_cellSize + m_cellSpacing);
                float y = m_startY + row * (m_cellSize + m_cellSpacing);
                cell.setPosition(x, y);

                // Add the cell to the grid
                m_grid.push_back(cell);
            }
        }
    }

    // Method to render the grid
    void render(sf::RenderWindow& window) 
    {
        for (const auto& cell : m_grid) 
        {
            window.draw(cell);
        }
    }
};
