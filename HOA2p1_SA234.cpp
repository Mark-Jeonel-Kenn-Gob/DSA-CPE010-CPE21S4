#include <iostream>
#include <cstring>

using namespace std;

class Item {
protected:
    char* name;
    double price;
    int quantity;

public:
    Item(const char* itemName, double itemPrice, int itemQuantity) {
        name = new char[strlen(itemName) + 1];
        strcpy(name, itemName);
        price = itemPrice;
        quantity = itemQuantity;
    }

    Item(const Item& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        price = other.price;
        quantity = other.quantity;
    }

    Item& operator=(const Item& other) {
        if (this == &other) return *this;

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        price = other.price;
        quantity = other.quantity;

        return *this;
    }

    virtual ~Item() {
        delete[] name;
    }

    virtual double calculateSum() const {
        return price * quantity;
    }

    virtual void printItem() const {
        cout << name << ": PHP " << price << " x" << quantity << endl;
    }

    const char* getName() const {
        return name;
    }
};

class Fruit : public Item {
public:
    Fruit(const char* fruitName, double fruitPrice, int fruitQuantity)
        : Item(fruitName, fruitPrice, fruitQuantity) {}

    ~Fruit() {}
};

class Vegetable : public Item {
public:
    Vegetable(const char* vegName, double vegPrice, int vegQuantity)
        : Item(vegName, vegPrice, vegQuantity) {}

    ~Vegetable() {}
};

double TotalSum(Item* groceryList[], int size) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += groceryList[i]->calculateSum();
    }
    return total;
}

void DeleteItem(Item* groceryList[], int& size, const char* itemName) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(groceryList[i]->getName(), itemName) == 0) {
            delete groceryList[i];  
            for (int j = i; j < size - 1; ++j) {
                groceryList[j] = groceryList[j + 1];
            }
            groceryList[size - 1] = nullptr; 
            --size;
            cout << itemName << " has been deleted from the grocery list." << endl;
            return;
        }
    }
    cout << itemName << " not found in the grocery list." << endl;
}

int main() {
    const int MAX_ITEMS = 4;
    Item* groceryList[MAX_ITEMS] = {
        new Fruit("Apple", 10, 7),
        new Fruit("Banana", 10, 8),
        new Vegetable("Broccoli", 60, 12),
        new Vegetable("Lettuce", 50, 10)
    };

    int size = MAX_ITEMS;

    cout << "Jenna's Grocery List:" << endl;
    for (int i = 0; i < size; ++i) {
        groceryList[i]->printItem();
    }

    double total = TotalSum(groceryList, size);
    cout << "Total Sum: PHP " << total << endl;

    DeleteItem(groceryList, size, "Lettuce");

    cout << "Updated Grocery List:" << endl;
    for (int i = 0; i < size; ++i) {
        groceryList[i]->printItem();
    }

    for (int i = 0; i < size; ++i) {
        delete groceryList[i];
    }

    return 0;
}