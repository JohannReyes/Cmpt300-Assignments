#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() 
{
	char *memNames[5] = {"MemTotal", "MemFree", "Buffers", "Cached", "Slab"};
  	char currChar;
	char currMemName[15] = "";
  
  	double memNums[5];
  	double memData=0;
  
  	int memNameIndex = -1;
  	int currArrSiz = 0;

  	bool finComp = false;

	FILE *meminfo;

  	meminfo = fopen("/proc/meminfo", "r");
	
	if(meminfo == NULL)
	{
		printf("Failed to open file(s)\n");
	}
	else
	{
		currChar = fgetc(meminfo);
		while(currChar != EOF)
		{
      			//printf("%c", currChar);

      			//Checks if its running through the name and storing it
      			if((currChar>=65 && currChar<=90)||(currChar>=97 && currChar<=122))
      			{
        			strncat(currMemName, &currChar, 1);
      			}
      			else if(!finComp) //For when it is done storing the name: compare with word bank
      			{
        			for(int i=0; i<5; i++)
        			{
          				if(strcmp(memNames[i], currMemName) == 0)// If name is data wanted then
          				{
            					memNameIndex = i;  //save index for storing data
            					finComp = true;
            					break;
          				}
        			}
        			memset(currMemName, 0, sizeof(currMemName));
      			}
      			else if(currChar>=48 && currChar<=57) //once it hits the number, convert into double
      			{
        			memData = (memData*10) + (currChar-48);
      			}
      			else if(memNameIndex != -1 && memData != 0)  //storing memData into array (specific index)
      			{
        			memNums[memNameIndex] = memData;
        			//reset everything
        			memset(currMemName, 0, sizeof(currMemName));
        			memData = 0;
        			memNameIndex = -1;
        			finComp = false;
        			//update array num size
        			currArrSiz++;
      			}

      			if(currArrSiz == 5) // Arr is full, don't need anything else from file
      			{
        			break;
      			}
			currChar = fgetc(meminfo);
		}
		fclose(meminfo);		
	}
	
	//For testing
	/*printf("\n");
	for(int i=0; i<5; i++)
	{
		printf("%s: %.2f\n", memNames[i], memNums[i]);
	}*/
	
	//Calculation
	double memUtil = ((memNums[0]-memNums[1]-memNums[2]-memNums[3]-memNums[4])/memNums[0])*100;
	printf("%.2f\n",memUtil); 
  return 0;
}
