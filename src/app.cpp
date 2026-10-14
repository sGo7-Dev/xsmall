#include "app.h"
#include "time_info.h"

#include <chrono>

Application::Application() : should_close(false) {
}

Application::~Application() {
}

void Application::run() {
    start();

    float lastTime =
        std::chrono::duration<float>(std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    while (!should_close) {
        float currentTime = std::chrono::duration<float>(
                                std::chrono::high_resolution_clock::now().time_since_epoch())
                                .count();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        update({deltaTime, currentTime});
        render();
    }

    cleanup();
}
