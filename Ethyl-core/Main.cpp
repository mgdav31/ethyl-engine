#include "src/mgdutils.h"
#include "src/graphics/window.h"

int main()
{
	using namespace ethyl;

	graphics::Window window("Ethyl Engine v1.0a", 1200, 675);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	//LOG(glGetString(GL_VERSION));

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.isClosed())
	{
		window.clear();

#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}