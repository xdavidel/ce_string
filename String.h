#pragma once
#include <iostream>

class String
{
	private:
	size_t m_length;
	char* m_content;

	public:
	String();
	~String();

	size_t GetLength();
	void Assign(String otherString);
	void Assign(char* source);
	char CharAt(size_t index);
	void Append(String otherString);
	int Compare(String otherString);
	bool IsEmpty();
	void Clear();
};

