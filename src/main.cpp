#include <iostream>

#include "app.h"

#include <spdlog/spdlog.h>

class MyApp : public Application {
  public:
    MyApp() {
    }

    virtual ~MyApp() {
    }

    void start() override {
        spdlog::info("Hello, World");
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
