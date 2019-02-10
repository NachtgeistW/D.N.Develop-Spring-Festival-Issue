#include <iostream>
#include <thread>

#include "console_vt.h"
#include "static_string.h"
#include "string_template.h"
#include "color_output.h"

int main()
{
    using namespace std::chrono_literals;

    // Enable virtual terminal for colored output
    enable_virtual_terminal_mode();

    // Prepare characters for running
    using 夜 = String<-46, -71>; using 轮 = String<-62, -42>;
    using 大 = String<-76, -13>; using 简 = String<-68, -14>;
    using 直 = String<-42, -79>; using 是 = String<-54, -57>;
    using 天 = String<-52, -20>; using 使 = String<-54, -71>;
    using 啊 = String<-80, -95>; using 激 = String<-68, -92>;
    using 动 = String<-74, -81>; using 到 = String<-75, -67>;
    using 跑 = String<-59, -36>; using 圈 = String<-56, -90>;
    using 叹号 = String<-93, -95>;

    using Full = Join<夜, 轮, 大, 大, 简, 直, 是, 天, 使, 叹号,
        啊, 啊, 啊, 啊, 激, 动, 到, 跑, 圈, 叹号, 叹号, 叹号, 叹号>::Add<'\n'>;

    // Define colors
    const StaticString red = ColorStr<255, 0, 0>::value();
    const StaticString orange = ColorStr<255, 127, 0>::value();
    const StaticString yellow = ColorStr<255, 255, 0>::value();
    const StaticString green = ColorStr<0, 255, 0>::value();
    const StaticString cyan = ColorStr<0, 255, 255>::value();
    const StaticString blue = ColorStr<0, 0, 255>::value();
    const StaticString purple = ColorStr<255, 0, 255>::value();

    const StaticString str = Full::value();
    while (true)
    {
        std::cout << red.value();    std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << orange.value(); std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << yellow.value(); std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << green.value();  std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << cyan.value();   std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << blue.value();   std::cout << str.value(); std::this_thread::sleep_for(0.03s);
        std::cout << purple.value(); std::cout << str.value(); std::this_thread::sleep_for(0.03s);
    }
}
