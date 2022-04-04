//
// Created by Mikhail Tsaritsyn on 28.01.2022.
//

#include "App.h"


App::App(const sf::Vector2u &window_size, const std::string &title):
        m_window(sf::VideoMode(window_size.x, window_size.y), title),
        m_xscale(window_size.x / m_width), m_yscale(window_size.y / m_height), m_particles{}
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> x_dis(0, m_width);
    std::uniform_real_distribution<float> y_dis(0, m_height);
    std::uniform_real_distribution<float> phi_dis(0, 2 * M_PIf32);

    for (unsigned i = 0; i < 500; i++) {
        float phi = phi_dis(gen);
        sf::Vector2f pos;
        bool inside_other;
//        try to place a new particle so that it does not hit any other
        do {
            pos = sf::Vector2f{x_dis(gen), y_dis(gen)};
            inside_other = false;
            for (const auto& particle: m_particles) {
//                std::cout << particle->getDistanceTo(pos) << '\n';
                if (particle->getDistanceTo(pos) < R_MIN) {
                    inside_other = true;
                    break;
                }
            }
        }
        while (inside_other);
        m_particles.push_back(std::make_unique<Particle>(
                pos, 1.f, sf::Vector2f{sinf(phi), cosf(phi)}
                ));
//        m_particles.emplace_back(pos, 1.f, sf::Vector2f{sinf(phi), cosf(phi)});
    }
    m_particle_num = m_particles.size();

//    m_particle_renders.resize(m_particle_num);
//    float r = 3;
//    for (unsigned i = 0; i < m_particle_num; i++) {
//        m_particle_renders[i].setRadius(r);
//        m_particle_renders[i].setOrigin(r, r);
//        m_particle_renders[i].setFillColor(sf::Color::Red);
//        m_particle_renders[i].scale({1.f, m_yscale / m_xscale});
//    }

//    put lines on the borders
    float pad = R_MIN * 2;
    m_objects.push_back(std::make_unique<Line>(
            sf::Vector2f(m_width / 2, -pad),
            sf::Vector2f(0.f, 1.f),
            1000,
            sf::Vector2f(0.f, 0.1f)
            ));
    m_objects[0]->makeForceExternal(true);
    m_objects.push_back(std::make_unique<Line>(
            sf::Vector2f(m_width / 2, m_height + pad),
            sf::Vector2f(0.f, -1.f),
            1000
    ));
    m_objects[1]->setPositionFixed(true);
    m_objects.push_back(std::make_unique<Line>(
            sf::Vector2f(-pad, m_height / 2),
            sf::Vector2f(1.f, 0.f),
            1000
    ));
    m_objects[2]->setPositionFixed(true);
    m_objects.push_back(std::make_unique<Line>(
            sf::Vector2f(m_width + pad, m_height / 2),
            sf::Vector2f(-1.f, 0.f),
            1000
    ));
    m_objects[3]->setPositionFixed(true);
//    std::cout << m_objects[0].get() << '\n';
//    std::cout << m_objects[1].get() << '\n';
//    std::cout << m_objects[2].get() << '\n';
//    std::cout << m_objects[3].get() << '\n';

//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(m_width + pad, -pad),
//            sf::Vector2f(-pad, -pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//            sf::Vector2f(0.f, 1.f)
//            ));
//    m_objects[0]->external_acceleration = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(m_width + pad, m_height + pad),
//            sf::Vector2f(m_width + pad, -pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[1]->fixed_position = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(-pad, -pad),
//            sf::Vector2f(-pad, m_height + pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[2]->fixed_position = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(-pad, m_height + pad),
//            sf::Vector2f(m_width + pad, m_height + pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[3]->fixed_position = true;
}


