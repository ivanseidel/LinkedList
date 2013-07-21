# LinkedList

This library was developed targeting **`Arduino`** applications. However, works just great with any C++.

Implementing a buffer for objects takes time. If we are not in the mood, we just create an array[1000] with enough size.

The objective of this library is to create a pattern for projects. If you need, in ANY case to use a List of: `int`, `float`, `objects`, `Lists` or `Wales`. **This is what you are looking for.**

## Installation

1. [Download](https://github.com/ivanseidel/LinkedList/releases) the Latest release from gitHub.
2. Unzip and modify the Folder name to "LinkedList" (Remove the '-version')
3. Paste the modified folder on your Library folder (On your `Libraries` folder inside Sketchbooks or Arduino software).

## Getting started

**If you are here, because another Library requires this class, just don't waste time reading bellow. Install and ready.**

-------------------------

### The `LinkedList` class

In case you don't know what a LinkedList is and what it's used for, take a quick look at [Wikipedia::LinkedList](https://en.wikipedia.org/wiki/Linked_list) before continuing.

#### To declare a LinkedList object
```c++
// Instantiate a LinkedList that will hold 'integer'
LinkedList<int> myLinkedList = LinkedList<int>();

// Or just this
LinkedList<int> myLinkedList();

// But if you are instantiating a pointer LinkedList...
LinkedList<int> *myLinkedList = new LinkedList<int>();

// If you want a LinkedList with any other type such as 'MyClass'
LinkedList<MyClass> *myLinkedList = new LinkedList<MyClass>();
```

#### Getting the size of the linked list
```c++
// To get the size of a linked list, make use of the size() method
int theSize = myList.size();

// Notice that if it's pointer to the linked list, you should use -> instead
int theSize = myList->size();
```

#### Adding objects to the `LinkedList`

```c++
// add(obj) method will insert at the END of the list
myList.add(myObject);

// add(index, obj) method will try to insert the object at the specified index
myList.add(0, myObject); // Add at the beginning
myList.add(3, myObject); // Add on the index 3

// unshift(obj) method will insert the object at the beginning
myList.unshift(myObject);

// set(index, obj) method will change the object at index to obj
myList.set(0, myObject); // Change the first element to myObject
myList.set


```

#### Removing objects from `LinkedList`


When dealing with the `variance`, you can also do the same as the `mean`. Access it direcly from
the object, or use the methods `vary` and `setVariance` to change the `variance`.

#### Set, Change and get `variance` values
```c++
// Set or Get the attribute direcly to the object
myGaussian.variance = 4;

// Increase the variance by `y`
myGaussian.vary(3);

// Set to 3 and then vary 10 more
myGaussian.setVariance(3).vary(10);
```

Ok, now that we can change both `mean` and `variance`, we can now go to the next step: Summing Gaussians.

It's already implemented all the math to do that, and it's nos so hard to understand it, after resuming
sum of Gaussians to 'sum of pondered values'.

The operators **+, +=, =** works just good with the class `Gaussian`.

#### Sum, Set and do Math with Gaussians
```c++
Gaussian g1 = Gaussian(0, 10);
Gaussian g2(10, 10);

// Simply sum both of them (the + method is overloaded on the class)
Gaussian result = g1 + g2;

// Or do like this
result = g1;
result += g2;
```

============================

### `GaussianAverage` class

This class provides a simple but really powerfull filter called [Moving Average](https://en.wikipedia.org/wiki/Moving_average).

It's an average of the last `n` values, but using `Gaussians` to incorporate the power of uncertainty.

You can also use it as a simple `Moving Average` by setting the `variance` to a fixed value, or just not
setting it (The default value when a Gaussian is created is really High, and is a constant).

Also, `GaussianAverage` class EXTENDS from `Gaussian`. Instead of calculating only the average (mean), you have access
to the variance as well.

**ATTENTION: This class REQUIRES [LinkedList class](https://github.com/ivanseidel/LinkedList) as well. It MUST be included BEFORE `GaussianAverage`.**
```c++
#include <LinkedList.h>
#include <GaussianAverage.h>
```

#### To declare a `GaussianAverage` object

```c++
// The default number of samples is 4
GaussianAverage myAverage = GaussianAverage();

// If you want to change it pass to constructor
// 30 samples will be stored
GaussianAverage myAverage = GaussianAverage(30);

// The same as above
GaussianAverage myAverage(30);
```

Now that we have our class instantiated, let's proceed to add Values (or Gaussians) to it.

There are two main ways to add values to the `Average`. Using the `sum(Gaussian)` method, or `+=` overloaded operator.

#### To add values to the Moving Average just use the operator `+=`
```c++
// Add it through the add method
myAverage.add(Gaussian(32,20));
myAverage.add(myGaussian);

// Add it with the overloaded operator +=
myAverage += Gaussian(32, 20);
myAverage += myGaussian;

// You can also add an double/integer to it
// (note that the Variance will be always the same, and very HIGH)
myAverage += 32;
myAverage += 70;
```

Ok, we have created and added... What is missing? Yes, Process.

The process of calculating the average is not done every time you add something new (you migth want
to add three samples before calculating). So, to calculate it you can use the method `process()`.

Once you have processed, the values of the `mean` and `variance` will be stored inside the object.
Note that `process` method returns the `self` object.

To minimize the CPU usage, we have implemented a cache detector. If you use the method `process` more
than once before adding something new, the new average will not be calculated.

#### Process the new Average
```c++
// This will run the calculation and store the result inside the myAverage object
// (remember that it's also a Gaussian!)
myAverage.process();

// Or perhaps, you want to save it
mySavedAverage = myAverage.process();

// Or you want to process, change it, and then save
myAverage.process();
myAverage.vary(30).move(10);

mySavedAverage = myAverage;
```

------------------------

## Library Reference

### `Gaussian` class

- `double` `Gaussian::mean` - Mean of the Gaussian.

- `double` `Gaussian::variance` - Variance of the Gaussian.

- `Gaussian::Gaussian(double _mean = 0.0, double _variance = MAX_VARIANCE)` - Constructor.

- `Gaussian` `Gaussian::setMean(double _val)` - Set the mean to _val.

- `Gaussian` `Gaussian::move(double _val)` - Adds _val to the mean.

- `Gaussian` `Gaussian::setVariance(double _val)` - Set the variance to _val.

- `Gaussian` `Gaussian::vary(double _val)` - Adds _val to the variance.

- `void` `Gaussian::operator=(Gaussian _gaus)` - Copies the mean and variance to current object.

- `Gaussian` `Gaussian::operator+(Gaussian _gaus)` - Sum gaussians and returns the new Gaussian.

- `void` `Gaussian::operator+=(Gaussian _gaus)` - Sum gaussians and saves it to itself.

- **protected** `Gaussian` `sum(double _mean, double _variance)` - Return the sum of itself with _mean and _variance.

=======================

### `GaussianAverage` class

- `GaussianAverage::GaussianAverage(int _n = 4)` - Constructor. n = number of samples to hold.

- `void` `GaussianAverage::add(Gaussian g)` - Add the Gaussian g to the LinkedList.

- `void` `GaussianAverage::operator+=(Gaussian _gaus)` - Add the Gaussian _gaus to the LinkedList.

- `void` `GaussianAverage::operator+=(double _mean)` - Add a new Gaussian with mean _mean to the LinkedList.

- `Gaussian` `GaussianAverage::process()` - Calculate the average Gaussian and returns it.

- **proteced** `LinledList<Gaussian>` `GaussianAverage::*gaussians` - Pointer to linked list that will hold the latest Gaussians.

- **proteced** `int` `GaussianAverage::n` - Number of samples to hold.

- **proteced** `bool` `GaussianAverage::isCached` - Flag that indicates if a process() MUST be done.

- **proteced** `Gaussian` `avg` - Only a temporary helper used by process().

----------------------------


### Version History

* `1.0 (2013-07-20)`: Original release
