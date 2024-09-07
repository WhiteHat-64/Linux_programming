#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int *ptr;

    while(1) {
        for(int i=0; i<10000; i++) {
            ptr = (int *) malloc(4092);

            for (int j = 0; j < 100000; j++) {
                ptr[j] = 100+j;
            }

            printf("ptr[0]: %d\n", ptr[0]);
            printf("ptr[1]: %d\n", ptr[1]);
            printf("ptr[2]: %d\n", ptr[2]);
            printf("ptr[98]: %d\n", ptr[98]);
            printf("ptr[99]: %d\n", ptr[99]);
        }
        sleep(1);
    }

}
