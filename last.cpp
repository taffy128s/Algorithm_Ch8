#include <cstdio>
#include <algorithm>
#define SIZE  12
#define RANGE 10

int arr[SIZE + 1] = {0, 9, 9, 1, 3, 1, 4, 5, 7, 8, 2, 1, 10};

void counting_sort_not_stable() {
    int record[RANGE + 1] = {0};
    int place[RANGE + 1] = {0};
    for (int i = 1; i <= SIZE; i++)
        record[arr[i]]++;
    for (int i = 1; i <= RANGE; i++)
        record[i] += record[i - 1];
    int i = 1;
    while (i <= SIZE) {
        int left_bound = record[arr[i] - 1] + 1, right_bound = record[arr[i]];
        if (left_bound <= i && i <= right_bound) i++;
        else std::swap(arr[i], arr[left_bound + place[arr[i]]++]);
    }
}

int main() {
    counting_sort_not_stable();
    for (int i = 1; i <= SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
    return 0;
}
