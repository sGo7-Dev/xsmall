#include "app.h"
#include "math/vec2.h"

#include <spdlog/spdlog.h>

class MyApp : public xsmall::Application {
  public:
    MyApp() {
    }

    virtual ~MyApp() {
    }

    void start() override {
        xsmall::math::vec2 position = xsmall::math::vec2(0.0f, 0.0f);
        spdlog::info("initialized app");
    }

    void update(TimeInfo time) override {
    }

    void render() override {
    }

    void cleanup() override {
    }
};

int main() {
    spdlog::set_pattern("[%H:%M:%S / %^%l%$] %v");

    MyApp app;
    app.run();
    return 0;
}
