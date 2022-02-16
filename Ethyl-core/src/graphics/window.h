#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace ethyl { namespace graphics {

	class Window
	{
	private:
		const char* m_title;
		int m_width, m_height;
		GLFWwindow* m_window;
		//bool closed;

	public:
		Window(const char* name, int width, int height);
		~Window();

		void clear() const;
		void update();
		bool isClosed() const;

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }

	private:
		bool init();

	};

}}