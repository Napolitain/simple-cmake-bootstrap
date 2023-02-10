//
// Created by Maxime Boucher on 14/01/2023.
//

#ifndef CMAKE_TEST_STATISTICS_HPP
#define CMAKE_TEST_STATISTICS_HPP

#include <ostream>

namespace statistics {

    /**
     * Simple vector class
     * @tparam T
     */
    template<typename T>
    class vector {
        T *data;
        int size = 0;
        int capacity = 0;

    public:
        vector() {
            data = new T[0];
        }

        /**
         * Initialize a vector with a given size and random integers between 1 and 1000
         */
        explicit vector(int size) {
            data = new T[size];
            this->size = size;
            this->capacity = size;
            for (int i = 0; i < size; i++) {
                data[i] = rand() % 1000 + 1;
            }
        }

        /**
         * Copy constructor
         */
        vector(const vector &other) {
            this->size = other.size;
            this->capacity = other.capacity;
            this->data = new T[other.size];
            for (int i = 0; i < other.size; i++) {
                this->data[i] = other.data[i];
            }
        }

        /**
         * Push back an element to the vector
         * if vector is full, double the capacity
         * else add the element to the end of the vector
         * @param element
         */
        void push_back(T element) {
            if (size == capacity) {
                capacity *= 2;
                T *newData = new T[capacity];
                for (int i = 0; i < size; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[size] = element;
            size++;
        }

        /**
         * Sort the vector using bubble sort
         */
        void bubbleSort() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (data[j] > data[j + 1]) {
                        T temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
        }

        /**
         * Sort the vector using quicksort
         */
        void quickSort() {
            quickSort(0, size - 1);
        }

        /**
         * Sort the vector using quicksort
         * @param left
         * @param right
         */
        void quickSort(int left, int right) {
            int i = left;
            int j = right;
            T pivot = data[(left + right) / 2];
            while (i <= j) {
                while (data[i] < pivot) {
                    i++;
                }
                while (data[j] > pivot) {
                    j--;
                }
                if (i <= j) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                    i++;
                    j--;
                }
            }
            if (left < j) {
                quickSort(left, j);
            }
            if (i < right) {
                quickSort(i, right);
            }
        }

        /**
         * Sort the vector using merge sort
         */
        void mergeSort() {
            mergeSort(0, size - 1);
        }

        /**
         * Sort the vector using merge sort
         * @param left
         * @param right
         */
        void mergeSort(int left, int right) {
            if (left < right) {
                int middle = (left + right) / 2;
                mergeSort(left, middle);
                mergeSort(middle + 1, right);
                merge(left, middle, right);
            }
        }

        /**
         * Merge two sorted subarrays
         * @param left
         * @param middle
         * @param right
         */
        void merge(int left, int middle, int right) {
            int i = left;
            int j = middle + 1;
            int k = 0;
            T *temp = new T[right - left + 1];
            while (i <= middle && j <= right) {
                if (data[i] < data[j]) {
                    temp[k] = data[i];
                    i++;
                } else {
                    temp[k] = data[j];
                    j++;
                }
                k++;
            }
            while (i <= middle) {
                temp[k] = data[i];
                i++;
                k++;
            }
            while (j <= right) {
                temp[k] = data[j];
                j++;
                k++;
            }
            for (int i = left; i <= right; i++) {
                data[i] = temp[i - left];
            }
            delete[] temp;
        }

        /**
         * Print the vector as follows : [x1, x2, x3, ..., xn]
         * @param os
         * @param vector
         * @return ostream
         */
        friend std::ostream &operator<<(std::ostream &os, const vector &vector) {
            os << "[";
            for (int i = 0; i < vector.size; i++) {
                os << vector.data[i];
                if (i != vector.size - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        /**
         * Returns the median of the vector
         * @return median
         * @throws std::runtime_error if vector is empty
         */
        T median() {
            if (size == 0) {
                throw std::runtime_error("Vector is empty");
            }
            if (size % 2 == 0) {
                return (data[size / 2] + data[size / 2 - 1]) / 2;
            } else {
                return data[size / 2];
            }
        }

    };

    /**
     * Compute the mean of a vector
     * @tparam T type of the vector
     * @param data vector
     * @return mean
     */
    template<typename T>
    float mean(T &data) {
        float sum = 0;
        for (auto &i: data) {
            sum += i;
        }
        return sum / data.size();
    }

}

#endif //CMAKE_TEST_STATISTICS_HPP
