#include "src/mgdutils.h"
#include "src/fileutils.h"
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/simple2DRenderer.h"
#include "src/graphics/buffers/vbuffer.h"
#include "src/graphics/buffers/ibuffer.h"
#include "src/graphics/buffers/varray.h"

#include "src/math/math.h"
#include "src/neural/neuron.h"

#include <chrono>

#define APP_TITLE		"Ethyl Engine"
#define APP_VERSION		"v1.0a"
#define APP_GAME_MODE	1

using namespace ethyl;

void inputTests(ethyl::graphics::Window* window);
void drawSprite(graphics::Shader* shader, graphics::VArray* vao, graphics::IBuffer* ibo, const math::vec3& pos);

int MainGame()
{
	LOG(APP_TITLE " " APP_VERSION);
	graphics::Window window(APP_TITLE " " APP_VERSION, 1200, 675);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	math::mat4 ortho = math::mat4::orthographic(9.0f, 16.0f, 0.0f, 0.0f, 1.0f, -1.0f);
	graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");

	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", math::mat4::translation(math::vec3(4, 3, 0)));
	shader.setUniformMat4("ml_matrix", math::mat4::rotation(45.0f, math::vec3(0, 0, 1)));

	graphics::Renderable2D sprite(math::vec3(5, 5, 0), math::vec2(4, 4), math::vec4(1, 0, 1, 1), shader);
	graphics::Renderable2D sprite2(math::vec3(7, 1, 0), math::vec2(6, 4), math::vec4(1, 1, 0, 1), shader);
	graphics::Simple2DRenderer renderer;

	shader.setUniform4f("col", math::vec4(0.4f, 0.3f, 1.0f, 1.0f));
	shader.setUniform2f("light_pos", math::vec2(4.0f, 1.5f));
	while (!window.isClosed())
	{
		window.clear();
		//inputTests(&window);

		//drawSprite(&shader, &sprite2, &ibo, math::vec3(0, 0, 0));
		//drawSprite(&shader, &sprite1, &ibo, math::vec3(4, 3, 0));
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", math::vec2(x / window.getWidth() * 16, 9 - (y / window.getHeight() * 9)));
		//LOG(x << ", " << y);
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

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
}
void drawSprite(graphics::Shader* shader, graphics::VArray* vao, graphics::IBuffer* ibo, const math::vec3& pos)
{
	vao->bind();
	ibo->bind();
	shader->setUniformMat4("ml_matrix", math::mat4::translation(pos));
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, 0);
	ibo->unbind();
	vao->unbind();
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

void runTest()
{
	int MAX = 10;

	auto t1 = TIME_NOW;
	for (int i = 0; i < MAX; i++)
	{
		LOG("Iteration: " << i);
	}
	auto t2 = TIME_NOW;
	LOG("Time: " << GET_TIME((t2 - t1), milliseconds) << "ms");
}

int main()
{
	//runTest();

#if APP_GAME_MODE
	return MainGame();
#else
	return MainNeural();
#endif
}
