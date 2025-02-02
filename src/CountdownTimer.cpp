#include "CountdownTimer.h"

CountdownTimer::CountdownTimer(float duration)
    : m_duration(sf::seconds(duration)), m_remainingTime(m_duration) {
}

void CountdownTimer::addTime()
{
    m_remainingTime += sf::seconds(20);
    m_duration += sf::seconds(20);
}

void CountdownTimer::start(float duration) {
    m_duration = sf::seconds(duration);  
    m_remainingTime = m_duration;        
    m_clock.restart();                   
}

void CountdownTimer::update() {
    sf::Time elapsed = m_clock.getElapsedTime();
    m_remainingTime = m_duration - elapsed;

    if (m_remainingTime.asSeconds() < 0)
        m_remainingTime = sf::Time::Zero;
}

std::string CountdownTimer::getTimeString() const {
    int seconds = static_cast<int>(m_remainingTime.asSeconds());
    int minutes = seconds / 60;
    seconds %= 60;

    std::ostringstream ss;
    ss << minutes << ":" << (seconds < 10 ? "0" : "") << seconds;
    return ss.str();
}

bool CountdownTimer::isFinished() const {
    return m_remainingTime.asSeconds() <= 0;
}