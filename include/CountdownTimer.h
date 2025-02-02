#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

class CountdownTimer
{
public:
    CountdownTimer(float duration);
    void addTime();
    void start(float duration);
    void update();
    std::string getTimeString() const;
    bool isFinished() const;
    

private:
    sf::Clock m_clock;
    sf::Time m_duration;
    sf::Time m_remainingTime;
};