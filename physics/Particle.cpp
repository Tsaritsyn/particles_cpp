//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#include "Particle.h"

Particle::Particle(
        const sf::Vector2f& pos,
        float mass,
        const sf::Vector2f& v,
        const sf::Vector2f& acceleration,
        float charge
): AbstractObject(pos, mass, v, acceleration, charge), m_visualisation(3) {
    float visualisation_radius = m_visualisation.getRadius();
    m_visualisation.setFillColor(sf::Color::Red);
    m_visualisation.setOrigin(visualisation_radius, visualisation_radius);
//    m_visualisation.setPosition(m_pos.x, m_pos.y);
}

float Particle::getDistanceTo(const sf::Vector2f &point) const {
    return norm(m_pos - point);
}

sf::Vector2f Particle::getDirectionTo(const sf::Vector2f &point) const {
    auto temp = point - m_pos;
    return temp / norm(temp);
}

void Particle::draw(sf::RenderWindow &window, float x_scale, float y_scale) {
    m_visualisation.setPosition(m_pos.x * x_scale, m_pos.y * y_scale);
    window.draw(m_visualisation);
}
