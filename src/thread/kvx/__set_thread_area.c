#include "pthread_impl.h"
#include "libc.h"
#include <elf.h>

int __set_thread_area(void *p)
{
        __asm__ __volatile__ ("copyd $r13 = %[tp]\n;;\n"
                              : /* "No outputs. */
                              : [tp] "r"(p)
                              : "r13");
        return 0;
}
