#include "String.h"

template<typename T>
void Print(T value, const char* label = "")
{
	std::cout << label << " " << value << std::endl;
}

int main()
{
	String<char> str1;
	String<char> str2("Hello");
	String<int> str3("Hello");

	Print(str2.CharAt(0));
	Print(str2.GetLength());
	Print(str3.CharAt(0));
	Print(str3.GetLength());

	Print(str1 > str2 ? "True" : "False", "str1 > str2: ");
	Print(str1 < str2 ? "True" : "False", "str1 < str2: ");
	Print(str2 == str2 ? "True" : "False", "str2 = str2: ");

	str1.Assign(str2);

	str1.Append(str2);
	str1.Append("Hello");

	return 0;
}