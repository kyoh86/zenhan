#include <iostream>
#include <string>
#include <windows.h>
#include <imm.h>

int main(int argc, char** argv)
{
    constexpr LPARAM IMC_GETOPENSTATUS = 5;
    constexpr LPARAM IMC_SETOPENSTATUS = 6;

    HWND hwnd = GetForegroundWindow();
    if (!hwnd) {
        std::cerr << "Failed to get foreground window.\n";
        return 0;
    }

    HWND ime = ImmGetDefaultIMEWnd(hwnd);
    if (!ime) {
        std::cerr << "Failed to get default IME window.\n";
        return 0;
    }

    LRESULT stat = SendMessage(ime, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);
    bool compatible_mode = false;
    bool should_change_status = false;
    LPARAM new_stat = 0;

    if (argc >= 2) {
        std::string arg = argv[1];
        if (arg.find("--compat") != std::string::npos) {
            compatible_mode = true;
            if (argc >= 3) {
                try {
                    new_stat = std::stoi(argv[2]);
                    should_change_status = true;
                } catch (...) {
                    std::cerr << "Invalid integer value for new status.\n";
                }
            }
        } else {
            try {
                new_stat = std::stoi(arg);
                should_change_status = true;
            } catch (...) {
                std::cerr << "Invalid integer value for new status.\n";
            }
        }
    }

    if (should_change_status) {
        SendMessage(ime, WM_IME_CONTROL, IMC_SETOPENSTATUS, new_stat);
    }

    std::cout << static_cast<long long>(stat) << "\n";

    return compatible_mode ? 0 : static_cast<int>(stat);
}
