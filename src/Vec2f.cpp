#include "Vec2f.hpp"

/**
 * @brief << operator function for Vec2f class. Used to print the vector.
 * 
 * @param out std::ostream reference
 * @param v Vec2f reference
 * @return std::ostream& reference
 */
std::ostream & operator<<(std::ostream &out, const Vec2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

/* ### Math operators ### */

/**
 * @brief + operator function for Vec2f class. Adds vector u with vector v.
 * 
 * @param u term/summand/addend (Vec2f reference)
 * @param v term/summand/addend (Vec2f reference)
 * @return Vec2f sum
 */
Vec2f operator+(const Vec2f &u, const Vec2f &v)
{
    return Vec2f(u.x + v.x, u.y + v.y);
}

/**
 * @brief - operator function for Vec2f class. Subtracts vector u with vector v.
 * 
 * @param u term/minuend (Vec2f reference)
 * @param v term/subtrahend (Vec2f reference)
 * @return Vec2f difference
 */
Vec2f operator-(const Vec2f &u, const Vec2f &v)
{
    return Vec2f(u.x - v.x, u.y - v.y);
}

/**
 * @brief * operator function for Vec2f class. Multiplies the two vectors.
 * 
 * @param u factor/multiplier (Vec2f reference)
 * @param v factor/multiplier (Vec2f reference)
 * @return Vec2f product
 */
Vec2f operator*(const Vec2f &u, const Vec2f &v)
{
    return Vec2f(u.x * v.x, u.y * v.y);
}

/**
 * @brief * operator function for Vec2f class. Multiplies the vector with a float value.
 * 
 * @param u factor/multiplier (float reference)
 * @param v factor/multiplier (Vec2f reference)
 * @return Vec2f product
 */
Vec2f operator*(const float &u, const Vec2f &v)
{
    return Vec2f(u * v.x, u * v.y);
}

/**
 * @brief * operator function for Vec2f class. Multiplies the vector with the float value.
 * 
 * @param v factor/multiplier (Vec2f reference)
 * @param u factor/multiplier (float reference)
 * @return Vec2f product
 */
Vec2f operator*(const Vec2f &v, const float &u)
{
    return u * v;
}

/**
 * @brief / operator function for Vec2f class. Divides the vector with the float value, throws error when div by 0.
 * 
 * @param v dividend/numerator (Vec2f reference)
 * @param u dividend/numerator (float reference)
 * @return Vec2f fraction/quotient/ratio
 */
Vec2f operator /(const Vec2f &v, const float &u)
{
    if (u == 0.f)
        throw std::runtime_error("[MATH ERROR]: Attempted to divide by 0");
    return (1.f/u) * v;
}