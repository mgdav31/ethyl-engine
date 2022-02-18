#include "vec3.h"

namespace ethyl::math {

    vec3::vec3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    vec3::vec3(const float& x, const float& y, const float& z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3& vec3::add(const vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    vec3& vec3::sub(const vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    vec3& vec3::mul(const vec3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }
    vec3& vec3::div(const vec3& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    vec3 operator+(vec3 left, const vec3& right)
    {
        return left.add(right);
    }
    vec3 operator-(vec3 left, const vec3& right)
    {
        return left.sub(right);
    }    
    vec3 operator*(vec3 left, const vec3& right)
    {
        return left.mul(right);
    }
    vec3 operator/(vec3 left, const vec3& right)
    {
        return left.div(right);
    }

    bool vec3::operator==(const vec3& other)
    {
        return x == other.x && y == other.y && z == other.z;
    }
    bool vec3::operator!=(const vec3& other)
    {
        return !(*this == other);
    }

    vec3& vec3::operator+=(const vec3& other)
    {
        return this->add(other);
    }
    vec3& vec3::operator-=(const vec3& other)
    {
        return this->sub(other);
    }
    vec3& vec3::operator*=(const vec3& other)
    {
        return this->mul(other);
    }
    vec3& vec3::operator/=(const vec3& other)
    {
        return this->div(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec3& vector)
    {
        stream << "vec3<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
        return stream;
    }

}