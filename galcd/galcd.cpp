
#include <iostream>
#include <string>

#include "AorusLCDController.h"

void usage()
{
    std::cerr << "Usage: galcd [on|off]\n";
}

int main(int argc, char* argv[])
{
    AorusLCDController lcd{};
    
    if (argc != 2)
    {
        usage();
        return 1;
    }

    bool desired;
    if (std::string{ "on" } == argv[1])
        desired = true;
    else if (std::string{ "off" } == argv[1])
        desired = false;
    else {
        usage();
        return 2;
    }

    uint32_t result = lcd.SetLCDStatus(desired);
    
    if (result != 0)
    {
        std::cout << "Failed. Result:" << std::hex << result << "\n";
        return 3;
    }

    return 0;
}
