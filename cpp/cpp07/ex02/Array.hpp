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

        Array(const Array &ref) : len(ref.len), val(new T[ref.len])
        {
            for (unsigned int i = 0; i < ref.len; i++)
                this[i] = ref[i];
        };
        Array& operator=(const Array& ref)
        {
            if (this != &ref)
            {
                len = ref.len;
                //if (ref.len != len)
                //{
                //    delete [] val;
                //    val = new T[ref.len];
                //}
                std::cout << "?? " << std::endl;
                for (unsigned int i = 0; i < len; i++)
                    val[i] = ref.val[i];
            }
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
