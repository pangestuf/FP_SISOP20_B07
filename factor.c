#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void print_factor(int n);
int main(int argc, char *argv[])
{
    int i;
    for(i=1;i<argc;i++){
        printf(1,"%d:",atoi(argv[i]));
        print_factor(atoi(argv[i]));
    }
exit();
}

void print_factor(int n)
{
    if (n==1)
	return;
    int num=2;
    while (n%num != 0)
        num++;
    printf(1," %d",num);
    print_factor(n/num);
}
