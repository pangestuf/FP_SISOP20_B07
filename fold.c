#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  int fd, n;
  if(argc < 2){
    printf(1, "Need  2 arguments!\n");
    exit();
  }
  int x = atoi(argv[2]);
  char buffer[x];

  if((fd = open(argv[1], O_RDONLY)) < 0){
	printf(1, "fold: cannot open %s\n", argv[1]);
	exit();
    }
  while( ( n = read (fd, buffer,sizeof(buffer))) > 0 ){
	for(int i = 0;i< x;i++){
		if(buffer[i]=='\n'){
			buffer[i] = ' ';
		}
	}
	printf(1,"%s\n",buffer);
    }
close(fd);
  exit();
}
