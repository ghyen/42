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
        unsigned int length() const {return len;};
        unsigned int size(void) cosnt {return val / sizeof(T);};
        Array(void) : val(NULL), len(0) {};
        Array(unsigned int n)
        {
            val = new T(sizof(T) * n);
            len = n;
        };
        Array(const Array &ref)
        {
            
            for (int i = 0; i < ref.len; i++)
            {

            }
        };
        Array &operator=(const Array& Array)
        {

        };
        Array &operator[](unsigned int n)
        {

        };
        const Array &operator[](const unsigned int n)
        {

        };
        ~Array(void);
}

#include "Array.tpp"