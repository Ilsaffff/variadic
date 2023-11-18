#include "src/wrapper/Wrapper.h"
#include "src/engine/Engine.h"


int main() {
    auto subj = Subject<int>();
    Wrapper<int> wrapper(&subj, &Subject<int>::sum,
                         {{"arg1", 0},
                          {"arg2", 0}});
    return 0;
}
