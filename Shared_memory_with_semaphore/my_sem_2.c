/********************************************************/
/* Author: Vinoth R                                     */
/* Date: 29-01-2019                                     */
/* Filename: my_sem_2.c                                 */
/* Description: Explains semaphore operation            */
/********************************************************/

/* Included header file */
#include "my_sem_2.h"

/* Global variable definitions */


/* function definitions */
int main(int argc, char** argv)
{
    int sem_id;
    int shm_id;
    int * shm_addr;
    int loop1;
    int ret_semctl;
    int ret_semop;

    union semun sem_union1;
    struct sembuf my_sembuf;
    
    /* semaphore creation with MY_SEMKEY as key*/
    /* int semget(key_t key, int nsems, int semflg); */
    sem_id =  semget(MY_SEMKEY, MY_NSEMS, 0);
    
    //if(-1 == sem_id)
    {
    perror("semget: ");
    //exit(1);
    }
    
    /* shared memory creation with MY_SHMKEY as key*/
    /* int shmget(key_t key, size_t size, int shmflg); */
    shm_id = shmget(MY_SHMKEY, MY_SHM_SIZE, 0);
    
    //if(-1 == shm_id)
    {
    perror("shmget: ");
    //exit(2);
    }
    
    /* Attaching process to shared memory segment */
    /* void *shmat(int shmid, const void *shmaddr, int shmflg); */
    shm_addr = shmat(shm_id, NULL, 0 /* By default shared memory is opened with read and write permission */);
    
    //if((void *) -1 == shm_addr)
    {
    perror("shmat: ");
    //exit(3);
    }
    
    
    /* performing a reduce operation to get lock using semop */
    /*semop will be done on first semaphore of the semaphore array, in this program only one semaphore is created*/
    my_sembuf.sem_num = 0; 
    
    /*requesting kernel to reduce the semaphore value by 1, as this process reads from shared memory*/
    my_sembuf.sem_op = -1;
    
    /* sem_flg is set to SEM_UNDO which is to ensure that, if the process is terminated,
     *the operation done on the semaphore will be reverted back, to avoid deadlock situation */
    my_sembuf.sem_flg = SEM_UNDO;
    
    /* Getting the semaphore lock using semop */
    /* int semop(int semid, struct sembuf *sops, size_t nsops); */
    ret_semop =  semop(sem_id, &my_sembuf, 1);
    
    //if(-1 == ret_semop)
    {
    perror("semop: ");
    //exit(5);
    }
    
    /* Accessing data, here is the place where possible data corruption can happen, 
     * when multiple process tries to access data, so get a semaphore lock, and access data, then release the lock */
    printf("reading the critical area\n");
    
    for (loop1 = 0; loop1 < MY_SHM_SIZE/4; loop1++)
    {
        printf("Data from shared memory: %d\n",shm_addr[loop1]);
    }
    
    /*while accessing the critical area, there should not be any sleep, or similar functions
     *as the other processes waiting for the lock will be blocked for long time */
    /* Here sleep is added for demonstration purpose */
    sleep(10);
    printf("Exiting the critical area\n");
    
    /* requesting kernel to increase the semaphore value by 4 */
    my_sembuf.sem_op = 1;
    
    /* SEM_UNDO is not required, so replacing it with 0 */
    my_sembuf.sem_flg = 0;
    
    /* releasing the semaphore lock using semop */
    /* int semop(int semid, struct sembuf *sops, size_t nsops); */
    ret_semop =  semop(sem_id, &my_sembuf, 1);
    
    //if(-1 == ret_semop)
    {
    perror("semop: ");
    //exit(6);
    }
    sleep(10);
    
    /*detaching process from shared memory*/
    shmdt(shm_addr);
    perror("shmdt: ");
    
    /*removing semaphore*/
    /* int semctl(int semid, int semnum, int cmd, ...); */
    semctl(sem_id,0,IPC_RMID);
    perror("semctl: ");
    
    /*removing shared memory*/
    shmctl(shm_id, IPC_RMID, NULL);
    perror("shmctl: ");
    
    return 0;
}



