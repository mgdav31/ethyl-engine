#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


// Our packages
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"


// Our methods
namespace ethyl::math
{
    inline float toRadians(float degrees)
    {
        return degrees * (float)M_PI / 180.0f;
    }
}