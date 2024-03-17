#include <stdio.h>
#include "compress.h"
#include "compress.c"

int main(int argc, char *argv[]){
    printf("start\n");
    if (argc != 3) {//if the user didn't send all the arguments 
        fprintf(stderr, "Usage: %s <congestion_algorithm>\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[1],"-c")){
        Encryption(argv[2]);
    }
    if(strcmp(argv[1],"-d")){
        decoding(argv[2]);
    }
}

