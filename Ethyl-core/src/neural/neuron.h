#pragma once

#include "../mgdutils.h"

#define PULSE_RATE_HZ	1
#define MAX_FRIENDS		8

namespace ethyl::neural {

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
}