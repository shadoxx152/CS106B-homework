#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

#define defaultCapcity 10

using namespace std;


RBQueue::RBQueue() {
    elements = new int[defaultCapcity];
    capacity = defaultCapcity;
    head = 0;
    tail = 0;
}

RBQueue::~RBQueue() {
    delete[] elements;
}

void RBQueue::enqueue(int elem) {
    elements[tail] = elem;
    tail = (tail + 1) % capacity;
}

int RBQueue::dequeue() {
    int headData = elements[head];
    head = (head + 1) % capacity;
    return headData;
}

int RBQueue::peek() const{
    return elements[head];
}

bool RBQueue::isEmpty() const{
    return head == tail;
}

bool RBQueue::isFull() const{
    return this->size() == capacity;
}

int RBQueue::size() const{
    if (isEmpty()) {
        return 0;
    }

    if (head < tail) {
        return tail - head + 1;
    }

    return capacity - (head - tail - 1);
}

ostream& operator<<(ostream& out, const RBQueue& queue) {
    out << "{";

    int index = queue.head;

    if (!queue.isEmpty()) {
        out << queue.elements[index];
        while (index <= queue.tail) {
            out << ", " << queue.elements[index];
            index = (index + 1) % queue.capacity;
        }
    }

    out << "}";
    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout"){
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}
