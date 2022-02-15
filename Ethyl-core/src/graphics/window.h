#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace ethyl { namespace graphics {

	class Window
	{
	private:
		const char* m_title;
		int m_width, m_height;
		GLFWwindow* m_window;

		bool closed;

	public:
		Window(const char* name, int width, int height);
		~Window();

		void clear() const;
		void update() const;
		bool isClosed() const;

	private:
		bool init();

			
	};

}}