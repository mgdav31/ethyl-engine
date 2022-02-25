#include "src/mgdutils.h"
#include "src/fileutils.h"
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"
#include "src/neural/neuron.h"

#define APP_TITLE		"Ethyl Engine"
#define APP_VERSION		"v1.0a"
#define APP_GAME_MODE	1

using namespace ethyl;

void inputTests(ethyl::graphics::Window* window);

int MainGame()
{
	LOG(APP_TITLE " " APP_VERSION);
	graphics::Window window(APP_TITLE " " APP_VERSION, 1200, 675);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	math::mat4 position = math::mat4::translation(math::vec3(2, 3, 4));

	math::vec4 tester = position.columns[3];
	LOG(tester);

	/*
	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	*/

	GLfloat vertices[] =
	{
		0, 0, 0,
		15, 0, 0, 
		0, 15, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	math::mat4 ortho = math::mat4::orthographic(9.0f, 16.0f, 0.0f, 0.0f, 1.0f, -1.0f);
	LOG(ortho);
	graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	LOG(shader.getId());
	glUniformMatrix4fv(glGetUniformLocation(shader.getId(), "pr_matrix"), 1, GL_FALSE, ortho.elements);

	while (!window.isClosed())
	{
		window.clear();
		//inputTests(&window);

		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}

void inputTests(ethyl::graphics::Window* window)
{
	if (window->isKeyPressed(GLFW_KEY_A))
		LOG("A PRESSED");

	if (window->isMousePressed(GLFW_MOUSE_BUTTON_LEFT))
		LOG("MOUSE PRESSED");

	double x, y;
	window->getMousePosition(x, y);
	LOG(x << ", " << y);
}

int MainNeural()
{
	LOG(APP_TITLE " " APP_VERSION " - NEURAL");
	graphics::Window window(APP_TITLE " " APP_VERSION " - NEURAL", 1200, 675);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	neural::Neuron* neuron = new neural::Neuron();

	while (!window.isClosed())
	{
		window.clear();

		neuron->AddFriend();
		neuron->Print();

		window.update();
		system_sleep(1000 / PULSE_RATE_HZ);
	}

	return 0;
}

int main()
{
#if APP_GAME_MODE
	return MainGame();
#else
	return MainNeural();
#endif
}
