#include <iostream>

template <typename T>
class table {
private:
    T** arr;
    size_t rows;
    size_t cols;

public:
    class Next {
    private:
        T* rowPtr;
        size_t rowSize;

    public:
        Next(T* ptr, size_t size) : rowPtr(ptr), rowSize(size) {}

        T& operator[](size_t col) {
            if (col >= rowSize || col < 0) {
                throw ("Error");
            }
            return rowPtr[col];
        }
    };
    
    class ConstNext {
    private:
        const T* rowPtr;
        size_t rowSize;

    public:
        ConstNext(const T* ptr, size_t size) : rowPtr(ptr), rowSize(size) {}

        const T& operator[](size_t col) const {
            if (col >= rowSize || col < 0) {
                throw ("Error");
            }
            return rowPtr[col];
        }
    };

    table(size_t numRows, size_t numCols)
        : rows(numRows), cols(numCols) {
        arr = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
        }
    }

    ~table() {
        for (size_t i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    table& operator=(const table&) = delete;

    table(const table&) = delete;
    
    table(table&& other) noexcept
        : arr(other.arr), rows(other.rows), cols(other.cols) {
        other.arr = nullptr;
        other.rows = 0;
        other.cols = 0;
    }

    table& operator=(table&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < rows; ++i) {
                delete[] arr[i];
            }
            delete[] arr;

            arr = other.arr;
            rows = other.rows;
            cols = other.cols;

            other.arr = nullptr;
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    Next operator[](size_t row) {
        if (row >= rows) {
            throw ("Error");
        }
        return Next(arr[row], cols);
    }
    
    ConstNext operator[](size_t row) const {
        if (row >= rows) {
            throw ("Error");
        }
        return ConstNext(arr[row], cols);
    }
};

int main() {
    auto test = table<int>(3, 4);
    
    test[0][0] = 4;
    
    std::cout << test[0][0];

    return 0;
}

