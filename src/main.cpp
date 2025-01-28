#include <iostream>
#include "Windows.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"
int main()
{
   // sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animation");
   // window.setFramerateLimit(60);

   // // טעינת הטקסטורה
   //// sf::Texture texture;
   // 
   ///* if (!texture.loadFromFile("temp.png")) {
   //     std::cerr << "Error loading texture!" << std::endl;
   //     return -1;
   // }*/

   // // הגדרת sprite
   // sf::Sprite sprite;
   //// sprite.setTexture(texture);
   // SfmlManager sfm;
   // sprite.setTexture(sfm.getTexture(ObjName::E_Temp));
   // sprite.setPosition(400, 300); // מיקום התחלתי

   // // פרמטרים לאנימציה
   // const int frameWidth = 50;  // רוחב כל פריים
   // const int frameHeight = 50; // גובה כל פריים
   // int currentFrame = 100;       // מספר הפריים הנוכחי
   // sf::Clock frameClock;       // שעון לאנימציה

   // // מיפוי כיוונים לשורות
   // enum Direction { Up = 0, Left = 3, Down = 2, Right = 1 };
   // Direction direction = Down; // כיוון התחלתי

   // while (window.isOpen()) {
   //     sf::Event event;
   //     while (window.pollEvent(event)) {
   //         if (event.type == sf::Event::Closed) {
   //             window.close();
   //         }
   //     }

   //     // תנועה
   //     bool isMoving = false;
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
   //         sprite.move(0, -2);  // תנועה למעלה
   //         direction = Up;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
   //         sprite.move(0, 2);   // תנועה למטה
   //         direction = Down;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
   //         sprite.move(-2, 0); // תנועה שמאלה
   //         direction = Left;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
   //         sprite.move(2, 0);  // תנועה ימינה
   //         direction = Right;
   //         isMoving = true;
   //     }

   //     // עדכון אנימציה
   //     if (isMoving) {
   //         if (frameClock.getElapsedTime().asMilliseconds() > 100) {
   //             currentFrame = (currentFrame + 1) % 3; // 3 פריימים בכל שורה
   //             frameClock.restart();
   //         }
   //     }
   //     else {
   //         currentFrame = 1; // פריים "עמידה" באמצע השורה
   //     }

   //     // הגדרת ה-TextureRect בהתאם לכיוון ולפריים הנוכחי
   //     sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, direction * frameHeight, frameWidth, frameHeight));
   //     sprite.setScale(3.f, 3.f);
   //     // ציור
   //     window.clear(sf::Color::Black); // מנקה את החלון
   //     window.draw(sprite);           // מצייר את הספרייט
   //     window.display();              // מציג את התוצאה
   // }

	GameController game;
	game.run();
	return EXIT_SUCCESS;
}