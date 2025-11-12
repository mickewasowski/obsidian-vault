#include <stdio.h>
int main()
{
  char asd = 127; // by default they signed (meaning with negavite and positive values)
  // it overflows if you set a value out of its bounds

  unsigned char asd2 = 130; // this will allow only positive values
  // this would also wrap it
  
  // the above wrapping behavior also depends on the compiler -> it might wrap it, it might throw a warning or crash the compile process

  printf("Hi there \n");
  return 0; // means success
}
