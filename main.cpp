#include "Queue.h"
#include "ListQueue.h"
#include "Vector.h"
#include "QueueImplementation.h"
#include <iostream>


int main() {
	std::vector <double> source = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
	std::vector <double> source2 = { 0.1,0.2,0.3 };
	Queue first(source.data(), source.size(), List);
	//Queue second(source2.data(), source2.size(), List);
	Queue clear(Vector);
	Queue third(Vector);
	Queue fourth(Vector);
	third = first;
	//fourth = second;
	//cout << second.size()<<endl;
	int size = first.size();
	for (int i = 0; i < size; i++) {
		cout << first.top() << endl;
		first.pop();
	};

};
