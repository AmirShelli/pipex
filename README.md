# pipex

## Table of Contents
+ [About](#about)
+ [Getting Started](#getting_started)
+ [Usage](#usage)

## About
This project is the discovery in detail and by programming of a pipe from UNIX.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

This project works only on Linux/MacOS platforms only.

### Installing
To compile the program, you'll have to use your terminal and use the Makefile rules below:

 + ``make`` -> Generates _pipex_ and an object file for each .c
 + ``make clean``  Deletes all object files
 + ``make fclean``  Deletes the object files and the _pipex_
 + ``make re``  makes ``fclean`` and ``make`` again 

## Usage
After compiling the program type the executable file and the commands you'd like to try them on.
```
./pipex infile “cmd1” “cmd2” “cmd3” … outfile
```
it will be the equivalent of in the bash environment:
```
< infile cmd1 | cmd2 | cmd3 | ... > outfile
```
