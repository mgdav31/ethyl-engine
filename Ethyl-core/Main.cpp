#include "src/mgdutils.h"
#include "src/graphics/window.h"

#define NEURAL_MODE	0

#if NEURAL_MODE == 0
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
		if (window.isKeyPressed(GLFW_KEY_A))
		{
			LOG("A PRESSED");
		}

		if (window.isMousePressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			LOG("MOUSE PRESSED");
		}

		double x, y;
		window.getMousePosition(x, y);
		LOG(x << ", " << y);

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}

# else
// NEURAL PULSE

#define PULSE_RATE_HZ	1
#define MAX_FRIENDS		8

class Neuron
{
private:
	Neuron* m_friends[MAX_FRIENDS];
	uint m_index;
public:
	Neuron();

	void Fire(float pulse);

	void Print();
	bool AddFriend();
};


Neuron::Neuron()
{
	m_index = 0;
	for (int i = 0; i < MAX_FRIENDS; i++)
	{
		m_friends[i] = nullptr;
	}
}

void Neuron::Print()
{
	for (int i = 0; i < MAX_FRIENDS; i++)
	{
		LOG(m_friends[i]);
	}
}

void Neuron::Fire(float pulse)
{
	for (int i = 0; i < MAX_FRIENDS; i++)
	{
		LOG(m_friends[i]);
	}
}

bool Neuron::AddFriend()
{
	if (m_index >= MAX_FRIENDS)
	{
		return false;
	}

	Neuron *n = new Neuron();
	m_friends[m_index] = n;
	m_index += 1;
	return true;
}

int main()
{
	using namespace ethyl;

	graphics::Window window("Neural Pulse v1.0a", 1200, 675);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Neuron *neuron = new Neuron();


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

# endif