#include "src/wrapper/Wrapper.h"
#include "src/engine/Engine.h"


int main() {
    // Type of data: int
    Subject<int, int> subj_int;
    Wrapper<int, int> wrapper(&subj_int, &Subject<int, int>::get_first_arg, {{"arg1", 1},
                                                                             {"arg2", 3}});
    Wrapper<int, int> wrapper_sum(&subj_int, &Subject<int, int>::sum, {{"arg1", 1},
                                                                       {"arg2", 3}});
    Engine<int, int> engine;
    engine.register_command(wrapper, "first_arg");
    engine.register_command(wrapper_sum, "sum_int");
    std::cout << engine.execute("first_arg", {{"arg1", 5},
                                              {"arg2", 6}}) << "\n"; // Return 5
    std::cout << engine.execute("sum_int", {{"arg1", 5},
                                            {"arg2", 6}}) << "\n"; // Return 11

    // Type of data: string
    Subject<std::string, std::string> subj_str;
    Wrapper<std::string, std::string> wrapper_str(&subj_str,
                                                  &Subject<std::string, std::string>::sum,
                                                  {{"arg1", "Hello, "},
                                                   {"arg2", "World"}});
    Engine<std::string, std::string> engine_str;
    engine_str.register_command(wrapper_str, "sum_str");
    std::cout << engine_str.execute("sum_str", {{"arg1", "Hello, "},
                                                {"arg2", "it's my lab :)"}});
    return 0;
}
