#include <stdio.h>
#include <vector>
using namespace std;

struct MaxHeap {
    vector<int> container;

    MaxHeap() {
        container.push_back(0);
    }

    MaxHeap(vector<int> v) {
        container.push_back(0);
        vector<int>::iterator iter;
        for (iter = v.begin(); iter != v.end(); iter++) {
            container.push_back(*iter);
        }
        for (int i = parent(v.size()); i >= 1; i& 1 ? i-- : i = parent(i)) {
            down_heap(i);
        }
    }

    int parent(int index) {
        return index >> 1;
    }

    int left(int index) {
        return index << 1;
    }

    int right(int index) {
        return (index << 1) + 1;
    }

    void push(int element) {
        container.push_back(element);
        up_heap(container.size() - 1);
    }

    void up_heap(int index) {
        if (parent(index) > 0 && container[parent(index)] < container[index]) {
            int tmp = container[index];
            container[index] = container[parent(index)];
            container[parent(index)] = tmp;
            up_heap(parent(index));
        }
    }

    void pop() {
        container[1] = container[container.size() - 1];
        container.pop_back();
        down_heap(1);
    }

    void down_heap(int index) {
        int max = index;
        int left = MaxHeap::left(index);
        int right = MaxHeap::right(index);
        if (left < container.size() && container[left] > container[max]) {
            max = left;
        }
        if (right < container.size() && container[right] > container[max]) {
            max = right;
        }
        if (max != index) {
            int tmp = container[index];
            container[index] = container[max];
            container[max] = tmp;
            down_heap(max);
        }
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    MaxHeap m(a);
    for (auto n : m.container) {
        printf("%d ", n);
    }
    printf("\n");
    m.push(7);
    for (auto n : m.container) {
        printf("%d ", n);
    }
    printf("\n");
    m.push(5);
    for (auto n : m.container) {
        printf("%d ", n);
    }
    printf("\n");
    m.pop();
    for (auto n : m.container) {
        printf("%d ", n);
    }
}