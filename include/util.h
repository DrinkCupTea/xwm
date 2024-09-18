/* See LICENSE file for copyright and license details. */
#ifndef XWM_UTIL_H
#define XWM_UTIL_H

#include <stddef.h>

inline constexpr auto MAX(auto a, auto b) {
    return a > b ? a : b;
}

inline constexpr auto MIN(auto a, auto b) {
    return a > b ? b : a;
}

inline constexpr auto BETWEEN(auto x, auto a, auto b) {
    return (a <= x && x <= b);
}

void die(const char* fmt, ...);
void* ecalloc(size_t nmemb, size_t size);

#endif