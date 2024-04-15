# get_next_line
This project in C aims to create a function called get_next_line that efficiently reads lines from a file descriptor (fd) one at a time. Here's a summary:

## Mandatory Part:
### Function: 
*	char *get_next_line(int fd);
### Parameters:
* fd is the file descriptor to read from.
### Return Value:
* Returns the line read from the file descriptor.
* Returns NULL if there's nothing else to read or an error occurred.
### Description:
* The function should return a line read from the file descriptor.
* Repeated calls to get_next_line() should allow reading the text file line by line.
* The returned line should include the terminating \n character, except at the end of the file.
* Functions like read(), malloc(), and free() can be used.
###  Requirements:
* Implementation of get_next_line() function and supporting utility functions.
* Understanding and use of static variables.

## Bonus Part:
### Requirements:
* Develop get_next_line() using only one static variable.
* Ability to manage multiple file descriptors simultaneously.
