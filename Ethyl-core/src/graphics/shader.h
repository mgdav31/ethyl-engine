#pragma once

#include <vector>
#include <GL/glew.h>
#include "../mgdutils.h"
#include "../fileutils.h"

namespace ethyl::graphics {
    class Shader
    {
    private:
        GLuint m_shaderId;
        const char *m_vertPath, *m_fragPath;

    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void enable() const;
        void disable() const;

        inline GLuint getId() { return m_shaderId; }

    private:
        GLuint load();
    };
}