//App::App(const sf::Vector2u& window_size, const std::string &title)
//        : m_window(sf::VideoMode(window_size.x, window_size.y), title),
//        m_xscale(window_size.x / m_width), m_yscale(window_size.y / m_height)
//{
//
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<float> x_dis(0, m_width);
//    std::uniform_real_distribution<float> y_dis(0, m_height);
//    std::uniform_real_distribution<float> phi_dis(0, 2 * M_PIf32);
//
//    for (unsigned i = 0; i < 500; i++) {
//        float phi = phi_dis(gen);
//        sf::Vector2f pos;
//        bool inside_other;
////        try to place a new particle so that it does not hit any other
//        do {
//            pos = sf::Vector2f{x_dis(gen), y_dis(gen)};
//            inside_other = false;
//            for (unsigned j = 0; j < i; j++)
//                if (norm(pos - m_particles[j].pos) < m_rmin) {
//                    inside_other = true;
//                    break;
//                }
//        }
//        while (inside_other);
//        m_particles.emplace_back(pos, sf::Vector2f{sinf(phi), cosf(phi)});
//    }
//    m_particle_num = m_particles.size();
//
//    m_particle_renders.resize(m_particle_num);
//    float r = 3;
//    for (unsigned i = 0; i < m_particle_num; i++) {
//        m_particle_renders[i].setRadius(r);
//        m_particle_renders[i].setOrigin(r, r);
//        m_particle_renders[i].setFillColor(sf::Color::Red);
//        m_particle_renders[i].scale({1.f, m_yscale / m_xscale});
//    }
//
////    put lines on the borders
//    float pad = 2.f;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(m_width + pad, -pad),
//            sf::Vector2f(-pad, -pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//            sf::Vector2f(0.f, 1.f)
//            ));
//    m_objects[0]->external_acceleration = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(m_width + pad, m_height + pad),
//            sf::Vector2f(m_width + pad, -pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[1]->fixed_position = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(-pad, -pad),
//            sf::Vector2f(-pad, m_height + pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[2]->fixed_position = true;
//    m_objects.push_back(std::make_unique<Line>(
//            sf::Vector2f(-pad, m_height + pad),
//            sf::Vector2f(m_width + pad, m_height + pad),
//            sf::Vector2f(0.f, 0.f),
//            1000,
//    ));
//    m_objects[3]->fixed_position = true;
//}

void App::run() {
    long dt = 0;
    while (m_window.isOpen())
    {
        auto start = std::chrono::high_resolution_clock::now();
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                default:
                    break;
            }
        }

        update();
        auto end = std::chrono::high_resolution_clock::now();
        dt += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        if (dt * m_fps > 1000000000L) {
            dt -= 1000000000 / m_fps;
            refresh();
        }
    }
}

void App::refresh() {
    m_window.clear();
    for (auto& particle: m_particles) {
        particle->draw(m_window, m_xscale, m_yscale);

        if (m_verbose) {
            sf::CircleShape c_min(R_MIN * m_xscale);
            c_min.setOrigin(R_MIN * m_xscale, R_MIN * m_xscale);
            c_min.setPosition(particle->getPosition().x * m_xscale, particle->getPosition().y * m_yscale);
            c_min.scale({1.f, m_yscale / m_xscale});
            c_min.setFillColor(sf::Color::Transparent);
            c_min.setOutlineThickness(1.);
            c_min.setOutlineColor(sf::Color::Green);
            m_window.draw(c_min);
        }
    }

    for (const auto& object: m_objects)
        object->draw(m_window, m_xscale, m_yscale);

    m_window.display();
}

void App::update() {
    for (auto& object: m_objects) object->reset_kinematics();
    for (auto& particle: m_particles) particle->reset_kinematics();

    float max_velocity = 0.f;
    for (const auto& particle: m_particles) {
        float cur_velocity = norm(particle->getVelocity());
        if (cur_velocity > max_velocity)
            max_velocity = cur_velocity;
    }
    for (const auto& object: m_objects) {
        float cur_velocity = norm(object->getVelocity());
        if (cur_velocity > max_velocity)
            max_velocity = cur_velocity;
    }
    if (max_velocity > 1e-5) m_dt = R_MIN * 0.05f / max_velocity;
//    std::cout << max_velocity << ' ' << m_dt << '\n';

//    float max_acc = 0.f;
//    for (const auto& particle: m_particles) {
//        float cur_acc = norm(particle->getAcceleration());
//        if (cur_acc > max_acc)
//            max_acc = cur_acc;
//    }
//    for (const auto& object: m_objects) {
//        float cur_acc = norm(object->getAcceleration());
//        if (cur_acc > max_acc)
//            max_acc = cur_acc;
//    }
//    std::cout << max_acc << ' ' << m_dt << '\n';

//    updating forces
    for (auto& particle: m_particles) {
        for (auto &object: m_objects) {
            if (object->getDistanceTo(particle->getPosition()) < R_MAX) {
                auto interaction = object->getIntensityAt(particle->getPosition()) * particle->getCharge();
                std::cout << object->getDistanceTo(particle->getPosition()) << ' ' << interaction.x << ' ' << interaction.y << '\n';
                particle->influence(interaction);
                object->influence(-interaction);
            }
        }

        particle->influence(m_gravity * particle->getMass());
    }
    for (unsigned i = 0; i < m_particle_num - 1; i++)
        for (unsigned j = i + 1; j < m_particle_num; j++) {
            if (m_particles[i]->getDistanceTo(m_particles[j]->getPosition()) < R_MAX) {
                auto interaction =
                        m_particles[j]->getIntensityAt(m_particles[i]->getPosition()) * m_particles[i]->getCharge();
                m_particles[i]->influence(interaction);
                m_particles[j]->influence(-interaction);
            }
        }

//    updating velocities
    for (auto& particle: m_particles)
        particle->accelerate(m_dt);
    for (auto& object: m_objects)
        object->accelerate(m_dt);

//    updating positions
    for (auto& particle: m_particles)
        particle->move(m_dt);
    for (auto& object: m_objects)
        object->move(m_dt);
}



