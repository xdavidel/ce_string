#include "String.h"

int main()
{
	String str1;
	String str2;

	str1.Assign("Hi");
	str2.Assign(str1);

	str1.Append(str2);
	return 0;
}