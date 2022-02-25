#include "neuron.h"

namespace ethyl::neural {

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

		Neuron* n = new Neuron();
		m_friends[m_index] = n;
		m_index += 1;
		return true;
	}
}