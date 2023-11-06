#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

void sleep_for_seconds(float seconds) {
    #ifdef _WIN32
    Sleep(static_cast<DWORD>(seconds * 1000));
    #else
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(seconds * 1000)));
    #endif
}

int main() {
    int min;
    cout << "Masukkan jumlah menit : ";
    cin >> min;

    int sec = 60 * min;
    for(int i = 0;i < sec;i++){
        cout << i << "/" << sec << "  ";
    sleep_for_seconds(1.0f);
    }
    cout << "Mematikan komputer...\n";
    #ifdef _WIN32
    system("shutdown /s /t 1");
    #else
    system("poweroff");
    #endif

    return 0;
}
