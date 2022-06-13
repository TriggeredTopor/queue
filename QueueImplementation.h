#pragma once
#include <iostream>

using ValueType = double;

class IQueueImplementation {
public:
    //Добавление в конец очереди
    virtual void push(const ValueType& value) = 0;
    //Выкидываение первого 
    virtual void pop() = 0;
    // просмотр первого в очереди
    virtual const ValueType& top() const = 0;
    //проверка на пустоту
    virtual bool isEmpty() const = 0;
    //Размер очереди
    virtual size_t size() const = 0;
    //Деструктор
    virtual ~IQueueImplementation() = default;
};
