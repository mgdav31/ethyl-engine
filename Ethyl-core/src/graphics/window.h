#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

namespace ethyl::graphics {

	class Window
	{
	public: 
		//static Window* INSTANCE;

	private:
		const char* m_title;
		int m_width, m_height;
		GLFWwindow* m_window;

		bool m_keys[MAX_KEYS];
		bool m_buttons[MAX_BUTTONS];
		double mx, my;

	public:
		Window(const char* name, int width, int height);
		~Window();

		void clear() const;
		void update();
		bool isClosed() const;

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }

		bool isKeyPressed(unsigned int keycode) const;
		bool isMousePressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;

	private:
		bool init();

		// Friend methods allow for easy access to the private members when working
		// with a variable of type Window. however they are not a part of the class
		friend void resize_viewport(GLFWwindow* window, int width, int height);
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_callback(GLFWwindow* window, double xpos, double ypos);
	};

}