#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <fcntl.h>
#include <string>
#include <io.h>


class PrintUTF8
{
public:
	static void print(const std::wstring& text)
	{
		int a = _setmode(_fileno(stdin), _O_U16TEXT);
		a = _setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << text;
		a = _setmode(_fileno(stdin), _O_TEXT);
		a = _setmode(_fileno(stdout), _O_TEXT);
	}
    static void print(bool isFirstElement, bool isLastElement, int n, ...)
    {
        if (isFirstElement)
        {
            std::cout << (char)218;
            for (int i = 0; i < n - 1; ++i)
            {
                for (int i = 0; i < 15; ++i)
                {
                    std::cout << (char)196;
                }
                std::cout << (char)194;
            }
            for (int i = 0; i < 15; ++i)
            {
                std::cout << (char)196;
            }
            std::cout << (char)191 << std::endl;
        }
        std::cout << (char)179;
        va_list vl;
        va_start(vl, n);
        for (int i = 0; i < n; ++i)
        {
            std::string str = std::string(va_arg(vl, char*));
            std::cout << std::setw(15 - ((15 - str.length()) / 2 + 1) + 1) << str;
            std::cout << std::setw(((15 - str.length()) / 2 + 1)) << (char)179;
        }
        va_end(vl);
        std::cout << std::endl;
        if (isLastElement)
            std::cout << (char)192;
        else
            std::cout << (char)195;
        for (int j = 0; j < n - 1; ++j)
        {
            for (int i = 0; i < 15; ++i)
            {
                std::cout << (char)196;
            }
            if (isLastElement)
                std::cout << (char)193;
            else
                std::cout << (char)197;
        }
        for (int i = 0; i < 15; ++i)
        {
            std::cout << (char)196;
        }
        if (isLastElement)
            std::cout << (char)217;
        else
            std::cout << (char)180;
        std::cout << std::endl;
    }
};


