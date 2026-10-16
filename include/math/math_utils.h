#pragma once

#include <concepts>

namespace xsmall {
namespace math {

inline constexpr double EPSILON = 1e-5;
inline constexpr double EPSILON2 = EPSILON * EPSILON;

// only float and double types allowed
template <typename T>
concept Decimal = std::same_as<T, float> || std::same_as<T, double>;

template <Decimal T> static constexpr T clamp_util(const T value, const T min, const T max) {
    return value < min ? min : (value > max ? max : value);
}

template <Decimal T> static constexpr T abs_util(const T value) {
    return value == 0 ? 0.0 : (value < 0 ? -value : value);
}

template <Decimal T> constexpr bool is_equal_approx_util(T l, T r) {
    if (l == r) {
        return true;
    }
    float tolerance = (float)EPSILON * abs_util(l);
    if (tolerance < (float)EPSILON) {
        tolerance = (float)EPSILON;
    }
    return abs_util(l - r) < tolerance;
}

template <Decimal T> static constexpr T max_util(const T l, const T r) {
    return l > r ? l : r;
}

template <Decimal T> static constexpr T min_util(const T l, const T r) {
    return l < r ? l : r;
}

} // namespace math
} // namespace xsmall