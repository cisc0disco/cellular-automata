#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>


const int cellSize = 5;
using namespace std;

const int xWindow = 800 / cellSize;
const int yWindow = 600 / cellSize;

#define SIZE xWindows * yWindow

sf::RenderWindow window(sf::VideoMode(xWindow * cellSize, yWindow * cellSize), "SFML works!");

int main()
{
    window.setFramerateLimit(999);

    unsigned seed = time(0);
    srand(seed);
    int virusCreated = false;

    int randomX = rand() % window.getSize().x / cellSize;
    int randomY = rand() % window.getSize().y / cellSize;


    //sf::RectangleShape aCells[xWindow + 1][yWindow + 1];

    //sf::RectangleShape* aCellsX = new sf::RectangleShape[xWindow + 1];
    //sf::RectangleShape* aCellsY = new sf::RectangleShape[yWindow + 1];

    sf::RectangleShape** aCells = new sf::RectangleShape* [xWindow + 1];
    for (int i = 0; i < xWindow + 1; ++i)
        aCells[i] = new sf::RectangleShape[yWindow + 1];

    for (int i = 0; i <= window.getSize().x / cellSize - 2; i++)
    {
        for (int j = 0; j <= window.getSize().y / cellSize - 2; j++)
        {
            sf::RectangleShape shape;
            shape.setSize(sf::Vector2f(cellSize, cellSize));

            if (i == 0 && j == 0)
                shape.setPosition(sf::Vector2f(i, j));
            else
                shape.setPosition(sf::Vector2f(i * cellSize, j * cellSize));

            shape.setFillColor(sf::Color::Transparent);
            
            
            if (virusCreated == false && randomX == i && randomY == j)
            { 

                shape.setFillColor(sf::Color::Red);

                virusCreated = true;
            }

            //cout << i << " - " << j << endl;

            aCells[i][j] = shape;
        } 
    } 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();

        //window.draw(sprite);

        if (virusCreated == true) 
        {
            for (int i = 0 + 1; i <= xWindow - 1; i++)
                for (int j = 0 + 1; j <= yWindow - 1; j++)
                {


                    window.draw(aCells[i][j]);

                    if (aCells[i][j].getFillColor() == sf::Color::Red)
                    {

                        //aCells[i][j].setSize(sf::Vector2f(0.0f, 0.0f));

                        int nIndex = rand() % 30;

                        switch (nIndex) {
                        case 1:
                            if (i - 1 < xWindow * 20 && 0 > j - 1 < xWindow * 20 && i > 0)
                                aCells[i - 1][j - 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 2:
                            if (i < xWindow * 20 && 0 >j - 1 < xWindow * 20 && i > 0)
                                aCells[i][j - 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 3:
                            if (i + 1 < xWindow * 20 && 0 > j - 1 < xWindow * 20 && i > 0)
                                aCells[i + 1][j - 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 4:
                            if (i + 1 < xWindow * 20 && 0 > j < xWindow * 20 && i > 0)
                                aCells[i + 1][j].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);

                        case 5:
                            if (i + 1 < xWindow * 20 && 0 > j + 1 < xWindow * 20 && i > 0)
                                aCells[i + 1][j + 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 6:
                            if (i < xWindow * 20 && 0 >j + 1 < xWindow * 20 && i > 0)
                                aCells[i][j + 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 7:
                            if (i - 1 < xWindow * 20 && 0 > j - +1 < xWindow * 20 && i > 0)
                                aCells[i - 1][j + 1].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        case 8:
                            if (i - 1 < xWindow * 20 && 0 > j < xWindow * 20 && i > 0)
                                aCells[i - 1][j].setFillColor(sf::Color::Red);

                            window.draw(aCells[i][j]);
                        }
                    }
                }
        }
        window.display();
    }
    return 0;
}