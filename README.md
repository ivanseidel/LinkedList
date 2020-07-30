# TrueLinkedList

This library was developed targeting **`Arduino`** applications. However, works just great with any C++.

Implementing a buffer for objects takes time. If we are not in the mood, we just create an `array[1000]` with enough size.

The objective of this library is to create a pattern for projects.
If you need to use a List of: `int`, `float`, `objects`, `Lists` or `Wales`. **This is what you are looking for.**

With a simple but powerful caching algorithm, you can get subsequent objects much faster than usual. Tested without any problems with Lists bigger than 2000 members.

## Installation

1. [Download](https://github.com/ivanseidel/TrueLinkedList/archive/master.zip) the Latest release from gitHub.
2. Unzip and modify the Folder name to "TrueLinkedList" (Remove the '-version')
3. Paste the modified folder on your Library folder (On your `Libraries` folder inside Sketchbooks or Arduino software).
4. Reopen the Arduino software.

**If you are here, because another Library requires this class, just don't waste time reading bellow. Install and ready.**

## Tests

`cd` to this directory and run `g++ -std=c++14 tests.cpp -o tests && ./tests`

-------------------------

## Getting started

### The `TrueLinkedList` class

In case you don't know what a TrueLinkedList is and what it's used for, take a quick look at [Wikipedia::TrueLinkedList](https://en.wikipedia.org/wiki/Linked_list) before continuing.

#### To declare a TrueLinkedList object
```c++
// Instantiate a TrueLinkedList that will hold 'integer'
TrueLinkedList<int> myTrueLinkedList = TrueLinkedList<int>();

// Or just this
TrueLinkedList<int> myTrueLinkedList;

// But if you are instantiating a pointer TrueLinkedList...
TrueLinkedList<int> *myTrueLinkedList = new TrueLinkedList<int>();

// If you want a TrueLinkedList with any other type such as 'MyClass'
// Make sure you call delete(MyClass) when you remove!
TrueLinkedList<MyClass> *myTrueLinkedList = new TrueLinkedList<MyClass>();
```

#### Getting the size of the linked list
```c++
// To get the size of a linked list, make use of the size() method
int theSize = myList.size();

// Notice that if it's pointer to the linked list, you should use -> instead
int theSize = myList->size();
```

#### Adding elements

```c++
// add(obj) method will insert at the END of the list
myList.add(myObject);

// add(index, obj) method will try to insert the object at the specified index
myList.add(0, myObject); // Add at the beginning
myList.add(3, myObject); // Add at index 3

// unshift(obj) method will insert the object at the beginning
myList.unshift(myObject);
```

#### Getting elements

```c++
// get(index) will return the element at index
// (notice that the start element is 0, not 1)

// Get the FIRST element
myObject = myList.get(0);

// Get the third element
myObject = myList.get(2);

// Get the LAST element
myObject = myList.get(myList.size() - 1);
```

#### Changing elements
```c++
// set(index, obj) method will change the object at index to obj

// Change the first element to myObject
myList.set(0, myObject);

// Change the third element to myObject
myList.set(2, myObject);

// Change the LAST element of the list
myList.set(myList.size() - 1, myObject);
```

#### Removing elements
```c++
// remove(index) will remove and return the element at index

// Remove the first object
myList.remove(0);

// Get and Delete the third element
myDeletedObject = myList.remove(2);

// pop() will remove and return the LAST element
myDeletedObject = myList.pop();

// shift() will remove and return the FIRST element
myDeletedObject = myList.shift();

// clear() will erase the entire list, leaving it with 0 elements
// NOTE: Clear wont DELETE/FREE memory from Pointers, if you
// are using Classes/Poiners, manualy delete and free those.
myList.clear();
```

#### Sorting elements
```c++
// Sort using a comparator function
myList.sort(myComparator);
```

------------------------

## Library Reference

### `ListNode` struct

- `T` `ListNode::data` - The object data

- `ListNode<T>` `*next` - Pointer to the next Node

### `TrueLinkedList` class

**`boolean` methods returns if succeeded**

- `TrueLinkedList<T>::TrueLinkedList()` - Constructor.

- `TrueLinkedList<T>::~TrueLinkedList()` - Destructor. Clear Nodes to minimize memory. Does not free pointer memory.

- `int` `TrueLinkedList<T>::size()` - Returns the current size of the list.

- `bool` `TrueLinkedList<T>::add(T)` - Add element T at the END of the list.

- `bool` `TrueLinkedList<T>::add(int index, T)` - Add element T at `index` of the list.

- `bool` `TrueLinkedList<T>::unshift(T)` - Add element T at the BEGINNING of the list.

- `bool` `TrueLinkedList<T>::set(int index, T)` - Set the element at `index` to T.

- `T` `TrueLinkedList<T>::remove(int index)` - Remove element at `index`. Return the removed element. Does not free pointer memory

- `T` `TrueLinkedList<T>::pop()` - Remove the LAST element. Return the removed element.

- `T` `TrueLinkedList<T>::shift()` - Remove the FIRST element. Return the removed element.

- `T` `TrueLinkedList<T>::get(int index)` - Return the element at `index`.

- `void` `TrueLinkedList<T>::clear()` - Removes all elements. Does not free pointer memory.

- `void` `TrueLinkedList<T>::sort(int (*cmp)(T &, T &))` - Sorts the linked list according to a comparator funcrion. The comparator should return < 0 if the first argument should be sorted before the second, and > 0 if the first argument should be sorted after the first element. (Same as how `strcmp()` works.)

- **protected** `int` `TrueLinkedList<T>::_size` - Holds the cached size of the list.

- **protected** `ListNode<T>` `TrueLinkedList<T>::*root` - Holds the root node of the list.

- **protected** `ListNode<T>` `TrueLinkedList<T>::*last` - Holds the last node of the list.

- **protected** `ListNode<T>*` `TrueLinkedList<T>::getNode(int index)` - Returns the `index` node of the list.

### Version History

* `1.1 (2013-07-20)`: Cache implemented. Getting subsequent objects is now O(N). Before, O(N^2).
* `1.0 (2013-07-20)`: Original release

![TrueLinkedList](https://d2weczhvl823v0.cloudfront.net/ivanseidel/TrueLinkedList/trend.png)
