#include <dlfcn.h>
#include <cstdint>
#include <iostream>

int g_marker = 42;

int main() {
    Dl_info module{};
    if (dladdr(&g_marker, &module) == 0) {
        std::cerr << "Could not find the module.\n";
        return 1;
    }

    auto base = reinterpret_cast<std::uintptr_t>(module.dli_fbase);
    auto address = reinterpret_cast<std::uintptr_t>(&g_marker);
    auto rva = address - base;

    std::cout << std::hex << std::showbase;
    std::cout << "Module start: " << base << '\n';
    std::cout << "Variable VA:  " << address << '\n';
    std::cout << "RVA:          " << rva << '\n';
    std::cout << "Rebuilt VA:   " << base + rva << '\n';
    std::cout << std::dec << "Value:        " << g_marker << '\n';
}
