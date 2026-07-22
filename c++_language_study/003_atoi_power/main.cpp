#include <stdio.h>
#include "MyTools.h"

void test_atoi();
void test_pow();

int main()
{
	test_pow();

	return 0;
}

void test_pow()
{
	printf("test 1: pow(%d, %d) = %d\n", -1, 10, my_pow_fancy(-1, 10));
	printf("test 2: pow(%d, %d) = %d\n", 0, 10, my_pow_fancy(0, 10));
	printf("test 3: pow(%d, %d) = %d\n", 1, 10, my_pow_fancy(1, 10));
	printf("test 4: pow(%d, %d) = %d\n", 2, 10, my_pow_fancy(2, 10));
	printf("test 5: pow(%d, %d) = %d\n", -2, 10, my_pow_fancy(-2, 10));
	printf("test 6: pow(%d, %d) = %d\n", -2, 11, my_pow_fancy(-2, 11));
	printf("test 7: pow(%d, %d) = %d\n", 5, 0, my_pow_fancy(5, 0));
	printf("test 8: pow(%d, %d) = %d\n", 1, 0, my_pow_fancy(1, 0));
	printf("test 9: pow(%d, %d) = %d\n", -1, 0, my_pow_fancy(-1, 0));
	printf("test 10: pow(%d, %d) = %d\n", 0, 0, my_pow_fancy(0, 0));
	printf("test 11: pow(%d, %d) = %d\n", 2, 16, my_pow_fancy(2, 16));
	printf("test 11: pow(%d, %d) = %d\n", 2, 17, my_pow_fancy(2, 17));
	printf("test 11: pow(%d, %d) = %d\n", 2, 18, my_pow_fancy(2, 18));

}
void test_atoi()
{
	printf("test 1: [123123] => [%d]\n",
		my_atoi("123123"));
	printf("test 2: [+123123] => [%d]\n",
		my_atoi("+123123"));
	printf("test 3: [-123123] => [%d]\n",
		my_atoi("-123123"));
	printf("test 4: [+] => [%d] \n",
		my_atoi("+"));
	printf("test 5: [     +] => [%d]\n",
		my_atoi("     +"));
	printf("test 6: [- 1 2 3 1 2 3] => [%d]\n",
		my_atoi("- 1 2 3 1 2 3"));
	printf("test 7: [ -1 2 3 1 2         3] => [%d]\n",
		my_atoi(" -1 2 3 1 2         3"));
	printf("test 8: [       - 1 2 3    123       ] => [%d]\n",
		my_atoi("       - 1 2 3    123       "));
	printf("test 9: [+a1020] => [%d]\n",
		my_atoi("+a1020"));
	printf("test 10: [+++00012] => [%d]\n",
		my_atoi("+++00012"));
	printf("test 11: [+000000012] => [%d]\n",
		my_atoi("+000000012"));
	printf("test 11: [999999999999] => [%d]\n",
		my_atoi("999999999999")); //to do: detect overflow, underflow
}
