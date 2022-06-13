#include "Queue.h"
#include "ListQueue.h"
#include "Vector.h"
#include "QueueImplementation.h"

#include <stdexcept>

Queue::Queue(QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
        case QueueContainer::List: 
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
            
        case QueueContainer::Vector: 
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
            
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container)
    : _containerType(container)
{
    switch (_containerType)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }

        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    for (int i = 0; i < arraySize; i++)
    {
        _pimpl->push(valueArray[i]);
    }
}

Queue::Queue(const Queue& copyStack) 
    : _containerType(copyStack._containerType)
{
    switch (_containerType)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }

        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    std::vector<ValueType> temparray;
    const int tempsize = copyStack.size();

    for (int i = 0; i < tempsize; i++)
    {
        temparray.push_back(copyStack._pimpl->top());
        copyStack._pimpl->pop();
    }

    for (int j = 0; j < tempsize; j++)
    {
        copyStack._pimpl->push(temparray[j]);
    }

    for (int k = 0; k < tempsize; k++)
    {
        _pimpl->push(temparray[k]);
    }

}

Queue& Queue::operator=(const Queue& copyStack)
{
    if (this == &copyStack)
    {
        return *this;
    }

    switch (copyStack._containerType)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }

        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }
            
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    std::vector<ValueType> temparray;
    const int tempsize = copyStack.size();

    for (int i = 0; i < tempsize; i++)
    {
        temparray.push_back(copyStack._pimpl->top());
        copyStack._pimpl->pop();
    }

    for (int j = 0; j < tempsize; j++)
    {
        copyStack._pimpl->push(temparray[j]);
    }

    for (int k = 0; k < tempsize; k++)
    {
        _pimpl->push(temparray[k]);
    }

    return *this;
}

Queue::Queue(Queue&& moveStack) noexcept
    :_containerType(moveStack._containerType)
{
    switch (_containerType)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }

        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
}

Queue& Queue::operator=(Queue&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return *this;
    }

    switch (moveStack._containerType)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }
            
        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }
            
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;

    return(*this);
}

Queue::~Queue()
{
    delete _pimpl;
}

void Queue::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Queue::pop()
{
    _pimpl->pop();
}

const ValueType& Queue::top() const
{
    return _pimpl->top();
}

bool Queue::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Queue::size() const
{
    return _pimpl->size();
}
