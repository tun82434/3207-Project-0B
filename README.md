tucp.c is a C program that allowed me to recreate the cp command in linux.

* When running ./tucp with 2 arguments, the program takes in a source file and a renamed file path or a directory. The program will then copy the source file path and creates a copy using either the renamed file in the path or in the directory.
* When running ./tucp with more than 2 arguments, all the arguments besides the last one has to be a source file, the last argument has to be the directory. The program copies all of the source files and creates a copy of it in the directory.
