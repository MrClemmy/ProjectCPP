#include <iostream>
#include <cmath> // for comparing doubles
using namespace std;

#include "functions.h"  // Students will create this file



// Helper to compare doubles within small tolerance
bool almostEqual(double a, double b, double tolerance = 0.0001) {
    return fabs(a - b) < tolerance;
}

void runTests() {
    cout << "Running Function Tests...\n";

    // 1. Test Subtract
    if (almostEqual(subtract(5.0, 2.0), 3.0) &&
        almostEqual(subtract(-4.2, 23.0), -27.2)) {
        cout << "✅ Subtract: Passed\n";
    } else {
        cout << "❌ Subtract: Failed — Check your subtraction logic.\n";
    }

    // 2. Test Divide
    if (almostEqual(divide(10.0, 5.0), 2.0) &&
        almostEqual(divide(100.0, 20.0), 5.0)) {
        cout << "✅ Divide: Passed\n";
    } else {
        cout << "❌ Divide: Failed — Check your division logic.\n";
    }

    // 3. Test Biggest
    if (almostEqual(biggest(5.0, 10.0, 7.0), 10.0) &&
        almostEqual(biggest(4.9, 5.0, 5.0), 5.0)) {
        cout << "✅ Biggest: Passed\n";
    } else {
        cout << "❌ Biggest: Failed — Check your logic for finding the largest value.\n";
    }

    // 4. Test Smallest
    if (almostEqual(smallest(6.0, 20.0, 3.0), 3.0) &&
        almostEqual(smallest(3.14, 1.17, 8.3), 1.17)) {
        cout << "✅ Smallest: Passed\n";
    } else {
        cout << "❌ Smallest: Failed — Check your logic for finding the smallest value.\n";
    }

    // 5. Test Even/Odd
    if (isEven(4) && !isEven(7) && isOdd(7) && !isOdd(4)) {
        cout << "✅ Even/Odd: Passed\n";
    } else {
        cout << "❌ Even/Odd: Failed — Check your logic for even and odd numbers.\n";
    }

    // 6. Test SumRange
    int sum1 = sumRange(8, 20);  // should be 182
    int sum2 = sumRange(3, 13);  // should be 88
    if (sum1 == 182 && sum2 == 88) {
        cout << "✅ SumRange: Passed\n";
    } else {
        cout << "❌ SumRange: Failed — Check range summing logic (inclusive) or off-by-one errors.\n";
    }

    // 7. Test Power
    if (power(4, 5) == 1024 && power(1, 365) == 1) {
        cout << "✅ Power: Passed\n";
    } else {
        cout << "❌ Power: Failed — Check your loop logic for repeated multiplication.\n";
    }

    // 8. Test Random Number (this one is tricky to unit test)
    int randNum = randomNumber(1, 100);
    if (randNum >= 1 && randNum <= 100) {
        cout << "✅ RandomNumber: Passed (Range check only)\n";
    } else {
        cout << "❌ RandomNumber: Failed — Make sure your random numbers are in the correct range.\n";
    }

    // 9. Test isPrime
    if (isPrime(2) && isPrime(7) && !isPrime(8) && !isPrime(1)) {
        cout << "✅ IsPrime: Passed\n";
    } else {
        cout << "❌ IsPrime: Failed — Check logic for identifying prime numbers.\n";
    }

    // 10. Test countPrimes (output-based)
    cout << "\nManual check required for countPrimes — expected output:\n";
    cout << "There are 5 prime numbers up to 12.\n";
    cout << "There are 8 prime numbers up to 22.\n";
    countPrimes(12);
    countPrimes(22);

    cout << "\n✅ Finished Running Tests\n";
}

int main() {
    srand(time(0));  // Seed random number generator once in main()

    runTests();

    return 0;
}