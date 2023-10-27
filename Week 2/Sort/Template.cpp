#include "bits/stdc++.h"
#include "stdexcept"
using namespace std;

template<typename T> 

class DynamicArray {
private:
    T* a;
    int n, size;
public:
    DynamicArray(int n) {
        this->n = n;
        this->size = 0;
        a = new T[n];
    }

    ~DynamicArray() {
        delete[] a;
    }

    T at(int i) {
        return a[i-1];
    }

    int size() const {
        return size;
    }

    // Thêm một phần tử vào cuối mảng
    void pushBack(const T& value) {
        if (size == capacity) {
            // Nếu mảng đầy, tạo một mảng mới lớn hơn và sao chép dữ liệu từ mảng cũ
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    //cai dat toan tu truy van []
    // Toán tử truy vấn []
    T& operator[](int i) {
        if (i >= 0 && i < size) {
            return a[i];
        }
        else throw out_of_range("Index out of range");
    }

    //Toán tử truy vấn [] const cho việc sử dụng đối tượng const
    const T& operator[] (int i) {
        if (i < 0 | i >= size) {
            throw out_of_range("Index out of range");
        }
        else return a[i];
    }
};

int main() {
    // Sử dụng lớp DynamicArray với kiểu dữ liệu int
    DynamicArray<int> intArray(5);

    intArray.pushBack(1);
    intArray.pushBack(2);
    intArray.pushBack(3);

    cout << "Size of integer array: " << intArray.size() << endl;

    // Truy cập phần tử bằng toán tử []
    std::cout << "Element at index 1: " << intArray[1] << std::endl;

    return 0;
}

/*
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* data;      // Mảng chứa các phần tử kiểu T
    int capacity; // Số lượng phần tử mảng có thể chứa
    int size;     // Số lượng phần tử hiện tại trong mảng

public:
    // Khởi tạo một mảng động với số lượng phần tử ban đầu là capacity
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new T[capacity];
    }

    // Hàm hủy giải phóng bộ nhớ động đã cấp cho mảng
    ~DynamicArray() {
        delete[] data;
    }

    // Truy vấn phần tử thứ i của mảng
    T at(int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    // Trả về kích thước của mảng
    int size() const {
        return size;
    }

    // Thêm một phần tử vào cuối mảng
    void pushBack(const T& value) {
        if (size == capacity) {
            // Nếu mảng đầy, tạo một mảng mới lớn hơn và sao chép dữ liệu từ mảng cũ
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    // Toán tử truy vấn []
    T& operator[](int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    // Toán tử truy vấn [] const cho việc sử dụng đối tượng const
    const T& operator[](int i) const {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }
};

int main() {
    // Sử dụng lớp DynamicArray với kiểu dữ liệu int
    DynamicArray<int> intArray(5);

    intArray.pushBack(1);
    intArray.pushBack(2);
    intArray.pushBack(3);

    std::cout << "Size of integer array: " << intArray.size() << std::endl;

    // Truy cập phần tử bằng toán tử []
    std::cout << "Element at index 1: " << intArray[1] << std::endl;

    return 0;
}
*/