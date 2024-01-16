#pragma once

template <typename T>

void swap(T &n1, T &n2)
{
    T tmp = n1;
    n1 = n2;
    n2 = tmp;
}

template <typename T>
const T& min(T &n1, T &n2) {return n1 >= n2 ? n2 : n1;}

template <typename T>
const T& max(T &n1, T &n2) {return n1 <= n2 ? n2 : n1;}
