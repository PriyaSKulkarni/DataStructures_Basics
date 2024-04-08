#include <iostream>

class DynamicArray {
private:
    int *data;
    int capacity;
    int size;

public:
    // Constructor
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor
    DynamicArray(const DynamicArray &other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    DynamicArray& operator=(const DynamicArray &other) {
        if (this != &other) {
            // Free existing memory
            delete[] data;

            // Copy values
            capacity = other.capacity;
            size = other.size;

            // Allocate new memory
            data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Add element to the end of the array
    void push_back(int value) {
        if (size >= capacity) {
            // Increase capacity if needed
            if (capacity == 0) capacity = 1;
            else capacity *= 2;

            int *newData = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    // Get element at index
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds\n";
            exit(1);
        }
        return data[index];
    }

    // Get size of the array
    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
