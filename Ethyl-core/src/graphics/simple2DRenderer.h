#pragma once

#include <deque>
#include "renderer2D.h"

namespace ethyl::graphics {
    class Simple2DRenderer : Renderer2D
    {
    private:
        std::deque<const Renderable2D*> m_renderQueue;

    public:
        virtual void submit(const Renderable2D* renderable) override;
        virtual void flush() override;

    };

}