#include <iostream>
#include <string>
#include "functions.h"
using namespace std;


int main()
{
	cout << subtract(5, 2) << endl; // 3
	cout << subtract(-4.2, 23) << endl; // -27.2

	cout << divide(10, 8) << endl; // 1.25
	cout << divide(100, 20) << endl; // 5


/* ---------------------------------------------------------- */

	//Implement biggest and smallest functions for three input values.
           // inputs: three decimal values
          // returns: the largest (or smallest) decimal value
	cout << biggest(10, 2.2, 7) << endl;  // 10
	cout << biggest(4.9, 5, 5) << endl; //5
	cout << biggest(8, 10, 20.3) << endl; //20.3

	cout << smallest(6, 20, 3) << endl; //3
	cout << smallest(3.14, 1.17, 8.3) << endl;  //1.17


/* ---------------------------------------------------------- */


	//Implement isEven, isOdd boolean functions
           // inputs: an integer value
          // returns: true if value is even for isEven (or odd for isOdd), false otherwise
	int n;
	cout << "Enter a number: " << endl;
	cin >> n;
	
	if (isEven(n))
	{
		cout << n << " is even." << endl;
	}
	
	if (isOdd(n))
	{
		cout << n << " is odd." << endl;
	}

/* ---------------------------------------------------------- */

	//Create a function that sums the numbers between the given range, and should also *print* the number of values being added up
           // inputs: two integer values
          // returns: the sum of all integers from the first to the second value
	int total1 = sumRange(8, 20);  //this should be 8+9+10+...+20 = ?  
	int total2 = sumRange(3, 13);

	cout << "There are 13 values from 8 to 20. The sum of this range is " << total1 << endl;
	cout << "There are 11 values from 3 to 13. The sum of this range is " << total2 << endl;

/* ---------------------------------------------------------- */

    //Create a function that calculates power (x raised to the y) WITHOUT using the built-in pow function
           // inputs: two integer values
          // returns: x^y (hint: x^2 = x*x)
	cout << "4 raised to the power of 5 is " << power(4, 5) << endl;    // 1024
	cout << "1 raised to the power of 365 is " << power(1, 365) << endl;  // 1

/* ---------------------------------------------------------- */

	//////////////////////////////////////////////////////
	// Next, write a random number generator that will generate random integer numbers between any two input values
	// Hint: Remember that you will need to call srand() and rand() functions in your function to do this
	int random1 = randomNumber(11, 99); // this should be a random number between 11 and 99
	int random2 = randomNumber(-5, 19); // random number between -5 and 19

	cout << "Here is a random value between 11 and 99:\t" << random1 << endl;
	cout << "Here is a random value between -5 and 19:\t" << random2 << endl;

/* ---------------------------------------------------------- */

	// Okay, now something more interesting!
    // Prime numbers cannot be evenly divided by any number smaller than them except 1
	// Write a boolean function that checks if an input number is prime or not
    // hint: computers don't mind doing lots of divisions
           // inputs: an integer value
          // returns: true if value is a prime number, false otherwise

	//if (isPrime(n))
	//{
	//	cout << n << " is prime." << endl;
	//}

/* ---------------------------------------------------------- */

    // Write a function that *counts* all the prime numbers from 1 up to a certain number
	// hint: Functions may call other functions, even other functions that *you* have written.
           // inputs: an integer value
          // returns: nothing (prints to console)	

	//countPrimes(12); //Should print: "there are 5 prime numbers up to 12"     (the prime numbers are 2,3,5,7,11)
	//countPrimes(22); //Should print: "there are 8 prime numbers up to 22"     (the prime numbers are 2,3,5,7,11,13,17,19)



	return 0;
}