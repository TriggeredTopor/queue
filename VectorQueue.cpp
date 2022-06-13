#include "Vector.h"

VectorQueue::VectorQueue()
{}

void VectorQueue::push(const ValueType& value)
{
	Vector.push_back(value);
}

void VectorQueue::pop()
{
	for (size_t i = 0; i < Vector.size()-1; i++) {
		Vector[i] = Vector[i + 1];
	}
	Vector.pop_back();
}

const ValueType& VectorQueue::top() const
{
	return (Vector.front());
}

bool VectorQueue::isEmpty() const
{
	if (Vector.size() != 0)
	{
		return false;
	}

	return true;
}

size_t VectorQueue::size() const
{
	return (Vector.size());
};

VectorQueue::~VectorQueue()
{
	Vector.clear();
}
