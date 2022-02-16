#include "window.h"
#include "../mgdutils.h"

namespace ethyl { namespace graphics {

	void resizeViewport(GLFWwindow* window, int width, int height);

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
			LOG("Error: Could not initialize GLFW");
			return false;
		}

		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window)
		{
			glfwTerminate();
			LOG("Error: Failed to create GLFW window");
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, resizeViewport);

		if (glewInit() != GLEW_OK)
		{
			LOG("Error: Could not initialize GLEW");
			return false;
		}

		LOG("OpenGL " << glGetString(GL_VERSION));
		return true;
	}


	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glViewport(0, 0, m_width, m_height);
		glfwSwapBuffers(m_window);

	}

	bool Window::isClosed() const
	{
		return glfwWindowShouldClose(m_window) == 1;
	}

	void resizeViewport(GLFWwindow* window, int width, int height)
	{
		LOG("Resizing viewport (" << width << ", " << height << ")");
		glViewport(0, 0, width, height);
	}
}}