#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

// Function Declaration:
int twoARGC(char **argv);
int nARGC(int argc, char **argv);

int main(int argc, char **argv){
    if (argc < 2){ // less than 2 arguments
        printf("Error: Insufficient arguments, two arguments are required.\n");
        exit(1);
    } else if (argc == 3){ // 2 arguments
        twoARGC(argv);
    } else{ // greater than 2 arguments (n arguments)
        nARGC(argc, argv);
    }
    return 0;
}

int twoARGC(char **argv){
    struct stat path1, path2;
    if (stat(argv[1], &path1) == 0 && stat(argv[2], &path2) == 0){
        if (S_ISREG(path1.st_mode) && S_ISREG(path2.st_mode)){ // tucp sourceFile destinationFile
            FILE *sFile, *dFile;
            sFile = fopen(argv[1],"r");
            dFile = fopen(argv[2],"w");
            if (sFile == NULL){ // Source File could not be opened
                printf("Error: Source File could not be opened.\n");
                exit(1);
            }
            if (dFile == NULL){ // Destination could not be opened
                printf("Error: Destination File could not be opened.\n");
                exit(1);
            }
            
        } else if (S_ISREG(path1.st_mode) && S_ISDIR(path2.st_mode)){ // tucp sourceFile destinationDirectory
            printf("tucp sourceFile destinationDirectory\n");
        } else{ // Invalid inputs
            printf("Error: Invalid arguments.\n");
            exit(1);
        }
    } else{
        printf("Error: Invalid path arguments.\n");
        exit(1);
    }
    return 0;
}

int nARGC(int argc, char **argv){
    return 0;
}


