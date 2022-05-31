#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *OSversion;
	FILE *Kernelversion;
	char currChar;
	
	OSversion = fopen("/etc/os-release", "r");
	Kernelversion = fopen("/proc/version", "r");
	
	if(OSversion == NULL || Kernelversion == NULL)
	{
		printf("Failed to open file(s)\n");
	}
	else
	{
		currChar = fgetc(OSversion);
		while(currChar != EOF)
		{
			printf("%c", currChar);
			currChar = fgetc(OSversion);
		}
		fclose(OSversion);
		
		currChar = fgetc(Kernelversion);
		while(currChar != EOF)
		{
			printf("%c", currChar);
			currChar = fgetc(Kernelversion);
		}
		fclose(Kernelversion);
		
	}
	return 0;
}
