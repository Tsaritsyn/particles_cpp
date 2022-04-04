//
// Created by Mikhail Tsaritsyn on 07.02.2022.
//

#ifndef LIQUID_CONTINUOUSOBJECT_H
#define LIQUID_CONTINUOUSOBJECT_H

#include "Object.h"

class ContinuousObject: public AbstractObject {
protected:
    bool m_is_velocity_fixed, m_is_position_fixed, m_is_force_external;
    sf::Vector2f m_external_acceleration;

public:
    explicit ContinuousObject(
            const sf::Vector2f& pos,
            float mass = 1.f,
            const sf::Vector2f& v = sf::Vector2f(0.f, 0.f),
            const sf::Vector2f& acceleration = sf::Vector2f(0.f, 0.f),
            float charge = 1.f,
            bool is_position_fixed = false,
            bool is_velocity_fixed = false,
            bool is_force_external = false
    ): AbstractObject(pos, mass, v, acceleration, charge), m_is_position_fixed(is_position_fixed),
       m_is_velocity_fixed(is_velocity_fixed), m_is_force_external(is_force_external)
    {};

    virtual void setPositionFixed(bool flag) {m_is_position_fixed = flag;}

    virtual void setVelocityFixed(bool flag) {m_is_velocity_fixed = flag;}

    virtual void makeForceExternal(bool flag) {m_is_force_external = flag;}

    void move (float dt) override {if (!m_is_position_fixed) AbstractObject::move(dt);};

    void accelerate(float dt) override {if (!m_is_velocity_fixed) AbstractObject::accelerate(dt);};

    virtual void reset_kinematics() override;
};


class Line: public ContinuousObject {
protected:
    sf::Vector2f m_normal;

public:
    explicit Line(
            const sf::Vector2f& pos,
            const sf::Vector2f& normal,
            float mass = 1.f,
            const sf::Vector2f& v = sf::Vector2f(0.f, 0.f),
            const sf::Vector2f& acceleration = sf::Vector2f(0.f, 0.f),
            float charge = 1.f,
            bool is_position_fixed = false,
            bool is_velocity_fixed = false,
            bool is_force_external = false
    ): ContinuousObject(pos, mass, v, acceleration, charge, is_position_fixed, is_velocity_fixed, is_force_external),
    m_normal(normal)
    {};

    [[nodiscard]] float getDistanceTo(const sf::Vector2f& point) const override;

    [[nodiscard]] sf::Vector2f getDirectionTo(const sf::Vector2f& point) const override;

    void draw(sf::RenderWindow& window, float x_scale, float y_scale) override;
};


#endif //LIQUID_CONTINUOUSOBJECT_H
