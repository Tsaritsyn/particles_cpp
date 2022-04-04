//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#ifndef LIQUID_PARTICLE_H
#define LIQUID_PARTICLE_H

#include "Object.h"

#include "SFML/Graphics.hpp"

class Particle: public AbstractObject {
protected:
    sf::CircleShape m_visualisation;

public:
    explicit Particle(
            const sf::Vector2f& pos,
            float mass = 1.f,
            const sf::Vector2f& v = sf::Vector2f(0.f, 0.f),
            const sf::Vector2f& acceleration = sf::Vector2f(0.f, 0.f),
            float charge = 1.f
    );

    [[nodiscard]] float getDistanceTo(const sf::Vector2f& point) const override;

    [[nodiscard]] sf::Vector2f getDirectionTo(const sf::Vector2f& point) const override;

    void draw(sf::RenderWindow& window, float x_scale, float y_scale) override;

    sf::Vector2f getPosition() const {return m_pos;};
};


//struct Particle {
//    sf::Vector2f pos, v, force;
//    float mass = 1.f;
//
//    Particle(const sf::Vector2f& position, const sf::Vector2f& velocity): pos(position), v(velocity), force(0.f, 0.f) {};
//};


#endif //LIQUID_PARTICLE_H
