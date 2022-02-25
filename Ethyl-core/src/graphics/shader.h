#pragma once

#include <vector>
#include <GL/glew.h>
#include "../mgdutils.h"
#include "../fileutils.h"
#include "../math/math.h"

namespace ethyl::graphics {
    class Shader
    {
    private:
        GLuint m_shaderId;
        const char *m_vertPath, *m_fragPath;

    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void setUniform1f(const GLchar* name, float value);
        void setUniform1i(const GLchar* name, int value);
        void setUniform2f(const GLchar* name, const math::vec2& vector);
        void setUniform3f(const GLchar* name, const math::vec3& vector);
        void setUniform4f(const GLchar* name, const math::vec4& vector);
        void setUniformMat4(const GLchar* name, const math::mat4& matrix);

        void enable() const;
        void disable() const;

        inline GLuint getId() { return m_shaderId; }

    private:
        GLuint load();
        GLint getUniformLocation(const GLchar* name);
    };
}