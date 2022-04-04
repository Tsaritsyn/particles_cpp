//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#include "common.hpp"

float norm(const sf::Vector2f& v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float dot(const sf::Vector2f& v1, const sf::Vector2f& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}