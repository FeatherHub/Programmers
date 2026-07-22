#include <iostream>
#include <stack>
#include <stdarg.h>

using namespace std;

enum class TYPE {
	CHAR, 
	INT
};

enum class CATEGORY {
	ARGUMENT,
	LOCAL
};

typedef struct function_variable {
	TYPE type;
	CATEGORY cat;
	//const or not const
	//...
} function_local;

typedef struct function_table_entry {
	void* function_id;
	function_variable variables [100];
	int varnum;
} function_table_entry;

typedef struct function_table {
	function_table_entry ents[100];
	int entnum;
} function_table;

stack<void*> rtstk;
function_table ftab;

//int(int, int)(int)
void add()
{
	int arg2 = (int)rtstk.top(); rtstk.pop();
	cout << "arg2: " << arg2 << endl;

	int arg1 = (int)rtstk.top(); rtstk.pop();
	cout << "arg1: " << arg1 << endl;

	int lcl = (int)rtstk.top(); rtstk.pop();
	cout << "lcl1: " << lcl << endl;

	lcl = arg1 + arg2;
	cout << "calculation" << endl;

	rtstk.push((void*)lcl);
	cout << "push lcl " << lcl << endl;
}

void* pop()
{
	void* _val = rtstk.top();
	rtstk.pop();
	return _val;
}

#define POP pop()

//void(int*, int*)(int*)
void myswap()
{
	int* arg2 = (int*)POP; 
	int* arg1 = (int*)POP;
	int* lcl1 = (int*)POP;

	*lcl1 = *arg1;
	*arg1 = *arg2;
	*arg2 = *lcl1;

	return;
}

void init_function_table()
{
	ftab.entnum = 0;

	ftab.ents[0].function_id = add;
	ftab.ents[0].varnum = 3;
	ftab.ents[0].variables[0].type = TYPE::INT;
	ftab.ents[0].variables[0].cat = CATEGORY::ARGUMENT;
	ftab.ents[0].variables[1].type = TYPE::INT;
	ftab.ents[0].variables[1].cat = CATEGORY::ARGUMENT;
	ftab.ents[0].variables[2].type = TYPE::INT;
	ftab.ents[0].variables[2].cat = CATEGORY::LOCAL;

	ftab.entnum++;
}

void call(void* func, ...)
{
	if (ftab.entnum <= 0) 
		return;

	function_table_entry fte;
	int found = 0;
	//find the ent
	for (int i = 0; i < ftab.entnum; i++)
	{
		if (ftab.ents[i].function_id == func) {
			fte = ftab.ents[i];
			found = 1;
			cout << "func " << func << " found" << endl;
			break;
		}
	}

	if (!found) {
		cout << "func " << func << " not exist" << endl;
		return;
	}

	//push local first
	for (int i = 0; i < fte.varnum; i++)
	{
		function_variable fv = fte.variables[i];

		if (fv.cat == CATEGORY::LOCAL) {
			switch (fv.type)
			{
			case TYPE::CHAR:
				cout << "local variable CHAR is pushed for " << fte.function_id << endl;
				rtstk.push((void*)char{});
				break;
			case TYPE::INT:
				cout << "local variable INT is pushed for " << fte.function_id << endl;
				rtstk.push((void*)int{});
				break;
			default:
				cout << "no supported local variable type" << (int)fv.type << endl;
				break;
			}
		}
		else if (fv.cat == CATEGORY::ARGUMENT) {
		}
		else {
			cout << "not supported category " << (int)fv.cat << endl;
		}
	}

	//push arguments last
	va_list varg;
	va_start(varg, func);
	for (int i = 0; i < fte.varnum; i++)
	{
		function_variable fv = fte.variables[i];

		if (fv.cat == CATEGORY::ARGUMENT) {
			//copy parameter
			char cv;
			int iv;
			switch (fv.type)
			{
			case TYPE::CHAR:
				cv = va_arg(varg, char);
				rtstk.push((void*)cv);
				cout << "argument CHAR is pushed for " << fte.function_id << endl;
				break;
			case TYPE::INT:
				iv = va_arg(varg, int);
				rtstk.push((void*)iv);
				cout << "argument INT " << iv << " is pushed for " << fte.function_id << endl;
				break;
			default:
				cout << "no supported argument type" << (int)fv.type << endl;
				break;
			}

		}
		else if (fv.cat == CATEGORY::LOCAL) {
		}
		else {
			cout << "not supported category " << (int)fv.cat << endl;
		}
	}
	va_end(varg);

	//call
	((void(*)(void))func)();

	//pop
	
	//push
	
	//return caller

}

int main()
{
	init_function_table();
	call(add, 10, 900);
	call(myswap);
	return 0;
}