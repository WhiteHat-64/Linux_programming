/********************************************************/
/* Author: Vinoth R                                     */
/* Date: 29-01-2019                                     */
/* Filename: my_sem.h                                      */
/* Description: Explains semaphore operation            */
/********************************************************/

#ifndef SEM_H
#define SEM_H

/* Included header files */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

/* Macro Definitions */
#define MY_SEMKEY 2000
#define MY_SHMKEY 1000
#define MY_NSEMS 1
#define MY_SHM_SIZE 8192

/* user defined datatype definitions */

/* function prototypes */


#endif /* SEM_H */
