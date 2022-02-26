#include "vbuffer.h"

namespace ethyl::graphics {
    VBuffer::VBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
        : m_componentCount(componentCount)
    {
        glGenBuffers(1, &m_bufferId);
        bind();
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
        unbind();
    }

    void VBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
    }

    void VBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}
