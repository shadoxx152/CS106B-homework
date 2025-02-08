#include <iostream>
#include "testing/SimpleTest.h"
#include "console.h"
#include "vector.h"
using namespace std;

struct BackpackItem {
    int survivalValue;  // You can assume this value will always >= 0
    int weight;         // You can assume this value will always >= 0
};

int fillBackpackHelper(Vector<BackpackItem>& items, int capacityRemaining, int curValue, int index) {
    /* Base Case: If there is no more capacity in the backpack to hold things,
     * then we can no longer fit any more value in.
     */
    if (capacityRemaining < 0) {
        return 0;
    }
    /* Base Case: If we have run out of items to consider, then the best value we
     * can get is what we've built up so far.
     */
    else if (index == items.size()) {
        return curValue;
    }else {
        /* Choose: Select an item to decide whether to bring along or not.
         */
        BackpackItem curItem = items[index];

        /* Explore: Try including the item and not including it, and keep track
         * of the best possible value in each case. */
        int bestValueWithout = fillBackpackHelper(items,
                                                  capacityRemaining,
                                                  curValue,
                                                  index + 1);

        int bestValueWith = fillBackpackHelper(items,
                                               capacityRemaining - curItem.weight,
                                               curValue + curItem.survivalValue,
                                               index + 1);

        /* Unchoose: No explicit unchoose necessary since no changes to data
         * structures have been made.
         */

        /* The final value we return is the best of the two options we tried. */
        return max(bestValueWith, bestValueWithout);
    }
}

int fillBackpack(Vector<BackpackItem>& items, int targetWeight) {
    return fillBackpackHelper(items, targetWeight, 0, 0);
}
PROVIDED_TEST("Simple knapsack examples.") {
    int targetWeight = 18;
    Vector<BackpackItem> items = {
        {12, 4},
        {10,6},
        {8, 5},
        {11, 7},
        {14, 3},
        {7, 1},
        {9, 6}
    };
    EXPECT_EQUAL(fillBackpack(items, targetWeight), 44);

    targetWeight = 25;
    items = {
       {5, 6},
       {20, 15},
       {3, 11},
       {50, 12},
       {5, 6},
       {4, 11},
       {15, 13},
       {12, 7},
       {6, 17},
       {7, 13}
    };

    EXPECT_EQUAL(fillBackpack(items, targetWeight), 67);

    targetWeight = 5;
    items = {
       {3, 2},
       {4, 3},
       {5, 4},
       {6, 5}
    };

    EXPECT_EQUAL(fillBackpack(items, targetWeight), 7);
}
