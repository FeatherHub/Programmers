#include <locale>
#include <iostream>
#include <windows.h>

using namespace std;

#define UTF_32_LITTLE_ENDIAN 12000

int main()
{
	SetConsoleCP(UTF_32_LITTLE_ENDIAN);

	wcout << std::hex
		<< int(L'안') << " "
		<< int(L'녕') << " "
		<< int(L'하') << " "
		<< int(L'세') << " "
		<< int(L'요') << endl;

	wcout << L"Hello \n";

	wcout << L"Hej, världen! (Swedish) \n";

	locale::global(locale("zh_CN.UTF-8"));
	wcout << L"你好，世界！ (Chinese) \n";

	wcout << L"안녕하세요 \n";

	wcout << L"ひらがな \n";

	wcout << L"مرحبًا، العالم! \n";


	return 0;
}