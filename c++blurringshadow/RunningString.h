#pragma once
#include"pch.h"

//只能用于宽字符
class RunningString
{
public:
	RunningString(const std::wstring&str, const unsigned short&scale):runner(str)
	{
		int i = 0;
		track.resize(scale);
		for(std::vector<wchar_t>&v : track)
		{
			v.resize(scale);
			for(wchar_t&wc : v)
				wc = L'　';
		}
		for(const wchar_t&wc : runner)
			(*this)[i++] = wc;
	}

	void run();
private:
	wchar_t&operator[](const short i);

	const std::wstring runner;
	std::vector<std::vector<wchar_t>>track;
};
