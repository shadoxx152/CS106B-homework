/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "error.h"
using namespace std;

/*
 * sumOfSquares (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named sumOfSquares that takes
 * an int n and returns the sum of squares from 1 to n.
 */

int sumOfSquares(int n){
    // TODO: Your code here
    if (n < 0) {
        error("");
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    return sumOfSquares(n - 1) + n * n;
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Example Tests") {
    EXPECT_EQUAL(sumOfSquares(3), 14);
    EXPECT_EQUAL(sumOfSquares(4), 30);
    EXPECT_EQUAL(sumOfSquares(5), 55);
    EXPECT_EQUAL(sumOfSquares(6), 91);
}


