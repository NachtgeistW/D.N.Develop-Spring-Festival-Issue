#include"pch.h"
#include"RunningString.h"

int main()
{
	std::wcout.imbue(std::locale("", LC_CTYPE));
	std::wcin.imbue(std::locale("", LC_CTYPE));

	const short speed = []() { short input; std::cout << "多大的圈？\n"; std::cin >> input; return input; }();
	const std::wstring str = []() { std::wstring input; std::cout << "\n跑什么圈？\n"; std::wcin >> input; return input; }();
	system("cls");
	RunningString(str, speed).run();
}