#include<stdio.h>
#include<string.h>

void memLeak( )
{
  int *data = new int;
  *data = 15;
  printf("NAT : %d",*data);
}

int main(int argc, char *argv[])
{
	memLeak();
}