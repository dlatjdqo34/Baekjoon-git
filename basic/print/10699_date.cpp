#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>

using namespace std;

int main()
{
    time_t timer = time(NULL);
    struct tm *t = localtime(&timer);
    
    printf("%d-%d-%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    return 0;
}