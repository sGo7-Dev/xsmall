#pragma once

/*
    If you have any thoughts about this seeing much like
    Godot's Vector2 implementation, then you're right!
    I take inspiration on that.
    I love Godot.

    - Goulax16
*/

#include <concepts>

namespace xsmall {
namespace math {

template <typename T>
concept Decimal = std::same_as<T, float> || std::same_as<T, double>;

template <Decimal T> struct vec2 {
    T x = T{0};
    T y = T{0};

    constexpr vec2() = default;
    constexpr vec2(T x, T y) : x(x), y(y) {
    }

    constexpr vec2<T> abs() const;
    constexpr T angle() const;
    constexpr T cross(const vec2 &other) const;
    constexpr T angle_to(const vec2 &to) const;
    constexpr T angle_to_point(const vec2 &to) const;
    constexpr T aspect() const;
    constexpr vec2<T> ceil() const;
    constexpr vec2<T> floor() const;
    constexpr vec2<T> round() const;
    constexpr vec2<T> clamp(const vec2 &min, const vec2 &max) const;
    constexpr T dot(const vec2 &other) const;
    constexpr T magnitude() const;
    constexpr T sqr_magnitude() const;
    constexpr vec2<T> max(const vec2<T> &other) const;
    constexpr vec2<T> min(const vec2<T> &other) const;
    constexpr vec2<T> normalized() const;
    constexpr void normalize();

    constexpr vec2<T> operator-(const vec2<T> &) const;
    constexpr vec2<T> operator+(const vec2<T> &) const;

    constexpr vec2<T> operator*(const vec2<T> &) const;
    constexpr vec2<T> operator*(T scalar) const;

    constexpr vec2<T> operator/(const vec2<T> &) const;
    constexpr vec2<T> operator/(T scalar) const;

    constexpr void operator+=(const vec2<T> &);
    constexpr void operator-=(const vec2<T> &);

    constexpr void operator*=(const vec2<T> &);
    constexpr void operator/=(const vec2<T> &);

    constexpr void operator*=(T scalar);
    constexpr void operator/=(T scalar);
};

} // namespace math
} // namespace xsmall