#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main(void)
{
    int i;

    srand(time(NULL));

    for (i = 0; i < 5; i++)
        printf("난수 출력: %d\n", rand() % 100);
    
    return 0;
}