#ifndef VORTEX_ARRAY_H
#define VORTEX_ARRAY_H
#include <iostream>
#include <stdexcept>

namespace Vortex {
    template <typename T>

    class Array {
    private:
        T* data_{};
        int capacity_{0};
        int size_{0};

    public:
        explicit Array(const int capacity) : data_(new T[capacity]), capacity_(capacity) {}

        ~Array() {
            delete[] data_;
        }

        Array(const Array&) = delete;
        Array& operator=(const Array&) = delete;

        void pop() {
            if (size_ == 0) {
                throw std::out_of_range("Vortex::Array is empty");
            }
            --size_;
        }

        void push(const T& new_value) {
            if (this->size_ == this->capacity_) {
                throw std::out_of_range("Vortex::Array is already full");
            }
            data_[size_] = new_value;
            ++this->size_;
        }

        [[nodiscard]] T& operator[](int index) {
            return this->data_[index];
        }

        [[nodiscard]] const T& operator[](int index) const {
            return this->data_[index];
        }

        [[nodiscard]] T& at(int index) {
            if (index < 0 || index >= this->size_) {
                throw std::out_of_range("Vortex::Array at() index out of range");
            }
            return this->data_[index];
        }

        void remove() {
            if (this->size_ == 0) {
                throw std::out_of_range("Vortex::Array is empty");
            }
            --this->size_;
        }

        void insert(int index, const T& new_value) {
            if (this->size_ == this->capacity_) {
                throw std::out_of_range("Vortex::Array is full");
            }

            if (index < 0 || index > this->size_) {
                throw std::out_of_range("Vortex::Array insert index out of range");
            }

            for (int i{this->size_}; i > index; --i) {
                this->data_[i] = this->data_[i - 1];
            }
            this->data_[index] = new_value;
            ++this->size_;
        }

        void erase(int index) {
            if (index < 0 || index > this->size_) {
                throw std::out_of_range("Vortex::Array erase index out of range");
            }

            for (int i{index}; i < this->size_ - 1; ++i) {
                this->data_[i] = this->data_[i + 1];
            }
            --this->size_;
        }
        [[nodiscard]] int find(const T& value) const {
            for (int i{0}; i < this->size_; ++i) {
                if (this->data_[i] == value) return i;
            }
            return -1;
        }
        [[nodiscard]] int size() const { return this->size_; }
        [[nodiscard]] int capacity() const { return this->capacity_; }
        [[nodiscard]] bool empty() const { return this->size_ == 0; }
        [[nodiscard]] bool full() const { return this->size_ == capacity(); }

        void print() const {
            std::cout << "[";
            for (int i = 0; i < size_; ++i) {
                std::cout << data_[i];
                if (i < size_ - 1) std::cout << ", ";
            }
            std::cout << "]\n";
        }

        void reverse() {
            T temp{};
            int left{0};
            int right{this->size() - 1};

            while (left < right) {
                temp = data_[left];
                data_[left] = data_[right];
                data_[right] = temp;
                left++; --right;
            }
        }
    };
}

#endif
