#ifndef __VEC2F_UTIL_HPP__
#define __VEC2F_UTIL_HPP__

#include <iostream>
#include <math.h>
#include <vector>

#include "SFML/Graphics.hpp"

std::ostream & operator<<(std::ostream &out, const sf::Vector2f &v);

int test_sum(int a, int b);

#endif