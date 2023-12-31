#include "Engine.h"

template<typename T, typename... Args>
T Engine<T, Args...>::execute(const std::string &command_name,
                              std::unordered_map<std::string, T> &&new_args) {
    if (commands.find(command_name) == commands.end()){
        throw std::runtime_error("The command not registered");
    }
    return commands[command_name].run_func(std::move(new_args));
}

template<typename T, typename ...Args>
void Engine<T, Args...>::register_command(Wrapper<T, Args...> &wrapper,
                                          const std::string &command_name) {
    commands[command_name] = wrapper;
}