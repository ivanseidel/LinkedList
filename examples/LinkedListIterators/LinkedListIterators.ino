/*
	LinkedList Iterators Example
	Link: http://github.com/ivanseidel/LinkedList

	Example Created by
		Emil Muratov, github.com/vortigont

*/
#include <Arduino.h>
#include <LinkedList.h>


/*
	An example on how to use STL compatible iterators to traverse LinkedList nodes

*/


LinkedList<int> myList = LinkedList<int>();

void setup()
{
	
	Serial.begin(115200);
	Serial.println("LinkedList STL compatible Iterators Example");

	// Add some stuff to the list
	int begin = 5,
		cnt = 20;

	// fill the list with ascending integers
	while (cnt--){
		myList.add(begin++);
	}

	// let's print our list
	Serial.print("myList: ");
    for(const auto i : myList){   // const iterator by value
        Serial.printf("%d ", i);
	}
	Serial.println();

	// count Sum of all list members
	int sum = 0;
    for(const auto i : myList){   // const iterator by value
        sum+=i;
	}

	Serial.printf("myList iterated sum: %d\n", sum);

	// let's double odd elements in a list and zero out evens,
	// do this right inplace, without retreive/save list elements
	for (auto& i : myList)		// mutable iterator by reference
		i *= 2*(i%2);

	// let's print our new list
	Serial.print("myList: ");
    for(const auto& i : myList){   // const iterator by reference
        Serial.printf("%d ", i);
	}

	Serial.println();
}

void loop() {

	while (true){
		delay(100);
	}; // nothing else to do, loop forever
}


