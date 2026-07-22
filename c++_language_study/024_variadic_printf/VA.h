#pragma once
#include <stdarg.h>

#define CREATE_AND_INIT_VA(VAR_NAME) \
		VA VAR_NAME = VA(fmt); \
		va_start((VAR_NAME.___ap()), VAR_NAME.___fmt()) \

class VA
{
public:
	VA(const char* fmt) 
	{
		ap = nullptr;
		this->fmt = fmt;
	}

	template <typename T>
	T pop()
	{
		return va_arg(ap, T);
	}

	void clear()
	{
		va_end(ap);
		ap = nullptr;
		fmt = nullptr;
	}

	va_list& ___ap()
	{
		return ap;
	}

	const char* ___fmt()
	{
		return fmt;
	}

private:
	va_list ap;
	const char* fmt;
};