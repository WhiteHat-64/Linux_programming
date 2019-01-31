/********************************************************/
/* Author: Vinoth R                                     */
/* Date: 29-01-2019                                     */
/* Filename: my_sem_1.h                                      */
/* Description: Explains semaphore operation            */
/********************************************************/

#ifndef SEM_1_H
#define SEM_1_H

/* Included header files */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Macro Definitions */
#define MY_SEMKEY 2000
#define MY_SHMKEY 1000
#define MY_NSEMS 1
#define MY_SHM_SIZE 8192

/* user defined datatype definitions */
union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

/* function prototypes */


#endif /* SEM_1_H */
