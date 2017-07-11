// sliding window min and max O(n)

#include <queue>

int arr[];  // arreglo de valores
int n;      // tamaño del arreglo
int w;      // tamaño de la ventana

// G.front = max, S.front = min
deque<int> S(w), G(w);

// Process first window of size w
int i;
for (i = 0; i < w; i++) {
    while ((!S.empty()) && arr[S.back()] >= arr[i]) {
        S.pop_back();
    }

    while ((!G.empty()) && arr[G.back()] <= arr[i]) {
        G.pop_back();
    }

    G.push_back(i);
    S.push_back(i);
}

// max and min of first window
int max = arr[G.front()];
int min = arr[S.front()];

// Process rest of the Array elements
for (; i < n; i++) {
    while (!S.empty() && S.front() <= i - w) {
        S.pop_front();
    }
    while (!G.empty() && G.front() <= i - w) {
        G.pop_front();
    }

    while ((!S.empty()) && arr[S.back()] >= arr[i]) {
        S.pop_back();
    }
    while ((!G.empty()) && arr[G.back()] <= arr[i]) {
        G.pop_back();
    }

    G.push_back(i);
    S.push_back(i);

    int max = arr[G.front()];
    int min = arr[S.front()];
}