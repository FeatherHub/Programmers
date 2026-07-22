#include "MyTools.h"

#include <Windows.h>
#include <stdio.h>

typedef struct {
    char* str;
    int len;
} my_string;

int my_strLen(const char* str);
int my_isAlpha(char a);
int my_isDigit(char a);
int my_pow(int base, int exponent);

my_string* removeCharFancy(const my_string * src, char toRemove);
my_string* removeCharExtreme(const my_string* src, char toRemove);
my_string* removeAt(const my_string* src, int pos);

int my_atoi(const char* str)
{
    if (str == 0) return 0;
    
    int strLen = my_strLen(str);
    
    if (strLen <= 0) return 0;
    if (str[0] == 0) return 0;

    //Discard null characters if any
    strLen--;
    char* strBuffer = (char*)malloc((strLen) * sizeof(char));
    int bufferLen = 0;

    //Discard white spaces if any
    {
        int srcIdx = 0;
        int dstIdx = 0;
        while (srcIdx < strLen) {
            if (str[srcIdx] == ' ') {
                srcIdx++;
                continue;
            }
            strBuffer[dstIdx++] = str[srcIdx++];
        }
        bufferLen = dstIdx;
    }

    if (bufferLen <= 0) {
        free(strBuffer);
        return 0;
    }
   
    //Allow sign symbols at the first position 
    //Disallow string which consists of only a sign symbol
    {
        char firstChar = strBuffer[0];
        if (!my_isDigit(firstChar)) {
            if (firstChar != '+' &&
                firstChar != '-') {
                free(strBuffer);
                return 0;
            }
            else // firstChar == '+' || '-' 
            { 
                if (bufferLen == 1) {
                    free(strBuffer);
                    return 0;
                }
            }
        }
    }

    //Check for validitiy for other characters
    for (int i = 1; i < bufferLen; i++)
    {
        if (!my_isDigit(strBuffer[i])) {
            free(strBuffer);
            return 0;
        }
    }

    //At this point the source string is trimmed and verified in strBuffer
    
    //Split the strBuffer into sign and digits
    //Identify presence of sign symbol and its type
    int hasSign = 0; 
    int signType = 1; //default sign
    {
        char firstChar = strBuffer[0];

        if (firstChar == '+' ||
            firstChar == '-')
        {
            hasSign = 1;

            if (firstChar == '-')
                signType = -1;
        }
    }

    //Trim 
    //Shift elements left if the first character is a sign symbol
    if (hasSign) {
        for (int i = 0; i < bufferLen-1; i++)
        {
            strBuffer[i] = strBuffer[i + 1];
        }
        bufferLen--;
    }

    //"123" -> [0] = 1 [1] = 2 [2] = 3
    // 123 -> [0] = 3 [1] = 2 [2] = 1 
    int* digits = (int*)malloc((bufferLen) * sizeof(int));
    for (int i = 0; i < bufferLen; i++)
    {
        digits[i] = strBuffer[bufferLen - 1 - i] - 48; //map ascii code to integer
    }

    //Check for int overflow 
    /*
    To Do
        how to detect oveflow
    */


    //for (int i = 0; i < bufferLen; i++)
    //{
    //    printf("strBuffer[%d]: %c \n", i, strBuffer[i]);
    //    printf("digits[%d]: %d \n", i, digits[i]);
    //    printf("\n");
    //}

    //Assemble into one integer
    int sum = 0;
    for (int i = 0; i < bufferLen; i++)
    {
        sum += digits[i] * my_pow(10, i);
    }
    sum *= signType;

    free(strBuffer);
    free(digits);

    return sum;
}

// length includes the first appeared null mark
// will not work if the string has no proper null mark
int my_strLen(const char* str)
{
    if (str == 0) return -1;

    int i = 0;
 
    while (str[i++] != 0) {}

    return i;
}

int my_isAlpha(char a)
{
    //A65-Z90 a97-z122
    if ((a >= 65 && a <= 90) ||
        (a >= 97 && a <= 122))
        return 1;
    else
        return 0;
}

int my_isDigit(char a)
{
    //0=48 9=57
    if (a >= 48 && a <= 57) 
        return 1;
    else 
        return 0;
}

int my_pow(int base, int exponent)
{
    int res = 1;
    for (int i = 0; i < exponent; i++)
    {
        res *= base;
    }

    return res;
}

int my_pow_fancy(int base, int exponent)
{
    //don't change the order of condition test
    if (base == 0 || exponent < 0) return 0;
    if (base == 1 || exponent == 0) return 1;
    if (exponent == 1) return base;
    if (base == -1) return (exponent % 2 == 0) ? 1 : -1;

    int res = base;
    while (--exponent > 0) res *= base; 

    return res;
}

//float my_pow_powerful(float base, int exponent)
//{
//
//}


//Write intuitive code
//Defend against bad inputs
my_string* removeCharFancy(const my_string* src, char toRemove)
{
    if (src == 0 || src->str == 0) return 0;

    if (src->len <= 0) return 0;
    char* buffer = (char*)malloc(src->len * sizeof(char));
    if (buffer == 0) return 0;

    int srcIdx = 0, dstIdx = 0;

    while (srcIdx < src->len)
    {
        char curChar = src->str[srcIdx];
        if (curChar == toRemove) {
            srcIdx++;
            continue;
        }
        buffer[dstIdx] = curChar;
        srcIdx++, dstIdx++;
    }

    my_string* newStr = (my_string*)malloc(sizeof(my_string*));
    if (newStr == 0) return 0;

    newStr->len = dstIdx;
    newStr->str = (char*)malloc(newStr->len * sizeof(char));
    if (newStr->str) return 0;

    for (int i = 0; i < newStr->len; i++)
    {
        newStr->str[i] = buffer[i];
    }

    free(buffer);

    return newStr;
}

//Assume valid input
//Assume a favorable situation
//Use as small memory as possible
//Use as few lines as possible
my_string* removeCharExtreme(const my_string* src, char toRemove)
{
    int cnt = 0;
    int i = 0;

    while (i < src->len)
        if (src->str[i++] != toRemove && cnt++) {}
    
    my_string* newStr = (my_string*)malloc(sizeof(my_string*));
    newStr->len = cnt;
    newStr->str = (char*)malloc(newStr->len * sizeof(char));

    int dstIdx = 0;
    i = -1;
    while (++i < src->len) {
        if (src->str[i] == toRemove) continue;
      
        newStr->str[dstIdx++] = src->str[i];
    }
    
    return newStr;
}

my_string* removeAt(const my_string* src, int pos)
{
    return nullptr;
}
