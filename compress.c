#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compress.h"


char* changeFileName(char* name);
char* Encryption(char* fileName){
    int data = 0;
    char value;
    char* newName = changeFileName(fileName);
    FILE* pFile = fopen(fileName, "r");
    FILE* newFile = fopen(newName,"wb+");// check for the the end of the name that it's not txt
    if(pFile == NULL || newFile == NULL){
        printf("opening the file has failed\n");
        return NULL;
    }
    printf("start Encryption\n");
    while(fscanf(pFile,"%c",&value) == 1){
         switch (value) {
            case '0': 
                data = 1111; break;
            case '1': 
                data = 1110; break;
            case '2': 
                data = 1101; break;
            case '3': 
                data = 1100; break;
            case '4': 
                data = 1011; break;
            case '5': 
                data = 1010; break;
            case '6': 
                data = 1001; break;
            case '7': 
                data = 1000; break;
            case '8': 
                data = 0111; break;
            case '9': 
                data = 0110; break;
            default: 
            break; // if value is not 0-9, keep it as it is
        }
        fwrite(&data,sizeof(int), sizeof(data)/sizeof(int),newFile);
    }
    fclose(newFile);
    fclose(pFile);
    return newName;
}

char* decoding(char* fileName){
    char *data;
    int value;
    char* newName = changeFileName(fileName);        FILE* pFile = fopen(fileName, "rb");
    FILE* newFile = fopen(newName,"w");// check for the the end of the name that it's not txt
    if(pFile == NULL || newFile == NULL){
        printf("opening the file has failed\n");
        return NULL;
    }
    while(fread(&value, sizeof(int), 1, pFile) == 1){
         switch (value) {
            case 1111: 
                data = "0"; break;
            case 1110: 
                data = "1"; break;
            case 1101: 
                data = "2"; break;
            case 1100: 
                data = "3"; break;
            case 1011: 
                data = "4"; break;
            case 1010: 
                data = "5"; break;
            case 1001: 
                data = "6"; break;
            case 1000: 
                data = "7"; break;
            case 0111: 
                data = "8"; break;
            case 0110: 
                data = "9"; break;
            default: 
            break; // if value is not 0-9, keep it as it is
        }
        fprintf(newFile,"%s",data);
    }
    fclose(newFile);
    fclose(pFile);
    return newName;
}

char* changeFileName(char* name){
    char* newName = "";
    int i = 0;
    while(name[i] !='\0'){
        if(name[i] == '.'){
            newName[i] = name[i];
            break;
        }
        newName[i] = name[i];
        i++;
    }
    if(name[i+1]=='t'){
        newName[i+1] = 'b';
        newName[i+2] = 'i';
        newName[i+3] = 'n';
    }
    else if(name[i+1]=='b'){
        newName[i+1] = 't';
        newName[i+2] = 'x';
        newName[i+3] = 't';
    }
    return newName;
}