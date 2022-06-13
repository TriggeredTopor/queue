#include "ListQueue.h"

ListQueue::ListQueue()
{
	List.clear();
}

void ListQueue::push(const ValueType& value)
{
	List.push_back(value);
}

void ListQueue::pop()
{
	List.pop_front();
}

const ValueType& ListQueue::top() const
{
	return(List.front());
}

bool ListQueue::isEmpty() const
{
	if (List.empty())
	{
		return true;
	}
	return false;
}

size_t ListQueue::size() const
{
	return (List.size());
}

ListQueue::~ListQueue()
{
	List.clear();
}
