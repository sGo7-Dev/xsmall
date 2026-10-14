#pragma once

/// @brief Application time information
struct TimeInfo {
    /// @brief Time elapsed between frames
    float delta = 0.0f;
    /// @brief Total elapsed time
    double elapsed = 0.0;
};