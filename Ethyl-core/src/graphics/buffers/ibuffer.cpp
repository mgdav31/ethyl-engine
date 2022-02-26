#include "ibuffer.h"

namespace ethyl::graphics {
    IBuffer::IBuffer(GLushort* data, GLsizei count)
        : m_count(count)
    {
        glGenBuffers(1, &m_bufferId);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
        unbind();
    }

    void IBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
    }

    void IBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}
