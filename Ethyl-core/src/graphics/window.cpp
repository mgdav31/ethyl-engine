#include "window.h"
#include "../mgdutils.h"

namespace ethyl::graphics {

	void resize_viewport(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		if (!init())
		{
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_buttons[i] = false;
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
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, resize_viewport);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, mouse_callback);
		glfwSetCursorPosCallback(m_window, cursor_callback);

		if (glewInit() != GLEW_OK)
		{
			LOG("Error: Could not initialize GLEW");
			return false;
		}

		LOG("OpenGL " << glGetString(GL_VERSION));
		return true;
	}

	bool Window::isKeyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
		{
			LOG("KEY NOT FOUND");
			return false;
		}
		return m_keys[keycode];
	}

	bool Window::isMousePressed(unsigned int button) const
	{
		if (button >= MAX_BUTTONS)
		{
			LOG("BUTTON NOT FOUND");
			return false;
		}
		return m_buttons[button];
	}

	void Window::getMousePosition(double& x, double& y) const
	{
		x = mx;
		y = my;
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

	void resize_viewport(GLFWwindow* window, int width, int height)
	{
		LOG("Resizing viewport (" << width << ", " << height << ")");
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_keys[key] = action != GLFW_RELEASE;

	}

	void mouse_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_buttons[button] = action != GLFW_RELEASE;
	}

	void cursor_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

}