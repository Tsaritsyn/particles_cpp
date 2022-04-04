//
// Created by Mikhail Tsaritsyn on 02.02.2022.
//

#ifndef LIQUID_OBJECT_H
#define LIQUID_OBJECT_H

#include <cmath>
#include <iostream>

#include "common.hpp"

#include "SFML/Graphics.hpp"

const float R_MIN = 2.f;
const float R_MAX = 5.21f * R_MIN;

class AbstractObject {
protected:
    float m_mass, m_charge;
    sf::Vector2f m_pos, m_v, m_acc;

public:
    explicit AbstractObject(
            const sf::Vector2f& pos,
            float mass = 1.f,
            const sf::Vector2f& v = sf::Vector2f(0.f, 0.f),
            const sf::Vector2f& acceleration = sf::Vector2f(0.f, 0.f),
            float charge = 1.f
            ) :
            m_mass(mass), m_charge(charge), m_pos(pos), m_v(v), m_acc(acceleration) {};

    [[nodiscard]] virtual float getDistanceTo(const sf::Vector2f& point) const = 0;

    [[nodiscard]] sf::Vector2f getIntensityAt(const sf::Vector2f& point) const {
        auto r = getDistanceTo(point);
        auto rho = powf(R_MIN / r, 6);
        auto direction = getDirectionTo(point);
//        std::cout << r << ' ' << rho << '\n';
        auto result = direction * 24.f * m_charge / r * (2.f * rho * rho - rho);
//        std::cout << norm(result) << '\n';
        return result;
    }

    [[nodiscard]] virtual sf::Vector2f getDirectionTo(const sf::Vector2f& point) const = 0;

    virtual void move (float dt) {m_pos += m_v * dt;};

    virtual void accelerate(float dt) {m_v += m_acc * dt;};

    virtual void influence(const sf::Vector2f& force) { m_acc += force / m_mass;};

    virtual void draw(sf::RenderWindow& window, float x_scale, float y_scale) = 0;

    [[nodiscard]] sf::Vector2f getVelocity() const {return m_v;}

    [[nodiscard]] sf::Vector2f getAcceleration() const {return m_acc;}

    [[nodiscard]] float getCharge() const {return m_charge;}

    [[nodiscard]] float getMass() const {return m_mass;}

    virtual void reset_kinematics() {m_acc = sf::Vector2f(0.f, 0.f);};
};


//struct AbstractObject {
//
//    float mass, charge;
//    sf::Vector2f v, acc{0.f, 0.f};
//
//    bool fixed_position = false, fixed_velocity = false, external_acceleration = false;
//
//    AbstractObject(float mass_, const sf::Vector2f& velocity, const sf::Vector2f acceleration):
//            mass(mass_), v(velocity), acc(acceleration), acc0(acceleration)
//    {};
//
//    virtual void move(float dt) = 0;
//
//    virtual void accelerate(float dt) = 0;
//
//    virtual void influence(const sf::Vector2f& force) = 0;
//
//    virtual void draw(sf::RenderWindow& window, float xscale, float yscale) const = 0;
//
//    [[nodiscard]] virtual float getDistance(const sf::Vector2f& point) const = 0;
//
//    [[nodiscard]] virtual bool isIntersection(const sf::Vector2f& p, const sf::Vector2f& vector) const = 0;
//
//    [[nodiscard]] virtual sf::Vector2f getClosestPoint(const sf::Vector2f& p) const = 0;
//
//    virtual void refresh() = 0;
//
//    [[nodiscard]] virtual sf::Vector2f getIntensity(const sf::Vector2f& point) const = 0;
//
//protected:
//    sf::Vector2f acc0;
//};
//
//struct Line: public AbstractObject {
////    sf::Vector2f p1, p2;
//    sf::Vector2f p0;
//    sf::Vector2f m_normal;
//    float m_c0;
//
//    Line(const sf::Vector2f& start,
//         const sf::Vector2f& end,
//         const sf::Vector2f& velocity = sf::Vector2f(0.f, 0.f),
//         float mass = 1,
//         const sf::Vector2f& acceleration = sf::Vector2f(0.f, 0.f));
//
//    void move(float dt) override;
//
//    void accelerate(float dt) override;
//
//    void influence(const sf::Vector2f& force) override;
//
//    void draw(sf::RenderWindow& window, float xscale, float yscale) const override;
//
//    [[nodiscard]] float getDistance(const sf::Vector2f& point) const override;
//
//    [[nodiscard]] bool isIntersection(const sf::Vector2f& p, const sf::Vector2f& vector) const override;
//
//    [[nodiscard]] sf::Vector2f getClosestPoint(const sf::Vector2f& p) const override;
//
//    void refresh() override;
//
//    [[nodiscard]] sf::Vector2f getIntensity(const sf::Vector2f& point) const override;
//};


#endif //LIQUID_OBJECT_H
