#pragma once

#include "math.h"
#include "../mgdutils.h"


namespace ethyl::math {
    struct mat4
    {
        union
        {
            float elements[4 * 4];
            vec4 columns[4];
        };

        mat4();
        mat4(float diagonal);

        static mat4 orthographic(float top, float right, float bottom, float left, float near, float far);
        static mat4 perspective(float fov, float aspect, float near, float far);

        static mat4 translation(const vec3& translation);
        static mat4 scale(const vec3& scale);
        static mat4 rotation(float angle, const vec3& axis);

        mat4& multiply(const mat4& other);
        mat4& operator*=(const mat4& other);
        friend mat4 operator*(mat4 left, const mat4& right);

        friend std::ostream& operator<<(std::ostream& stream, const mat4& matrix);
    };
}