//void App::update() {
//    for (auto& object: m_objects) object->refresh();
//
//    float max_velocity = 0.f;
//    for (unsigned i = 0; i < m_particle_num; i++) {
//        float cur_velocity = norm(m_particles[i].v);
//        if (cur_velocity > max_velocity)
//            max_velocity = cur_velocity;
//    }
//    for (const auto& object: m_objects) {
//        float cur_velocity = norm(object->v);
//        if (cur_velocity > max_velocity)
//            max_velocity = cur_velocity;
//    }
//    if (max_velocity > 1e-5) m_dt = m_rmin * 0.05f / max_velocity;
//
////    updating all forces
//    for (unsigned i = 0; i < m_particle_num; i++)
//        m_particles[i].force = sf::Vector2f(0, 0);
//
//    for (unsigned i = 0; i < m_particle_num - 1; i++) {
//        for (unsigned j = i + 1; j < m_particle_num; j++) {
//            auto direction = m_particles[j].pos - m_particles[i].pos;
//            auto distance = norm(direction);
//
//            if (distance < m_rmax) {
//                direction /= distance;
//
//                sf::Vector2f interaction = direction * compute_force(distance);
//
//                m_particles[i].force -= interaction;
//                m_particles[j].force += interaction;
//            }
//        }
//
//        for (auto& object: m_objects) {
//            auto direction = object->getClosestPoint(m_particles[i].pos) - m_particles[i].pos;
//            auto distance = object->getDistance(m_particles[i].pos);
//
//            if (distance < m_rmax) {
//                direction /= distance;
//
//                sf::Vector2f interaction = direction * compute_force(distance);
//
//                m_particles[i].force -= interaction;
//                object->influence(interaction);
//            }
//        }
//
//        m_particles[i].force += m_gravity * m_particles[i].mass;
//    }
//
////    updating all velocities
//    for (unsigned i = 0; i < m_particle_num; i++) {
//        m_particles[i].v += m_dt * m_particles[i].force / m_particles[i].mass;
//
////        collisions with borders
////        float cooling = 0.5f;
////        float delta_t = 0.1f;
////        if (m_particles[i].pos.x < 0 && m_particles[i].v.x < 0) {
////            m_particles[i].v.x *= -1;
//////            m_particles[i].v *= powf(cooling, m_dt / delta_t);
////        }
////        if (m_particles[i].pos.y < 0 && m_particles[i].v.y < 0) {
////            m_particles[i].v.y *= -1;
//////            m_particles[i].v *= powf(cooling, m_dt / delta_t);
////        }
////        if (m_particles[i].pos.x > m_width && m_particles[i].v.x > 0) {
////            m_particles[i].v.x *= -1;
//////            m_particles[i].v *= powf(cooling, m_dt / delta_t);
////        }
////        if (m_particles[i].pos.y > m_height && m_particles[i].v.y > 0) {
////            m_particles[i].v.y *= -1;
//////            m_particles[i].v *= powf(cooling, m_dt / delta_t);
////        }
//    }
//
//    for (const auto& object: m_objects)
//        object->accelerate(m_dt);
//
//////    particle-object collisions
////    for (auto& particle: m_particles) {
////        for (auto& object: m_objects) {
////            if (object->getDistance(particle.pos) < m_rmin && object->isIntersection(particle.pos, particle.v)) {
//////                std::cout << particle.mass << ' ' << object->mass << '\n';
//////                std::cout << '(' << particle.v.x << ' ' << particle.v.y << "), (" << object->v.x << ' ' << object->v.y << ")\n";
////                auto tmp = particle.v;
////                particle.v = ((particle.mass - object->mass) * tmp + 2.f * object->mass * object->v) / (particle.mass + object->mass);
////                object->v = ((object->mass - particle.mass) * object->v + 2.f * particle.mass * tmp) / (particle.mass + object->mass);
//////                std::cout << '(' << particle.v.x << ' ' << particle.v.y << "), (" << object->v.x << ' ' << object->v.y << ")\n\n";
////            }
////        }
////    }
//
////    updating all positions
//    for (unsigned i = 0; i < m_particle_num; i++) {
//        m_particles[i].pos += m_particles[i].v * m_dt;
//    }
//
//    for (const auto& object: m_objects)
//        object->move(m_dt);
//}
//
//float App::compute_force(float r) const {
//    float rho = powf(m_rmin / r, 6);
////    corresponds to Lennard-Jones potential: 4E0 * (rho^12 - rh0^6), rho = R_MIN / r
//    return 24.f * m_E0 / r * (2.f * rho * rho - rho);
//}
