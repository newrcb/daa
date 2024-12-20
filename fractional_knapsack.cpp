#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int value, weight;
    double ratio;
    Item(int v = 0, int w = 0) : value(v), weight(w), ratio((double)v / w) {}
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
double fractionalKnapsack(int W, int n, Item items[]) {
    sort(items, items + n, compare);
    double maxValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return maxValue;
}
int main() {
        int n, capacity;
        cout << "Enter the number of items: ";
        cin >> n;
        Item items[n];
        cout << "Enter the items (value weight):" << endl;
        for (int i = 0; i < n; ++i) {
            int value, weight;
            cin >> value >> weight;
            items[i] = Item(value, weight);
        }
        cout << "Enter the knapsack capacity: ";
        cin >> capacity;
        cout << "Maximum value = " << fractionalKnapsack(capacity, n, items) << endl;
    return 0;
}
