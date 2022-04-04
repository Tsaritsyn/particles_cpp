//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#ifndef LIQUID_APP_H
#define LIQUID_APP_H


#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <random>

#include "common.hpp"
#include "physics.hpp"

class App {
    sf::RenderWindow m_window;
    float m_width = 96*2, m_height = 54*2;    // real size of the 2D world
    float m_xscale, m_yscale;
    unsigned m_particle_num;
    float m_r = 10.f;
    float m_dt = 0.01f;

    sf::Vector2f m_gravity{0.f, 0.1f};

    bool m_verbose = false;
    unsigned m_fps = 30;

    std::vector<std::unique_ptr<Particle>> m_particles;
    std::vector<std::unique_ptr<ContinuousObject>> m_objects;

public:

    App(const sf::Vector2u& window_size, const std::string& title);

    void run();

    void update();

    void refresh();
};


#endif //LIQUID_APP_H
