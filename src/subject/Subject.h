#pragma once

#include <tuple>
#include <vector>

template<typename T, typename... Args>
class Subject {
public:
    Subject() = default;

    T get_first_arg(T &first_arg, Args &...args);

    T sum(T &first_arg, Args &...args);

    T sum(T &last_arg);

};

#include "Subject.tpp"