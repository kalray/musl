#include "pthread_impl.h"
#include "libc.h"
#include <elf.h>

int __set_thread_area(void *p)
{
	__asm__ __volatile__ ("copyd $r13 = $r0\n;;\n");
	return 0;
}
