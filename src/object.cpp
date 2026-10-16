#include "object.h"

Object::Object(const std::string &name) : name(name), components() {
}

template <typename T> void Object::add(std::shared_ptr<T> component) {
    components.push_back(component);
}

template <typename T> void Object::remove(std::shared_ptr<T> component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end()) {
        it = std::remove(components.begin(), components.end(), component);
        components.erase(it);
    }
}