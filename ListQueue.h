#pragma once
#include "QueueImplementation.h"
#include <list>

using ValueType = double;
using namespace std;

class ListQueue : public IQueueImplementation {
private:
    list <ValueType> List;
public:

    ListQueue();

    void push(const ValueType& value)override;

    void pop()override;

    const ValueType& top() const override;

    bool isEmpty() const override;

    size_t size() const override;

    virtual  ~ListQueue();
};
