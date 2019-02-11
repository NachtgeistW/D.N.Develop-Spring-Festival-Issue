#include"pch.h"
#include "RunningString.h"

void RunningString::run()
{
	std::wstring run1111;
	unsigned short pos = runner.length();
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD reset{0, 0};

	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hout, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hout, &cci);//��겻�ɼ�

	run1111.reserve(track.size()*track.size() + 1);

	while(true)
	{
		for(const std::vector<wchar_t>&v : track)
		{
			for(const wchar_t&wc : v)
				run1111 += wc;
			run1111 += '\n';
		}
		std::wcout << run1111;
		run1111.clear();
		for(unsigned short i = pos; i > pos - runner.length(); --i)
			std::swap((*this)[i], (*this)[i - 1]);
		pos++;
		SetConsoleCursorPosition(hout, reset);//�����ʼλ�ã��������
	}
}

//��ά������Ȧ����
wchar_t&RunningString::operator[](short i)
{
	const short&&length = track.size() - 1;
	i %= 4 * (length - 1);
	const short edge = i / (length - 1);
	i -= edge * (length - 1);
	switch(edge)
	{
	case 0://��
		return track[0][i];
	case 1://��
		return track[i][length];
	case 2://��
		return track[length][length - i];
	case 3://��
		return track[length - i][0];
	default:
		wchar_t temp;
		return temp;
	}
}