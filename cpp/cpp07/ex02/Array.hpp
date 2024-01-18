#pragma once
#include <cstddef>
#include <iostream>
#include <exception>

template <typename T>

class Array {
    private:
        T *val;
        unsigned int len;

    public:
        unsigned int size(void) const {return len;};
        Array(void) : val(NULL), len(0) {};
        Array(unsigned int n) : val(new T[n]), len(n) {};
        ~Array(void) {delete[] val;};

        Array(const Array &ref) : len(ref.len)
        {
            val = new T[len];
            for (unsigned int i = 0; i < len; i++)
                val[i] = ref.val[i];
        };
        Array& operator=(const Array& ref)
        {
            this->~Array();
            new (this) Array(ref);
            return *this;
        };
        T& operator[](unsigned int n)
        {
            if (n >= len)
                throw std::exception();
            return val[n];
        };
        const T& operator[](const unsigned int n) const
        {
            if (n >= len)
                throw std::exception();
            return val[n];
        };
};
