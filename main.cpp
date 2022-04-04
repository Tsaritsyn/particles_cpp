#include <iostream>

#include "rendering.hpp"

int main() {
    App app({960 * 3 / 2, 540 * 3 / 2}, "Liquid");
    app.run();

    return 0;
}
