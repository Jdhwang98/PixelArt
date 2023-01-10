#include "Application.h"

void Application::run()
{
    /* The grid for snake or pixel art */
    sf::RectangleShape grid;
    std::vector<sf::RectangleShape> many_grids;

    grid.setSize({ 10,10 });

    float gap_size = 1.0f;
    const float x_pos = 10;
    const float y_pos = 10;
    sf::Vector2f first_position{ x_pos, y_pos };


    many_grids.reserve(1000);
    many_grids.insert(many_grids.begin(), 10005, grid);
    int limit = 115;
    int count = 0;


    for (int i = 0; i < many_grids.size(); i++)
    {
        many_grids[i].setPosition({ first_position.x, first_position.y });
        first_position.x += gap_size;
        first_position.x += x_pos;
        count++;
        if (count == limit)
        {
            limit += 115;
            first_position.x = x_pos;
            first_position.y += gap_size;
            first_position.y += y_pos;
        }
    }

    /* Reference to the window */
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pixel Art", sf::Style::Default);

    while (window.isOpen()) {

        sf::Event event{};

        sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
                /* Any event handlers go here */
            }
        }
    
        for (int i = 0; i < many_grids.size(); i++)
        {
            if (many_grids[i].getGlobalBounds().contains(mouse_position))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    many_grids[i].setFillColor(sf::Color::Red);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    many_grids[i].setFillColor(sf::Color::White);
                }
            }
        }
        /* for all the stuff you want to draw */
        window.clear();
        for (const auto &i : many_grids)
        {
            window.draw(i);
        }
        window.display();
    }
}

