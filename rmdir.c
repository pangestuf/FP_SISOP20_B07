#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"
int isDirectoryNotEmpty(char *dirname){
	int n = 0;
	int fd0;
	struct dirent de;
	if((fd0 = open(dirname,0))<0) return 1;
	while(read(fd0,&de,sizeof(de))==sizeof(de)){
		if(++n > 2) break;
	}
	close(fd0);
	if(n<=2)return 0;
	else return 1;
}
int main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf(2, "Usage: rmdir files...\n");
    exit();
  }

  for(i = 1; i < argc; i++){
    if(isDirectoryNotEmpty(argv[i])||unlink(argv[i]) < 0){
      printf(2, "mkdir: %s failed to delete\n", argv[i]);
      break;
    }
  }

  exit();
}
