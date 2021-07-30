#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(void) {
  int    fd;
  long   size, pagesize;
  char   *mm;
  
  if((fd=open("position.txt",O_RDWR))== -1){
    perror("open");
    exit(-1);
  }
  
  pagesize=sysconf(_SC_PAGE_SIZE);
  size=(1000*sizeof(char)/pagesize+1)*pagesize;

  if(lseek(fd,0,SEEK_SET) < 0) {
    perror("lseek");
    exit(-1);
  }
  
  mm=(char*)mmap(0,size,PROT_READ,MAP_SHARED,fd,0);
  if ( mm == MAP_FAILED ) {
    printf("Mmap Error!!\n");
  }
  printf("%s", mm);
  close(fd);
  return 0;
}

