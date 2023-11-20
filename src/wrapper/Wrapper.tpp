#include "Wrapper.h"

template<typename T, typename ...Args>
Wrapper<T, Args...>::Wrapper(Subject<T, Args...> *new_subject,
                             T (Subject<T, Args...>::*new_func)(T &, Args &...),
                             std::unordered_map<std::string, T> &&default_args):
        func(new_func), subject(new_subject), default_args(default_args) {};

template<typename T, typename... Args>
template<std::size_t... Indices>
std::tuple<T, Args...> Wrapper<T, Args...>::fill_tuple_helper(const std::vector<T> &values,
                                                              std::index_sequence<Indices...>) {
    return std::make_tuple(values[Indices]...);
}

template<typename T, typename... Args>
std::tuple<T, Args...> Wrapper<T, Args...>::fill_tuple(const std::vector<T> &values) {
    return fill_tuple_helper(values, std::index_sequence_for<T, Args...>());
}


template<typename T, typename... Args>
T Wrapper<T, Args...>::run_func(std::unordered_map<std::string, T> &&current_args) {
    /**
     * Method validates args, fill a tuple and the tuple enter to the target func
     */
    auto values = validate_args(current_args);
    auto tuple = fill_tuple(values);
    return std::apply([this](T &first_arg, Args &... args) {
        return (subject->*func)(first_arg, args...);
    }, tuple);
}


template<typename T, typename... Args>
std::vector<T>
Wrapper<T, Args...>::validate_args(std::unordered_map<std::string, T> &current_args) {
    /** Method find difference args between default and received from user and return valid args
    */
    std::vector<T> values;
    std::unordered_map<std::string, T> target_args;
    for (const auto &default_arg: default_args) {
        auto it = current_args.find(default_arg.first);
        if (it != current_args.end()) {
            target_args[it->first] = it->second;
        } else {
            target_args[default_arg.first] = default_arg.second;
        }
    }

    for (const auto &arg: target_args) {
        values.push_back(arg.second);
    };
    return values;
}
