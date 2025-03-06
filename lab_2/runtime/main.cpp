#include <iostream>
#include "Util/RuntimeFramework.hpp"
int main() {
    Util::RuntimeFramework runtime;

    runtime.Initial();
    runtime.Render();

    while (runtime.GetState() != Util::RuntimeState::END) {
        runtime.Running();
        runtime.Render();
    }

    runtime.End();

    system("Pause");
}
