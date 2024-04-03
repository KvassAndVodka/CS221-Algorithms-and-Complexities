#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v) {
        valuePerWeight = static_cast<double>(value) / weight;
    }
};

bool compare(Item a, Item b) {
    return a.valuePerWeight > b.valuePerWeight;
}

void fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    cout << "Items: (weight, value) -";
    for (const auto& item : items) {
        cout << " (" << item.weight << ", " << item.value << ")";
    }
    cout << endl;
    cout << "Knapsack weight limit: " << capacity << endl;

    cout << "Maximum value: ";
    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            cout << "Take " << item.weight << "/" << item.weight << " of item " << item.weight << ", ";
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            double fraction = static_cast<double>(capacity - currentWeight) / item.weight;
            cout << "Take " << fraction * item.weight << "/" << item.weight << " of item " << item.weight << " and ";
            totalValue += item.valuePerWeight * (capacity - currentWeight);
            break;
        }
    }

    cout << "all of item " << items[0].weight << endl;
    cout << "Maximum value: " << totalValue << endl;
}

int main() {
    vector<Item> items = {{2, 60}, {3, 90}, {4, 100}};
    int knapsackWeightLimit = 5;

    fractionalKnapsack(items, knapsackWeightLimit);

    return 0;
}
