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
  pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10,thread11,thread12;
  pthread_attr_t attribute1;
  pthread_attr_t attribute2;
  pthread_attr_t attribute3;
  pthread_attr_t attribute4;
  pthread_attr_t attribute5;
  pthread_attr_t attribute6;
  pthread_attr_t attribute7;
  pthread_attr_t attribute8;
  pthread_attr_t attribute9;
  pthread_attr_t attribute10;
  pthread_attr_t attribute11;
  pthread_attr_t attribute12;
  int ret1,ret2,ret3,ret4,ret5,ret6,ret7,ret8,ret9,ret10,ret11,ret12;
  int *ptr1,*ptr2,*ptr3,*ptr4,*ptr5,*ptr6,*ptr7,*ptr8,*ptr9,*ptr10,*ptr11,*ptr12;
  pthread_attr_init(&attribute1);
  pthread_attr_init(&attribute2);
  pthread_attr_init(&attribute3);
  pthread_attr_init(&attribute4);
  pthread_attr_init(&attribute5);
  pthread_attr_init(&attribute6);
  pthread_attr_init(&attribute7);
  pthread_attr_init(&attribute8);
  pthread_attr_init(&attribute9);
  pthread_attr_init(&attribute10);
  pthread_attr_init(&attribute11);
  pthread_attr_init(&attribute12);

  ret1=pthread_create(&thread1,&attribute1,fun1,NULL);
  ret2=pthread_create(&thread2,&attribute2,fun2,NULL);
  ret3=pthread_create(&thread3,&attribute3,fun1,NULL);
  ret4=pthread_create(&thread4,&attribute4,fun2,NULL);
  ret5=pthread_create(&thread5,&attribute5,fun1,NULL);
  ret6=pthread_create(&thread6,&attribute6,fun1,NULL);
  ret7=pthread_create(&thread7,&attribute7,fun2,NULL);
  ret8=pthread_create(&thread8,&attribute8,fun1,NULL);
  ret9=pthread_create(&thread9,&attribute9,fun2,NULL);
  ret10=pthread_create(&thread10,&attribute10,fun2,NULL);
  ret11=pthread_create(&thread11,&attribute11,fun1,NULL);
  ret12=pthread_create(&thread12,&attribute12,fun2,NULL);
  printf("First thread retn :%d\n",ret1);
  printf("Second thread retn :%d\n",ret2);
  printf("third thread retn :%d\n",ret3);
  printf("fourth thread retn :%d\n",ret4);
  printf("fifth thread retn :%d\n",ret5);
  printf("sixth thread retn :%d\n",ret6);
  printf("Seventh thread retn :%d\n",ret7);
  printf("eight thread retn :%d\n",ret8);
  printf("nine thread retn :%d\n",ret9);
  printf("ten thread retn :%d\n",ret10);
  printf("eleven thread retn :%d\n",ret11);
  printf("tweleve thread retn :%d\n",ret12);
  pthread_join(thread1,(void*)&ptr1);
  pthread_join(thread2,(void*)&ptr2);
  pthread_join(thread3,(void*)&ptr3);
  pthread_join(thread4,(void*)&ptr4);
  pthread_join(thread5,(void*)&ptr5);
  pthread_join(thread6,(void*)&ptr6);
  pthread_join(thread7,(void*)&ptr7);
  pthread_join(thread8,(void*)&ptr8);
  pthread_join(thread9,(void*)&ptr9);
  pthread_join(thread10,(void*)&ptr10);
  pthread_join(thread11,(void*)&ptr11);
  pthread_join(thread12,(void*)&ptr12);
  return 0;


}

