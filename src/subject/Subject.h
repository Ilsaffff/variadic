#pragma once

#include <tuple>
#include <vector>

template<typename T>
class Subject {
public:
    Subject(){};

    template<typename ... Args>
    T sum(T &first_arg, Args& ...);

    T sum(T &first_arg);
};

template<typename T>
T Subject<T>::sum(T &first_arg) {
    return first_arg;
}


template<typename T>
template<typename ...Args>
T Subject<T>::sum(T &first_arg, Args &...args) {
    return first_arg + sum(args...);
}
