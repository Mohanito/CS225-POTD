#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>
#include <vector>

class Queue {
    public:
        Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        ~Queue();
        std::vector<int> v;
};

#endif
