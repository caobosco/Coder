#include <stdio.h>
#include <pthread.h>

pthread_mutex_t the_lock = PTHREAD_MUTEX_INITIALIZER;
void main()
{
    const int a = 8;
    a = 6;   
}
