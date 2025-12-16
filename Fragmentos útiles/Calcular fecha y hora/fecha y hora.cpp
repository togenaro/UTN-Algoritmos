#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char fecha[] = {NULL};
    
    time_t current_time;
    
    current_time = time(NULL);
    
    ctime(&current_time);
    
    strcpy(fecha, ctime(&current_time));
    
    printf("%s", fecha);
     
    struct tm *tiempo = localtime(&current_time);
    printf("%d/%d/%d", tiempo->tm_mday, tiempo->tm_mon, tiempo->tm_year+1900);
    
    printf("\n\n");
    system("pause");
    
    return tiempo->tm_mday;
    
    return 0;
}
