#pragma once

#include <vector>
#include "GL/glew.h"

#include "VBuffer.h"
#include "IBuffer.h"

namespace ethyl::graphics {
    class VArray
    {
    private:
        GLuint m_arrayId;
        std::vector<VBuffer*> m_buffers;

    public:
        VArray();
        ~VArray();

        void addBuffer(VBuffer* buffer, GLuint index);
        void bind() const;
        void unbind() const;
    };
}