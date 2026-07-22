#include "component_test.h"

#include <stdio.h>

#include "mymath.h"
#include "mystring.h"
#include "stack.h"

int component_test()
{
    printf("mymath-pow(%d %d): %d \n", 10, 2, mypow(10, 2));

    char s[100] = "hello world";
    char buf[100] = "";
    
    printf("mystring-mystrlen(%s): %d \n", s, mystrlen(s));

    myreverse(s, buf);
    printf("mystring-reverse %s -> %s \n", s, buf);

    char buf2[100] = "   aaabaaacaaadaaaaa aaa      ";
    printf("mystring-compact %s(%c) -> ", buf2, 'a');
    printf("%s \n", mycompact(buf2, 'a'));

    char buf3[100] = "aaabbbaaacccaaa";
    printf("mystring-trim %s(%c) -> ", buf3, 'a');
    printf("%s \n", mytrim(buf3, 'a'));



    return 0;
}
