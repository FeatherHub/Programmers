#include "Reader.h"
#include <stdio.h>

int Reader::read(char* buf, char delim)
{
    char* start = buf;
    char c;

    while ((c = getc()) != EOF && c != delim)
        *buf++ = c;

    *buf = '\0';

    return buf - start;
}

int Reader::readLine(char* buf)
{
    return read(buf, '\n');
}

int Reader::getc()
{
    return lastChar = ungetBuffer.empty() ? getchar() : ungetBuffer.pop();
}

int Reader::unget(char c)
{
    return c < 0 ? EOF : ungetBuffer.push(c);
}

int Reader::unget(char* l)
{
    int len = lineLen(l);

    for (int i = 0; i < len; i++)
        unget(l[i]);

    return len;
}

int Reader::ungetLastCharacter()
{
    int res = unget(lastChar);
    lastChar = EOF;
    return res;
}

int Reader::lineLen(const char*)
{
    return 0;
}
