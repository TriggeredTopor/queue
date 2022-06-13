#pragma once
#include <iostream>

using ValueType = double;

enum QueueContainer {
    Vector,
    List,
};


class IQueueImplementation;

class Queue
{
public:

    Queue(QueueContainer container = QueueContainer::Vector);

    Queue(const ValueType* valueArray, const size_t arraySize,
        QueueContainer container = QueueContainer::Vector);

    explicit Queue(const Queue& copyStack);
    Queue& operator=(const Queue& copyStack);


    Queue(Queue&& moveStack) noexcept;
    Queue& operator=(Queue&& moveStack) noexcept;

    ~Queue();


    void push(const ValueType& value);

    void pop();

    const ValueType& top() const;

    bool isEmpty() const;

    size_t size() const;
private:

    IQueueImplementation* _pimpl = nullptr;

    QueueContainer _containerType;
};

