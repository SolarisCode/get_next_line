# get_next_line
This is my own implementation of getline() from C library

Getting the next line is an ungly job in C, luckily there is getline()
from the standard input/output library.
I have created my own program to mimic the behavior of getline(),
and to gain a better understanding of file descriptors
in Linux operating system.

|Function name|get_next_line|
|:-----------:|:------------|
|Prototype|char *get_next_line(int fd);|
|Turn in files|get_next_line.c, get_next_line_utils.c,<br />get_next_line.h|
|Parameters|fd: The file descriptor to read from|
|Return value|Read line: correct behavior<br />NULL: there is nothing else to read, or an error<br />occurred|
|External functs|read, malloc, free|
|Description|A function that returns a line read from a<br />file descriptor|

>Basically `get_next_line(fd)` keeps reading form the provided file descriptor until 
>it encounters new line character `\n` then return it as a string, it also keeps
>track of the file if you try to use it again it would get you the next available line "DA ;)"

>If you use the bonus files instead of the main files you gain the functionality of using different 
>file descriptors after each other while `get_next_line(fd)` keeps track of each one of them, so you 
>you can go back and continue reading any of them from the stop point from the last call of 
>`get_next_line(fd)`

If you have any optimization idea about the code please let me know :)
