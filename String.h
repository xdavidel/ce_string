#pragma once
#include <iostream>

typedef size_t uint;

template<typename CharType>
class String
{
public:
	String()
		:m_content(nullptr),
		m_length(0)
	{}

	String(const char* str)
	{
		this->m_length = strlen(str);
		m_content = new CharType[this->m_length];
		memcpy(m_content, str, this->m_length + 1);
	}

	String(const String<CharType>& str)
		:m_length(str.GetLength())
	{
		this->m_length = str.GetLength();
		m_content = new CharType[this->m_length];
		memcpy(m_content, str.GetContent(), this->m_length + 1);
	}

	~String()
	{
		if (this->m_content != NULL)
		{
			delete(this->m_content);
		}
	}

	void Assign(const String<CharType> &str)
	{
		this->m_length = str.GetLength();
		m_content = new CharType[this->m_length];
		memcpy(m_content, str.GetContent(), this->m_length + 1);
	}

	void Append(const String<CharType> &str)
	{
		CharType *tmp = new CharType[this->m_length];
		memcpy(tmp, this->m_content, this->m_length);

		this->m_length += str.GetLength();

		m_content = new CharType[this->m_length];
		memcpy(m_content, tmp, this->m_length);

		memcpy(m_content + this->m_length - str.GetLength() +1, str.GetContent(), this->m_length + 1);
	}

	void Append(const char* str)
	{
		CharType *tmp = new CharType[this->m_length];
		memcpy(tmp, this->m_content, this->m_length);

		uint strLength = strlen(str);
		this->m_length += strLength;

		m_content = new CharType[this->m_length];
		memcpy(m_content, tmp, this->m_length);

		memcpy(m_content + this->m_length - strLength + 1, str, this->m_length + 1);
	}

	uint GetLength() const 
	{
		return m_length;
	}

	CharType CharAt(uint index) const
	{
		if (index > this->m_length || index < 0)
		{
			return NULL;
		}

		return this->m_content[index];
	}

	int Compare(const String& other) const
	{
		return this->m_length - other.GetLength();
	}

	bool IsEmpty() const
	{
		return this->m_length <= 0;
	}

	void Clear()
	{
		this->m_length = 0;

		if (NULL != this->m_content)
		{
			delete this->m_content;
		}
	}

	CharType* GetContent() const
	{
		return this->m_content;
	}

	bool operator > (const String &other)
	{
		return this->Compare(other) > 0 ? true : false;
	}

	bool operator < (const String &other)
	{
		return this->Compare(other) < 0 ? true : false;
	}

	bool operator == (const String &other)
	{
		return this->Compare(other) == 0;
	}
	
private:
	uint m_length;
	CharType* m_content;
};

