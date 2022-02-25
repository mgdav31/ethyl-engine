#include "mat4.h"

namespace ethyl::math {
    mat4::mat4()
    {
        clearArray(elements, 4 * 4);
    }

    mat4::mat4(float diagonal)
    {
        clearArray(elements, 4 * 4);
        elements[0 + 0*4] = diagonal;
        elements[1 + 1*4] = diagonal;
        elements[2 + 2*4] = diagonal;
        elements[3 + 3*4] = diagonal;
    }


    // OPENGL USES COLUMN MAJOR:
    //   Column Major means element indexes go from top-bot, then left-right
    //   Row Major would mean we fill indexes like we read/write.
    mat4& mat4::multiply(const mat4& other)
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                float sum = 0.0f;
                for (int e = 0; e < 4; e++)
                {
                    sum += elements[x + e*4] * other.elements[e + y*4];
                }
                elements[x + y*4] = sum;
            }
        }
        return *this;
    }

    mat4 mat4::orthographic(float top, float right, float bottom, float left, float near, float far)
    {
        mat4 result(1.0f);

        result.elements[0 + 0*4] = 2.0f / (right - left);
        result.elements[1 + 1*4] = 2.0f / (top - bottom);
        result.elements[2 + 2*4] = 2.0f / (near - far);

        result.elements[0 + 3*4] = (left + right) / (left - right);
        result.elements[1 + 3*4] = (bottom + top) / (bottom - top);
        result.elements[2 + 3*4] = (far + near) / (far - near);
        return result;
    }

    mat4 mat4::perspective(float fov, float aspect, float near, float far)
    {
        mat4 result(1.0f);

        float q = 1.0f / tan(toRadians(0.5f * fov));
        float a = q / aspect;
        float b = (near + far) / (near - far);
        float c = (2.0f * near * far) / (near - far);

        result.elements[0 + 0*4] = a;
        result.elements[1 + 1*4] = q;
        result.elements[2 + 2*4] = b;
        result.elements[3 + 2*4] = -1.0f;
        result.elements[2 + 3*4] = c;
        result.elements[3 + 3*4] = 0; // I believe this is correct, tho cherno didnt have it.
        return result;
    }

    mat4 mat4::translation(const vec3& translation)
    {
        mat4 result(1.0f);

        result.elements[0 + 3*4] = translation.x;
        result.elements[1 + 3*4] = translation.y;
        result.elements[2 + 3*4] = translation.z;
        return result;
    }

    mat4 mat4::scale(const vec3& scale)
    {
        mat4 result(1.0f);

        result.elements[0 + 0*4] = scale.x;
        result.elements[1 + 1*4] = scale.y;
        result.elements[2 + 2*4] = scale.z;
        return result;
    }

    mat4 mat4::rotation(float angle, const vec3& axis)
    {
        float r     = toRadians(angle);
        float c     = cos(r);
        float s     = sin(r);
        float omc   = (1 - c);
        float x = axis.x; float y = axis.y; float z = axis.z;

        mat4 result(1.0f);

        result.elements[0 + 0*4] = (x * x * omc) + c;
        result.elements[1 + 0*4] = (x * y * omc) + (z * s);
        result.elements[2 + 0*4] = (x * z * omc) - (y * s);

        result.elements[0 + 1*4] = (x * y * omc) - (z * s);
        result.elements[1 + 1*4] = (y * y * omc) + c;
        result.elements[2 + 1*4] = (y * z * omc) + (x * s);

        result.elements[0 + 2*4] = (x * z * omc) + (y * s);
        result.elements[1 + 2*4] = (y * z * omc) - (x * s);
        result.elements[2 + 2*4] = (z * z * omc) + c;
        return result;
    }

    mat4& mat4::operator*=(const mat4& other)
    {
        return multiply(other);
    }

    mat4 operator*(mat4 left, const mat4& right)
    {
        return left.multiply(right);
    }

    std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
    {
        stream << "mat4[" << std::endl;
        for (int y = 0; y < 4; y++)
        {
            stream << "  ";
            for (int x = 0; x < 4; x++)
            {
                stream << matrix.elements[y + x*4] << ", ";
            }
            stream << std::endl;
        }
        stream << "]";
        return stream;
    }

}