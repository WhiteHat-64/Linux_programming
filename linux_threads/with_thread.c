#include<stdio.h>
#include<pthread.h>
//#include<error.h>
void* fun1(void *  arg1)
{
  unsigned long long  int i,add;
   for(i=0,add=0;  i<11000000; i++)
   {
     add=add+i;
   }
   printf("%u\n",add);

}
void* fun2(void * arg2)
{
   unsigned long long int i,add;
   for(i=0,add=0;  i<22000000; i++)
   {
     add=add+i;
   }
   printf("%u\n",add);

}

int main()
{
  pthread_t thread1,thread2,thread3,thread4;
  pthread_attr_t attribute1;
  pthread_attr_t attribute2;
  pthread_attr_t attribute3;
  pthread_attr_t attribute4;
  int ret1,ret2,ret3,ret4;
  int *ptr1,*ptr2,*ptr3,*ptr4;
  pthread_attr_init(&attribute1);
  pthread_attr_init(&attribute2);
  pthread_attr_init(&attribute3);
  pthread_attr_init(&attribute4);

  ret1=pthread_create(&thread1,&attribute1,fun1,NULL);
  ret2=pthread_create(&thread2,&attribute2,fun2,NULL);
  ret3=pthread_create(&thread3,&attribute3,fun1,NULL);
  ret4=pthread_create(&thread4,&attribute4,fun2,NULL);
  printf("First thread retn :%d\n",ret1);
  printf("Second thread retn :%d\n",ret2);
  printf("third thread retn :%d\n",ret3);
  printf("fourth thread retn :%d\n",ret4);
  pthread_join(thread1,(void*)&ptr1);
  pthread_join(thread2,(void*)&ptr2);
  pthread_join(thread3,(void*)&ptr3);
  pthread_join(thread4,(void*)&ptr4);
  return 0;


}

