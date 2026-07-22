#include <stdio.h>

void print_wrap(const char* str, int wid);

int main()
{
	char buf[2000] = { 
"The build event commands can include any command \
that is valid at a command prompt or in a .bat file. \
The name of a batch file should be preceded by call \
to ensure that all subsequent commands are executed. \
The batch file itself runs from the output folder, \
for example, bin/Debug. If you need the same batch file \
for all configurations, you could put it in the same folder \
as the project file and use a relative path to it, \
for example, call ../../prebuild.bat. \
You can execute PowerShell scripts by entering a command like \
The build event commands can include any command \
that is valid at a command prompt or in a .bat file. \
The name of a batch file should be preceded by call \
to ensure that all subsequent commands are executed. \
The batch file itself runs from the output folder, \
for example, bin/Debug. If you need the same batch file \
for all configurations, you could put it in the same folder \
as the project file and use a relative path to it, \
for example, call ../../prebuild.bat. \
You can execute PowerShell scripts by entering a command like \
The build event commands can include any command \
that is valid at a command prompt or in a .bat file. \
The name of a batch file should be preceded by call \
to ensure that all subsequent commands are executed. \
The batch file itself runs from the output folder, \
for example, bin/Debug. If you need the same batch file \
for all configurations, you could put it in the same folder \
as the project file and use a relative path to it, \
for example, call ../../prebuild.bat. \
You can execute PowerShell scripts by entering a command like \
PowerShell MyPowerShellScript.ps1.The path to the PowerShell script" };
	
	printf("%s \n", buf);

	print_wrap(buf, 0);

	return 0;
}

void print_wrap(const char* str, int wid)
{
	int i, cnt;
	i = cnt = 0;

	while (str[i] != '\0')
	{
		putchar(str[i++]);
	
		if (++cnt >= wid) {
			putchar('\n');
			cnt = 0;
		}
	}
}

