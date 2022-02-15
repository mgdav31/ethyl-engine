#include "window.h"

namespace ethyl { namespace graphics {

	Window::Window(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		if (!init())
		{
			glfwTerminate();
		}
	}
	
	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Error: Could not initialize GLFW" << std::endl;
			return false;
		}

		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			glfwTerminate();
			std::cout << "Error: Failed to create GLFW window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		return true;
	}


	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() const
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);

	}

	bool Window::isClosed() const
	{
		return glfwWindowShouldClose(m_window) == 1;
	}
}}