#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
  int fd1, fd2, n;
  char ch;
  fd1=open("file1.txt",O_CREAT|O_RDWR,0666);
  if(fd1==-1)
  {
    printf("source filw cannot be processed\n");
    exit(0);
  }
  fd2=open("file2.txt",O_CREAT|O_RDWR,0666);
  if(fd2==-1)
  {
    printf("destination file cannot be processed\n");
    exit(0);
  }
  while(1)
    {
      n=read(fd1,&ch,1);
      if(n==0)
      break;
      write(fd2,&ch,1);
    }
  close(fd1);
  close(fd2);
}