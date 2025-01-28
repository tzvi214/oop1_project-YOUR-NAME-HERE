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

   // // ����� ��������
   //// sf::Texture texture;
   // 
   ///* if (!texture.loadFromFile("temp.png")) {
   //     std::cerr << "Error loading texture!" << std::endl;
   //     return -1;
   // }*/

   // // ����� sprite
   // sf::Sprite sprite;
   //// sprite.setTexture(texture);
   // SfmlManager sfm;
   // sprite.setTexture(sfm.getTexture(ObjName::E_Temp));
   // sprite.setPosition(400, 300); // ����� ������

   // // ������� ��������
   // const int frameWidth = 50;  // ���� �� �����
   // const int frameHeight = 50; // ���� �� �����
   // int currentFrame = 100;       // ���� ������ ������
   // sf::Clock frameClock;       // ���� ��������

   // // ����� ������� ������
   // enum Direction { Up = 0, Left = 3, Down = 2, Right = 1 };
   // Direction direction = Down; // ����� ������

   // while (window.isOpen()) {
   //     sf::Event event;
   //     while (window.pollEvent(event)) {
   //         if (event.type == sf::Event::Closed) {
   //             window.close();
   //         }
   //     }

   //     // �����
   //     bool isMoving = false;
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
   //         sprite.move(0, -2);  // ����� �����
   //         direction = Up;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
   //         sprite.move(0, 2);   // ����� ����
   //         direction = Down;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
   //         sprite.move(-2, 0); // ����� �����
   //         direction = Left;
   //         isMoving = true;
   //     }
   //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
   //         sprite.move(2, 0);  // ����� �����
   //         direction = Right;
   //         isMoving = true;
   //     }

   //     // ����� �������
   //     if (isMoving) {
   //         if (frameClock.getElapsedTime().asMilliseconds() > 100) {
   //             currentFrame = (currentFrame + 1) % 3; // 3 ������� ��� ����
   //             frameClock.restart();
   //         }
   //     }
   //     else {
   //         currentFrame = 1; // ����� "�����" ����� �����
   //     }

   //     // ����� �-TextureRect ����� ������ ������� ������
   //     sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, direction * frameHeight, frameWidth, frameHeight));
   //     sprite.setScale(3.f, 3.f);
   //     // ����
   //     window.clear(sf::Color::Black); // ���� �� �����
   //     window.draw(sprite);           // ����� �� �������
   //     window.display();              // ���� �� ������
   // }

	GameController game;
	game.run();
	return EXIT_SUCCESS;
}