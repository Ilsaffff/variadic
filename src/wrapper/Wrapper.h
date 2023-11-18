#pragma once


#include <tuple>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include "../subject/Subject.h"


template<typename T, typename ... Args>
class Wrapper {
public:
    Wrapper() = default;


    Wrapper(Subject<T> *new_subject, T (Subject<T>::*new_func)(T&, Args&...),
            std::initializer_list<std::tuple<std::string, T>> &&new_args);


private:
    Subject<T> *subject;

    T (Subject<T>::*func)(T&, Args&...);

    std::map<std::string, T> args;

    std::tuple<Args...> tuple_args;

};

template<typename T, typename... Args>
Wrapper<T, Args...>::Wrapper(Subject<T> *new_subject, T (Subject<T>::*new_func)(T &, Args&...),
                             std::initializer_list<std::tuple<std::string, T>> &&new_args):
        func(new_func), subject(new_subject) {
        }



