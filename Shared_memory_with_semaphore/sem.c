/********************************************************/
/* Author: Vinoth R                                     */
/* Date: 29-01-2019                                     */
/* Filename: sem.c                                      */
/* Description: Explains semaphore operation            */
/********************************************************/

/* Included header file */
#include "sem.h"

/* Global variable definitions */


/* function definitions */
int main(int argc, char** argv)
{  
    int sem_id;
    int shm_id;
    int * shm_addr;
    /* semaphore creation with MY_SEMKEY as key*/
    /* int semget(key_t key, int nsems, int semflg); */
    sem_id =  semget(MY_SEMKEY, MY_NSEMS, IPC_CREAT | IPC_CREAT | 0640);
    
    /* shared memory creation with MY_SHMKEY as key*/
    /* int shmget(key_t key, size_t size, int shmflg); */
    shm_id = shmget(MY_SHMKEY, MY_SHM_SIZE, IPC_CREAT | IPC_CREAT | 0640);
    
    /* Attaching process to shared memory segment */
    /* void *shmat(int shmid, const void *shmaddr, int shmflg); */
    shm_addr = shmat(shm_id, NULL, 0 /* By default shared memory is opened with read and write permission */);
    
    
}



