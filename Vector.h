#pragma once
#include "QueueImplementation.h"
#include <vector>

using ValueType = double;
using namespace std;

class VectorQueue : public IQueueImplementation {
private:
    vector <ValueType> Vector;
public:
    VectorQueue();

    void push(const ValueType& value)override;

    void pop()override;

    const ValueType& top() const override;

    bool isEmpty() const override;

    size_t size() const override;

    virtual ~VectorQueue();
};
