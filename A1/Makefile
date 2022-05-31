all: my_version my_current_processes my_memory_util

my_version: my_version.c
	gcc -g -Wall -o my_version my_version.c
	
my_current_processes: my_current_processes.c
	gcc -g -Wall -o my_current_processes my_current_processes.c
	
my_memory_util: my_memory_util.c
	gcc -g -Wall -o my_memory_util my_memory_util.c
	
clean:
	rm -f my_version my_current_processes my_memory_util *.o
