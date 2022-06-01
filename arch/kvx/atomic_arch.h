/*
 * Atomic compare and exchange: Compare OLD with MEM, if identical,
 * store NEW in MEM. Return the initial value in MEM. Success is
 * indicated by comparing RETURN with OLD.
 */
#define __cmpxchg(ptr, old, new, op_suffix) \
({ \
	__typeof((ptr)) __cxc__ptr = (ptr);                             \
	register unsigned long __cxc__rn __asm__("$r62") = (unsigned long) (new); \
	register unsigned long __cxc__ro __asm__("$r63") = (unsigned long) (old); \
	do {                                                            \
		__asm__ __volatile__ (                                  \
			"acswap" #op_suffix " 0[%[rPtr]], $r62r63\n"    \
			: "+r" (__cxc__rn), "+r" (__cxc__ro)            \
			: [rPtr] "r" (__cxc__ptr)                       \
			: "memory");                                    \
		/* Success */                                           \
		if (__cxc__rn) {                                        \
			__cxc__ro = (unsigned long) (old);              \
			break;                                          \
		}                                                       \
		/* We failed, read value */                             \
		__cxc__ro = (unsigned long) *(__cxc__ptr);              \
		if (__cxc__ro != (unsigned long) (old))                 \
			break;                                          \
		/* __cxc__rn has been cloberred by cmpxch result */     \
		__cxc__rn = (unsigned long) (new);                      \
	} while (1);                                                    \
	(__cxc__ro);                                                    \
})

#define cmpxchg(ptr, o, n) \
({ \
	unsigned long __cmpxchg__ret;                                   \
	switch (sizeof(*(ptr))) {                                       \
	case 4:                                                         \
		__cmpxchg__ret = __cmpxchg((ptr), (o), (n), w);         \
		break;                                                  \
	case 8:                                                         \
		__cmpxchg__ret = __cmpxchg((ptr), (o), (n), d);         \
		break;                                                  \
	}                                                               \
	(__typeof(*(ptr))) (__cmpxchg__ret);                            \
})

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	return cmpxchg(p, t, s);
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
	return (void *)a_cas(p, (uintptr_t)t, (uintptr_t)s);
}
