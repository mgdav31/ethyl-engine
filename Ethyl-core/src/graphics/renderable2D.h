#pragma once

#include "buffers/vbuffer.h"
#include "buffers/ibuffer.h"
#include "buffers/varray.h"

#include "../math/math.h"
#include "shader.h"

namespace ethyl::graphics {
    class Renderable2D
    {
    protected:
        math::vec3 m_position;
        math::vec2 m_size;
        math::vec4 m_color;

        VArray* m_vertexArray;
        IBuffer* m_indexBuffer;
        Shader& m_shader;

    public:
        Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color, Shader& shader)
            : m_position(position), m_size(size), m_color(color), m_shader(shader)
        {
            GLfloat vertices[] = 
            {
                0,          0,          0,
                0,          size.y,     0,
                size.x,     size.y,     0,
                size.x,     0,          0
            };

            GLfloat colors[] =
            {
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w
            };
            m_vertexArray = new VArray();
            m_vertexArray->addBuffer(new VBuffer(vertices, 4 * 3, 3), 0);
            m_vertexArray->addBuffer(new VBuffer(colors, 4 * 4, 4), 1);

            GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
            m_indexBuffer = new IBuffer(indices, 6);
        }

        virtual ~Renderable2D()
        {
            delete m_vertexArray;
            delete m_indexBuffer;
        }

        inline const VArray* getVertexArray() const { return m_vertexArray; }
        inline const IBuffer* getIndexBuffer() const { return m_indexBuffer; }
        inline Shader& getShader() const { return m_shader; }

        inline const math::vec3& getPosition() const { return m_position; }
        inline const math::vec2& getSize() const { return m_size; }
        inline const math::vec4& getColor() const { return m_color; }

    };
}
