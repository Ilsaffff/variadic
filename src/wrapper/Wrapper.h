#pragma once

#include <tuple>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include "variant"
#include "unordered_map"
#include "../subject/Subject.h"


template<typename T, typename ...Args>
class Wrapper {
public:
    Wrapper() = default;

    Wrapper(Subject<T, Args...> *new_subject, T (Subject<T, Args...>::*new_func)(T &, Args &...),
            std::unordered_map<std::string, T> &&default_args);

    T run_func(std::unordered_map<std::string, T> &&current_args);


private:
    Subject<T, Args...> *subject;

    T (Subject<T, Args...>::*func)(T &, Args &...);

    std::unordered_map<std::string, T> default_args;


    template<std::size_t... Indices>
    std::tuple<T, Args...>
    fill_tuple_helper(const std::vector<T> &values, std::index_sequence<Indices...>);

    std::tuple<T, Args...> fill_tuple(const std::vector<T> &values);

    std::vector<T> validate_args(std::unordered_map<std::string, T> &current_args);

};


#include "Wrapper.tpp"