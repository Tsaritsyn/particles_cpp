//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#ifndef LIQUID_COMMON_HPP
#define LIQUID_COMMON_HPP

#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

#define epsilon 1e-5

float norm(const sf::Vector2f& v);

float dot(const sf::Vector2f& v1, const sf::Vector2f& v2);

template <typename T>
T sign (T x) {
    return (x > 0) ? T(1) : T(-1);
}


#endif //LIQUID_COMMON_HPP
