#include <LinkedList.h>

/*
    How does range-based for loops work? It's similar to a macro.
    
    ```
        for (int number : numbers)
        {
            Serial.println(number);
        }
    ```

    get replaced with:

    ```
        for (INode<int> __begin = numbers.begin(), __end = numbers.end(); ++ __begin)
        {
            int number = *__begin;
            {
                Serial.println(number);
            }
        }
    ```
*/

#define foreach_node(t_ident, list, body) 

LinkedList<int> numbers = LinkedList<int>(); //Create list.

int toAdda = 10;
int toAddb = 20;
int toAddc = 30;

void setup() {
    //ADding a bunch'o numbers.
    numbers.add(toAdda);
    numbers.add(toAddb);
    numbers.add(toAddc);
    numbers.add(40);
    numbers.add(50);

    Serial.begin(9600);
    while (!Serial); //Wait for serial.


//  for (int number : numbers) //Range-based for loop. Does not copy, changing number changes value in list.
    for (int number : numbers) //<- Copies value in list, does not change value in list.
    {
        Serial.println(number);
    }

    //If you do want to change values in list (like add 10 to each), use int& (reference).

    for (int& number : numbers)
    {
        number += 10;
    }

    //Re-print values.
    for (int number : numbers)
    {
        Serial.println(number);
    }
}

void loop() {

}