#pragma once

#include "../wrapper/Wrapper.h"

template<typename T, typename ...Args>
class Engine {
public:
    Engine() = default;

    void register_command(Wrapper<T, Args...> &wrapper, const std::string &command_name);

    T execute(const std::string &command_name,
              std::unordered_map<std::string, T> &&new_args);

public:
    std::map<std::string, Wrapper<T, Args...>> commands;
};

#include "Engine.tpp"