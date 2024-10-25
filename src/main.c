#include <stdio.h>

int main(int argc, char *argv[]){
    printf("test c demo code....");
    if(argc > 1){
        printf("the config file path is %s\n", argv[1]);
    }
    return 0;
}