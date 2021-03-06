// PE_INFO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <Windows.h>
#include "pe.h"

int main()
{
    //std::cout << "Hello World!\n"; 
	HANDLE file_handle = CreateFile(TEXT("notepad.exe"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	//HANDLE file_handle = CreateFile(TEXT("JZNet.dll"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);

	if (file_handle)
	{
		DWORD file_size = GetFileSize(file_handle, NULL);
		DWORD r_size = 0;
		VOID *p_buffer = malloc(file_size);
		ReadFile(file_handle, p_buffer, file_size, &r_size, NULL);
		//std::cout << "file_size="<< file_size <<std::endl;
		PE_INFO(p_buffer, file_size);
	}
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
