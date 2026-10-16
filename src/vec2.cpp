#include "math/vec2.h"

#include <cmath>

using namespace xsmall::math;

template <Decimal T> static constexpr T clamp_util(const T value, const T min, const T max) {
    return value < min ? min : (value > max ? max : value);
}

template <Decimal T> static constexpr T max_util(const T l, const T r) {
    return l > r ? l : r;
}

template <Decimal T> static constexpr T min_util(const T l, const T r) {
    return l < r ? l : r;
}

template <Decimal T> constexpr vec2<T> vec2<T>::abs() const {
    return vec2(std::abs(x), std::abs(y));
}

template <Decimal T> constexpr T vec2<T>::angle() const {
    return std::atan2(y, x);
}

template <Decimal T> constexpr T vec2<T>::cross(const vec2 &other) const {
    return x * other.y - y * other.x;
}

template <Decimal T> constexpr T vec2<T>::angle_to(const vec2 &to) const {
    return std::atan2(cross(to), cross(to));
}

template <Decimal T> constexpr T vec2<T>::angle_to_point(const vec2 &to) const {
    return (to - *this).angle();
}

template <Decimal T> constexpr T vec2<T>::aspect() const {
    return x / y;
}

template <Decimal T>
constexpr vec2<T> vec2<T>::clamp(const vec2<T> &min, const vec2<T> &max) const {
    return vec2<T>(clamp_util(x, min.x, max.x), clamp_util(y, min.y, max.y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::ceil() const {
    return vec2<T>(std::ceil(x), std::ceil(y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::floor() const {
    return vec2<T>(std::floor(x), std::floor(y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::round() const {
    return vec2<T>(std::round(x), std::round(y));
}

template <Decimal T> constexpr T vec2<T>::dot(const vec2<T> &other) const {
    return (x * other.x) + (y * other.y);
}

template <Decimal T> constexpr T vec2<T>::magnitude() const {
    return std::sqrt(x * x + y * y);
}

template <Decimal T> constexpr T vec2<T>::sqr_magnitude() const {
    return x * x + y * y;
}

template <Decimal T> constexpr vec2<T> vec2<T>::max(const vec2<T> &other) const {
    return vec2<T>(max_util(x, other.x), max_util(y, other.y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::min(const vec2<T> &other) const {
    return vec2<T>(min_util(x, other.x), min_util(y, other.y));
}

template <Decimal T> constexpr void vec2<T>::normalize() {
    if (!std::isfinite(x) && !std::isfinite(y)) {
        x = 0;
        y = 0;
        return;
    }

    T len = sqr_magnitude();
    if (len == 0) {
        x = 0;
        y = 0;
    } else {
        len = std::sqrt(len);
        x /= len;
        y /= len;
    }
}

template <Decimal T> constexpr vec2<T> vec2<T>::normalized() const {
    auto vec = *this;
    vec.normalize();
    vec2();
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator-(const vec2<T> &other) const {
    return vec2(x - other.x, y - other.y);
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator+(const vec2<T> &other) const {
    return vec2(x + other.x, y + other.y);
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator*(const vec2<T> &other) const {
    return vec2(x * other.x, y * other.y);
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator/(const vec2<T> &other) const {
    return vec2(x / other.x, y / other.y);
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator*(T scalar) const {
    return vec2(x * scalar, y * scalar);
}

template <Decimal T> constexpr vec2<T> vec2<T>::operator/(T scalar) const {
    return vec2(x / scalar, y / scalar);
}

// opeq shit

template <Decimal T> constexpr void vec2<T>::operator-=(const vec2<T> &other) {
    x -= other.x;
    y -= other.y;
}

template <Decimal T> constexpr void vec2<T>::operator+=(const vec2<T> &other) {
    x += other.x;
    y += other.y;
}

template <Decimal T> constexpr void vec2<T>::operator*=(const vec2<T> &other) {
    x *= other.x;
    y *= other.y;
}

template <Decimal T> constexpr void vec2<T>::operator/=(const vec2<T> &other) {
    x /= other.x;
    y /= other.y;
}

template <Decimal T> constexpr void vec2<T>::operator*=(T scalar) {
    x *= scalar;
    y *= scalar;
}

template <Decimal T> constexpr void vec2<T>::operator/=(T scalar) {
    x /= scalar;
    y /= scalar;
}