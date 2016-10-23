#include <cstdio>
#include <algorithm>
#define SIZE  13
#define RANGE 2
#define TYPE C

int arr[SIZE] = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0};
int ans[SIZE] = {0};

void a() {
    int record[RANGE] = {0};
    for (int i = 0; i < SIZE; i++)
        record[arr[i]]++;
    for (int i = 1; i < RANGE; i++)
        record[i] += record[i - 1];
    for (int i = SIZE - 1; i >= 0; i--) {
        ans[record[arr[i]] - 1] = arr[i];
        record[arr[i]]--;
    }
}

void b() {
    int l = 0, r = SIZE - 1;
    while (true) {
        while (arr[l] == 0) l++;
        while (arr[r] == 1) r--;
        if (l < r) std::swap(arr[l], arr[r]);
        else return;
    }
}

void c() {
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j >= 1; j--) {
            if (arr[j] < arr[j - 1]) std::swap(arr[j], arr[j - 1]);
        }
    }
}

void printAns() {
    #if TYPE == A
    for (int i = 0; i < SIZE; i++)
        printf("%d ", ans[i]);
    #else
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    #endif
    puts("");
}

int main() {
    #if TYPE == A
    a();
    #elif TYPE == B
    b();
    #elif TYPE == C
    c();
    #endif
    printAns();
    return 0;
}
