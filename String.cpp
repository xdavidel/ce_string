#include "String.h"

String::String():m_content(nullptr), m_length(0) {}

String::~String()
{
	if (this->m_content != NULL)
	{
		delete(this->m_content);
	}
}

size_t String::GetLength() const
{
	return m_length;
}

void String::Assign(const String &other)
{
	this->Clear();

	size_t length = other.m_length;
	this->m_length = length;
	m_content = new char[ length + 1 ];
	strcpy_s(this->m_content, length +1, other.m_content);
}

void String::Assign(const char* source)
{
	size_t length = strlen(source) +1;
	this->Clear();

	this->m_length = length -1;
	this->m_content = new char[ length + 1 ];
	strcpy_s(this->m_content, length, source);
}

char String::CharAt(size_t index) const
{
	if (index > this->m_length || index < 0)
	{
		return NULL;
	}

	return this->m_content[ index ];
}

void String::Append(const String &other)
{
	size_t newLength = this->m_length + other.GetLength() + 1;
	char* tmp = new char[ newLength +1 ];
	strcpy_s(tmp, this->m_length +1, this->m_content);
	strcpy_s(tmp + sizeof(char)* this->m_length, newLength, other.m_content);

	delete this->m_content;
	this->m_content = tmp;
	this->m_length = newLength -1;
}

int String::Compare(const String &other) const
{
	return strcmp(this->m_content, other.m_content);
}

bool String::IsEmpty() const
{
	return this->m_length <= 0;
}

void String::Clear()
{
	this->m_length = 0;
	
	if (NULL != this->m_content)
	{
		delete this->m_content;
	}
}
