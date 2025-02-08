#include "HumanPyramids.h"
#include "error.h"
#include "map.h"
#include "utility"
using namespace std;

Map<pair<int, int>, double> memory;
double weightOnBackOf(int row, int col, int pyramidHeight) {
    if (row > pyramidHeight || pyramidHeight <= 0 || row < 0 || col < 0) {
        error("");
        return -1;
    }

    if (col == 0 && row == 0) {
        return 0;
    }

    if (memory.containsKey({row, col})) {
        return memory.get({row, col});
    }

    if (col == 0 && row > 0) {
        memory.put({row, col}, 80 + weightOnBackOf(row - 1, 0, pyramidHeight) * 0.5);
        return 80 + weightOnBackOf(row - 1, 0, pyramidHeight) * 0.5;
    } else if (col == row) {
        memory.put({row, col}, 80 + weightOnBackOf(row - 1, col - 1, pyramidHeight) * 0.5);
        return 80 + weightOnBackOf(row - 1, col - 1, pyramidHeight) * 0.5;
    } else {
        memory.put({row, col}, weightOnBackOf(row - 1, col - 1, pyramidHeight) * 0.5 + weightOnBackOf(row - 1, col, pyramidHeight) * 0.5 + 160);
        return weightOnBackOf(row - 1, col - 1, pyramidHeight) * 0.5 + weightOnBackOf(row - 1, col, pyramidHeight) * 0.5 + 160;
    }

}

/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */
    // SHOW_ERROR("This test is configured to always fail until you delete this line from\n         HumanPyramids.cpp. Once you have implemented memoization and want\n         to check whether it works correctly, remove the indicated line.");

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
