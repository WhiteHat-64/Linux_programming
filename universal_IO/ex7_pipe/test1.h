#ifndef TEST1_H
#define TEST1_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#ifdef DEBUG_CODE
#define  printlog(fmt,arg) printf("%s:%d: "fmt "\n", __FILE__, __LINE__, arg);
#else
#define  printlog(fmt,arg) printf(fmt"\n", arg);
#endif

#endif //TEST1_H
