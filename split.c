#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *buffer;

int main(int argc, char *argv[])
{
  int fd0, fd1,n,total,tfile=0;
  char filenya[3];
  filenya[0] ='x';
  filenya[1] ='a';
  filenya[2] ='a';

  if(argc < 1){
    printf(1, "Need arguments!\n");
    exit();
  }
  if((fd0 = open(argv[1], O_RDONLY)) < 0){
	printf(1, "split: cannot open %s\n", argv[1]);
	exit();
    }

  if((fd1 = open(filenya, O_CREATE|O_RDWR)) < 0){
	printf(1, "split: cannot open %s\n", filenya);
	exit();
  }
  while( ( n = read (fd0, buffer,sizeof(buffer))) > 0 ){
	   if (*buffer=='\n') total++;
	   write ( fd1, buffer, n );
	   if(total == 1000){
		total = 1;
		tfile++;
		filenya[1] =(tfile/26)+97;
  		filenya[2] =(tfile%26)+97;
		close(fd1);
		if((fd1 = open(filenya, O_CREATE|O_RDWR)) < 0){
			printf(1, "split: cannot open %s\n", filenya);
			exit();
  		}
  	}
	}
	close(fd0);
	close(fd1);
  exit();
}
