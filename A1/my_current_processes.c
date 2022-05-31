#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
	DIR *currDir;
	struct dirent *pid;
	
	currDir = opendir("/proc");
	
	if(currDir == NULL)
	{
		printf("Failed to open directory\n");
	}
	else
	{
		pid = readdir(currDir);
		while(pid != NULL)
		{
			if(pid->d_name[0] >= 48 && pid->d_name[0] <= 57)
			{
				printf("%s\n", pid->d_name);
			}
			pid = readdir(currDir);
		}
		closedir(currDir);
	}
	return 0;
}
