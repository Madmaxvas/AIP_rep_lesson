#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>

class IntArray {
private:
    int* a;
    size_t k;

public:
    IntArray() : a(nullptr), k(0) {}

    IntArray(size_t size) : a(new int[size]), k(size) {
        for (size_t i = 0; i < k; ++i) {
            a[i] = 0;
        }
    }

    ~IntArray() {
        delete[] a;
    }

    IntArray(const IntArray& other) : a(nullptr), k(0) {
        if (other.k > 0) {
            a = new int[other.k];
            k = other.k;
            for (size_t i = 0; i < k; ++i) {
                a[i] = other.a[i];
            }
        }
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this;
        delete[] a;
        
        k = other.k;
        if (k > 0) {
            a = new int[k];
            for (size_t i = 0; i < k; ++i) {
                a[i] = other.a[i];
            }
        } else {
            a = nullptr;
        }
        return *this;
    }

    size_t size() const noexcept {
        return k;
    }

    int& operator[](size_t index) {
        return a[index];
    }

    int operator[](size_t index) const {
        return a[index];
    }
};

class IntMatrix {
private:
    IntArray data;
    size_t rows;
    size_t cols;

public:
    IntMatrix() : rows(0), cols(0) {}

    void loadFromFile(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            exit(1);
        }

        if (!(file >> rows >> cols)) exit(1);
        
        data = IntArray(rows * cols);

        for (size_t i = 0; i < rows * cols; ++i) {
            if (!(file >> data[i])) exit(1);
        }
        file.close();
    }

    void print() const {
        if (rows == 0 || cols == 0) return;
        for (size_t i = 0; i < rows; ++i
