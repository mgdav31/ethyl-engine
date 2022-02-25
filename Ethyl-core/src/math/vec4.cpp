#include "vec4.h"

namespace ethyl::math {

    vec4::vec4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
    vec4::vec4(const float& x, const float& y, const float& z, const float& w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    vec4& vec4::add(const vec4& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }
    vec4& vec4::sub(const vec4& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }
    vec4& vec4::mul(const vec4& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }
    vec4& vec4::div(const vec4& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
        return *this;
    }

    vec4 operator+(vec4 left, const vec4& right)
    {
        return left.add(right);
    }
    vec4 operator-(vec4 left, const vec4& right)
    {
        return left.sub(right);
    }    
    vec4 operator*(vec4 left, const vec4& right)
    {
        return left.mul(right);
    }
    vec4 operator/(vec4 left, const vec4& right)
    {
        return left.div(right);
    }

    bool vec4::operator==(const vec4& other)
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }
    bool vec4::operator!=(const vec4& other)
    {
        return !(*this == other);
    }

    vec4& vec4::operator+=(const vec4& other)
    {
        return this->add(other);
    }
    vec4& vec4::operator-=(const vec4& other)
    {
        return this->sub(other);
    }
    vec4& vec4::operator*=(const vec4& other)
    {
        return this->mul(other);
    }
    vec4& vec4::operator/=(const vec4& other)
    {
        return this->div(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec4& vector)
    {
        stream << "vec4<" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ">";
        return stream;
    }

}