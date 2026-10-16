#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "component.h"

class Object {
    std::string name;
    std::vector<std::shared_ptr<Component>> components;

  public:
    Object(const std::string &name);

    template <typename T> void add(std::shared_ptr<T> component);
    template <typename T> void remove(std::shared_ptr<T> component);
};