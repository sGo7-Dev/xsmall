#pragma once

#include "app.h"
#include "time_info.h"

namespace xsmall {

class Application {
  private:
    bool should_close = false;

  public:
    Application();
    virtual ~Application();

    virtual void start() = 0;
    virtual void update(TimeInfo delta) = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;

    void run();
};

} // namespace xsmall