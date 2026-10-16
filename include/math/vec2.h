#pragma once

/*
/-------------------------------------------------------------------\
|    Note                                                           |
|                                                                   |
|    If you have any thoughts about this seeing much like           |
|    Godot's Vector2 implementation, then you're right!             |
|    I like how them implement it, so I took inspiration on it.     |
|    I love Godot.                                                  |
|                                                                   |
|    - Goulax16                                                     |
\-------------------------------------------------------------------/
*/

#include "math/math_utils.h"
#include <cmath>

namespace xsmall {
namespace math {

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
    constexpr T length() const;
    constexpr T length_squared() const;
    constexpr vec2<T> max(const vec2<T> &other) const;
    constexpr vec2<T> min(const vec2<T> &other) const;
    constexpr vec2<T> normalized() const;
    constexpr void normalize();
    constexpr vec2<T> lerp(const vec2<T> &to, T t) const;
    constexpr vec2<T> rotated(T angle) const;
    constexpr vec2<T> direction_to(const vec2<T> &to) const;
    constexpr T distance_to(const vec2<T> &to) const;
    constexpr T distance_squared_to(const vec2<T> &to) const;
    constexpr vec2<T> perpendicular() const;
    constexpr vec2<T> reflect(const vec2<T> &line) const;
    constexpr vec2<T> bounce(const vec2<T> &line) const;
    constexpr vec2<T> project(const vec2<T> &to) const;
    constexpr bool is_zero_approx() const;
    constexpr bool is_equal_approx(const vec2<T> &to) const;

    constexpr vec2<T> operator-(const vec2<T> &other) const {
        return vec2(x - other.x, y - other.y);
    }

    constexpr vec2<T> operator+(const vec2<T> &other) const {
        return vec2(x + other.x, y + other.y);
    }

    constexpr vec2<T> operator-() const {
        return vec2(-x, -y);
    }

    constexpr vec2<T> operator+() const {
        return vec2(+x, +y);
    }

    constexpr vec2<T> operator*(const vec2<T> &other) const {
        return vec2(x * other.x, y * other.y);
    }

    constexpr vec2<T> operator/(const vec2<T> &other) const {
        return vec2(x / other.x, y / other.y);
    }

    constexpr vec2<T> operator*(T scalar) const {
        return vec2(x * scalar, y * scalar);
    }

    friend constexpr vec2<T> operator*(T scalar, const vec2<T> &v) {
        return v * scalar;
    }

    friend constexpr vec2<T> operator/(T scalar, const vec2<T> &v) {
        return v / scalar;
    }

    constexpr vec2<T> operator/(T scalar) const {
        return vec2(x / scalar, y / scalar);
    }

    constexpr void operator-=(const vec2<T> &other) {
        x -= other.x;
        y -= other.y;
    }

    constexpr void operator+=(const vec2<T> &other) {
        x += other.x;
        y += other.y;
    }

    constexpr void operator*=(const vec2<T> &other) {
        x *= other.x;
        y *= other.y;
    }

    constexpr void operator/=(const vec2<T> &other) {
        x /= other.x;
        y /= other.y;
    }

    constexpr void operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
    }

    constexpr void operator/=(T scalar) {
        x /= scalar;
        y /= scalar;
    }

    constexpr bool operator==(const vec2<T> &other) {
        return x == other.x && y == other.y;
    }

    constexpr bool operator!=(const vec2<T> &other) {
        return x != other.x && y != other.y;
    }

    constexpr bool operator<(const vec2<T> &other) const {
        return x == other.x ? (y < other.y) : (x < other.x);
    }
    constexpr bool operator>(const vec2<T> &other) const {
        return x == other.x ? (y > other.y) : (x > other.x);
    }
    constexpr bool operator<=(const vec2<T> &other) const {
        return x == other.x ? (y <= other.y) : (x < other.x);
    }
    constexpr bool operator>=(const vec2<T> &other) const {
        return x == other.x ? (y >= other.y) : (x > other.x);
    }
};

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

template <Decimal T> constexpr T vec2<T>::length() const {
    return std::sqrt(x * x + y * y);
}

template <Decimal T> constexpr T vec2<T>::length_squared() const {
    return x * x + y * y;
}

template <Decimal T> constexpr vec2<T> vec2<T>::max(const vec2<T> &other) const {
    return vec2<T>(max_util(x, other.x), max_util(y, other.y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::min(const vec2<T> &other) const {
    return vec2<T>(min_util(x, other.x), min_util(y, other.y));
}

template <Decimal T> constexpr vec2<T> vec2<T>::lerp(const vec2<T> &to, T t) const {
    return vec2<T>(std::lerp(x, to.x, t), std::lerp(y, to.y, t));
}

template <Decimal T> constexpr vec2<T> vec2<T>::rotated(T angle) const {
    T sine = std::sin(angle);
    T cos = std::cos(angle);
    return vec2<T>(x * cos - y * sine, x * sine + y * cos);
}

template <Decimal T> constexpr vec2<T> vec2<T>::direction_to(const vec2<T> &to) const {
    vec2<T> vec(to.x - x, to.y - y);
    vec.normalize();
    return vec;
}

template <Decimal T> constexpr T vec2<T>::distance_to(const vec2<T> &to) const {
    return std::sqrt((x - to.x) * (x - to.x) + (y - to.y) * (y - to.y));
}

template <Decimal T> constexpr T vec2<T>::distance_squared_to(const vec2<T> &to) const {
    return (x - to.x) * (x - to.x) + (y - to.y) * (y - to.y);
}

template <Decimal T> constexpr vec2<T> vec2<T>::perpendicular() const {
    return vec2<T>(-y, x);
}

template <Decimal T> constexpr void vec2<T>::normalize() {
    if (!std::isfinite(x) && !std::isfinite(y)) {
        x = T{0};
        y = T{0};
        return;
    }

    T len = length_squared();
    if (len == 0) {
        x = T{0};
        y = T{0};
    } else {
        len = std::sqrt(len);
        x /= len;
        y /= len;
    }
}

template <Decimal T> constexpr vec2<T> vec2<T>::normalized() const {
    auto vec = *this;
    vec.normalize();
    return vec;
}

template <Decimal T> constexpr vec2<T> vec2<T>::reflect(const vec2<T> &line) const {
    return T{2} * line * dot(line) - *this;
}

template <Decimal T> constexpr vec2<T> vec2<T>::bounce(const vec2<T> &line) const {
    return -reflect(line);
}

template <Decimal T> constexpr vec2<T> vec2<T>::project(const vec2<T> &to) const {
    return to * (dot(to) / to.length_squared());
}

template <Decimal T> constexpr bool vec2<T>::is_zero_approx() const {
    return (abs_util(x) < EPSILON) && (abs_util(y) < EPSILON);
}

template <Decimal T> constexpr bool vec2<T>::is_equal_approx(const vec2<T> &to) const {
    return is_equal_approx_util(x, to.x) && is_equal_approx_util(y, to.y);
}

} // namespace math
} // namespace xsmall