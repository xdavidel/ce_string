#include "String.h"

String::String()
{
	this->m_content = NULL;
	this->m_length;
}


String::~String()
{
	if (this->m_content != NULL)
	{
		delete(this->m_content);
	}
}

size_t String::GetLength()
{
	return m_length;
}

void String::Assign(String otherString)
{
	this->Clear();

	size_t length = otherString.m_length;
	this->m_length = length;
	m_content = new char[ length + 1 ];
	strcpy_s(this->m_content, length +1, otherString.m_content);
}

void String::Assign(char* source)
{
	size_t length = strlen(source) +1;
	this->Clear();

	this->m_length = length -1;
	this->m_content = new char[ length + 1 ];
	strcpy_s(this->m_content, length, source);
}

char String::CharAt(size_t index)
{
	if (index > this->m_length || index < 0)
	{
		return NULL;
	}

	return this->m_content[ index ];
}

void String::Append(String otherString)
{
	size_t newLength = this->m_length + otherString.GetLength() + 1;
	char* tmp = new char[ newLength +1 ];
	strcpy_s(tmp, this->m_length +1, this->m_content);
	strcpy_s(tmp + sizeof(char)* this->m_length, newLength, otherString.m_content);

	delete this->m_content;
	this->m_content = tmp;
	this->m_length = newLength -1;
}

int String::Compare(String otherString)
{
	return strcmp(this->m_content, otherString.m_content);
}

bool String::IsEmpty()
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
