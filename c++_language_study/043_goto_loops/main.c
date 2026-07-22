#include <stdio.h>
#include <string.h>


void simloop();
void simif();

int main()
{

	return 0;
}

void simloop()
{
	char str[] = "Hello, World!";
	int len = strlen(str);
	
	int i, j;
	int cond;
	int tmp;
LOOP_BLOCK:
{
	LOOP_INIT:
	{
		i = 0;
		j = len - 1;
		goto LOOP_CONDITION;
	}
	LOOP_CONDITION:
	{
		cond = i < j;
		if (cond)	goto LOOP_BODY;
		else		goto LOOP_END;
	}
	LOOP_BODY:
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;

		goto LOOP_CONVAR_UPDATE;
	}
	LOOP_CONVAR_UPDATE:
	{
		i++;
		j--;
		goto LOOP_CONDITION;
	}
	LOOP_END:
	{
		//do some clean-up task
	}
}
	printf("%s %d %d \n", str, i, j);
}

void simif()
{
	int i = 1;
	if (i == 1) i++;
	else i--;

	// jumpvector[cond]()

}

