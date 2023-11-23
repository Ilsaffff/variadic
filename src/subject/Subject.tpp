#include "Subject.h"


template<typename T, typename... Args>
T Subject<T, Args...>::get_first_arg(T &first_arg, Args &...args) {
    return first_arg;
}

template<typename T, typename... Args>
T Subject<T, Args...>::sum(T &first_arg, Args &...args) {
    return first_arg + sum(args...);
}

template<typename T, typename... Args>
T Subject<T, Args...>::sum(T &last_arg) {
    return last_arg;
}