#pragma once

#include <string_view>
#include <cstdint>

namespace REFrameworkNET {
    static constexpr auto hash(std::string_view data) {
        size_t result = 0xcbf29ce484222325;

        for (char c : data) {
            result ^= c;
            result *= (size_t)1099511628211;
        }

        return result;
    }

    consteval auto operator "" _fnv(const char* s, size_t) {
        return hash(s);
    }
}