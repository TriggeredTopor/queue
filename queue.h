#pragma once
#include <iostream>
using Value = double;

class Queue{
public:

	Queue() = default;
 	Queue(const Value* rawArray, const size_t size, float coef = 2.0f);

    explicit Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    explicit Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

	~Queue();
// push new elem
	void pushBack();
// pops first elem 
	void popFront();
// acces first elem
	void front();
// access last elem 
	void back();
// if empty true else falce
	void empty();
// swaps two queues 
	void swap();

	void erase(size_t pos, size_t count = 1);


    void eraseBetween(size_t beginPos, size_t endPos);


    size_t size() const;


    size_t capacity() const;


    double loadFactor() const;


    Value& operator[](size_t idx);
    const Value& operator[](size_t idx) const;


    long long find(const Value& value) const;
   

    void reserve(size_t capacity);


    void shrinkToFit();

	class Iterator
    {
        Value* _ptr;
    public:
        explicit Iterator(Value* ptr);
    
        Value& operator*();
    
        const Value& operator*() const;
    
        Value* operator->();
    
        const Value* operator->() const;
    
        Iterator operator++();
    
        Iterator operator++(int);
    
        bool operator==(const Iterator& other) const;
    
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
private:
    Value* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
    float _multiplicativeCoef = 2.0f;
};
}