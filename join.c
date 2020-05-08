#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *buffer;
int
main(int argc, char *argv[])
{
  int fd0, fd1,n;
	
  if(argc < 2){
    printf(1, "Need  2 arguments!\n");
    exit();
  }
  if((fd0 = open(argv[1], O_RDONLY)) < 0){
	printf(1, "join: cannot open %s\n", argv[1]);
	exit();
    }
  if((fd1 = open(argv[2], O_RDONLY)) < 0){
	printf(1, "join: cannot open %s\n", argv[2]);
	exit();
  }

  while( ( n = read (fd0, buffer,sizeof(buffer))) > 0 ){
	if (*buffer=='\n'){
		if((n = read (fd1, buffer,sizeof(buffer))) > 0){
			*buffer = ' ';
			printf(1, "%s", buffer);
			while((n = read (fd1, buffer,sizeof(buffer))) > 0){
			   printf(1, "%s", buffer);
			}
		}else{
		printf(1, "%s", buffer);
    		}
	}
  }
  while(( n = read (fd1, buffer,sizeof(buffer))) > 0){
	printf(1, "%s", buffer);
  }
close(fd0);
close(fd1);
  exit();
}
