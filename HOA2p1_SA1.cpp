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

int main() {
    Fruit apple("Apple", 10, 7);
    Fruit banana("Banana", 10, 8);
    Vegetable broccoli("Broccoli", 60, 12);
    Vegetable lettuce("Lettuce", 50, 10);

    double total = 0;
    
    apple.printItem();
    total += apple.calculateSum();

    banana.printItem();
    total += banana.calculateSum();

    broccoli.printItem();
    total += broccoli.calculateSum();

    lettuce.printItem();
    total += lettuce.calculateSum();

    cout << "Total: PHP " << total << endl;

    return 0;
}