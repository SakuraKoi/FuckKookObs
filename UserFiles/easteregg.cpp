#include "easteregg.h"

#include <chrono>
#include <random>

void showRollingEasterEgg(HWND kookHwnd) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distributionDouble(0.0, 1.0);

    auto result = distributionDouble(generator);
    if (result > 0.3)
        return;
    for (int i = 0; i < 3; i++) {
        SetWindowText(kookHwnd, L"KOOK | 产品经理你马");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 品经理你马在");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 经理你马在天");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 理你马在天上");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 你马在天上飞");
        if (i == 2)
            break;
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 马在天上飞  ");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 在天上飞  产");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 天上飞  产品");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 上飞  产品经");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK | 飞  产品经理");
        Sleep(200);
        SetWindowText(kookHwnd, L"KOOK |   产品经理你");
        Sleep(200);
    }
    Sleep(500);
}
