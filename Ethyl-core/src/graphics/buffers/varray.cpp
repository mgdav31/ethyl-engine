#include "VArray.h"

/*
    TODO: Program does not store the buffers, but is trying to delete them in
      the destructor.
*/

namespace ethyl::graphics {
    VArray::VArray()
    {
        glGenVertexArrays(1, &m_arrayId);
    }

    VArray::~VArray()
    {
        for (int i = 0; i < m_buffers.size(); i++)
        {
            delete m_buffers[i];
        }
    }

    void VArray::addBuffer(VBuffer* buffer, GLuint index)
    {
        bind();
        buffer->bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
        
        buffer->unbind();
        unbind();
    }

    void VArray::bind() const
    {
        glBindVertexArray(m_arrayId);
    }

    void VArray::unbind() const
    {
        glBindVertexArray(0);
    }

}