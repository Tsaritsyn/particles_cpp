//
// Created by Mikhail Tsaritsyn on 07.02.2022.
//

#include "ContinuousObject.h"

float Line::getDistanceTo(const sf::Vector2f &point) const {
    return dot(m_normal, point - m_pos);
}

sf::Vector2f Line::getDirectionTo(const sf::Vector2f &point) const {
    auto temp = dot(point - m_pos, m_normal);
    if (fabsf(temp) < epsilon) return {0.f, 0.f};
    else if (temp > 0) return m_normal;
    else return -m_normal;
}

void Line::draw(sf::RenderWindow &window, float x_scale, float y_scale) {
    sf::Vector2f start{m_pos.x * x_scale, m_pos.y * y_scale};
    sf::Vector2f end = m_pos + m_normal;
    end.x *= x_scale;
    end.y *= y_scale;
    sf::Vertex line[] {
        sf::Vertex(start),
        sf::Vertex(end)
    };
    window.draw(line, 2, sf::Lines);
}

void ContinuousObject::reset_kinematics() {
    if (m_is_force_external) m_acc = m_external_acceleration;
    else m_acc = sf::Vector2f(0.f, 0.f);
}
