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

    public:
        Next(T* ptr) : rowPtr(ptr) {}

        T& operator[](size_t col) {
            return rowPtr[col];
        }
    };
    
    class ConstNext {
        private:
            const T* rowPtr;

        public:
        ConstNext(const T* ptr) : rowPtr(ptr) {}

            const T& operator[](size_t col) const {
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

    Next operator[](size_t row) {
        if (row >= rows) {
            throw std::out_of_range("Error(Range)");
        }
        return Next(arr[row]);
    }
    ConstNext operator[](size_t row) const {
            if (row >= rows) {
                throw std::out_of_range("Row index out of bounds");
            }
            return ConstProxy(arr[row]);
        }
};

int main() {
    auto test = table<int>(3, 4);
    
    test[0][0] = 4;
    
    std::cout << test[0][0];

    return 0;
}


