#include<stdio.h>
void fun1(void )
{
  unsigned long long  int i,add;
   for(i=0,add=0;  i<11000000; i++)
   {
     add=add+i;
   }
   printf("%llu\n",add);

}
void fun2(void )
{
   unsigned long long int i,add;
   for(i=0,add=0;  i<22000000; i++)
   {
     add=add+i;
   }
   printf("%llu\n",add);

}

main()
{
   fun1();
   fun1();
   fun2();
   fun2();
   fun1();
   fun1();
   fun1();
   fun2();
   fun2();
   fun1();
   fun2();
   fun2();

}


