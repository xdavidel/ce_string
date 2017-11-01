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

	size_t GetLength() const;
	void Assign(const String&);
	void Assign(const char*);
	char CharAt(size_t) const;
	void Append(const String&);
	int Compare(const String&) const;
	bool IsEmpty() const;
	void Clear();
};

