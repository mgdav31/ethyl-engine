#pragma once

#include "GL/glew.h"

namespace ethyl::graphics
{
    class IBuffer
    {
    private:
        GLuint m_bufferId;
        GLuint m_count;

    public:
        IBuffer(GLushort* data, GLsizei count);

        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return m_count; }
    };
}
