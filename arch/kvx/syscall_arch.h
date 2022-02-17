#ifndef __clang__

/* Mark all arguments registers as per ABI in the range r1-r5 as
   clobbered when they are not used for the invocation of the scall */
#define ASM_CLOBBERS "cc", "memory",					\
    "r7", "r8", "r9", "r10", "r11", /* unused argument registers */ \
    "r15", /* struct pointer */						\
    "r16", "r17", /* veneer registers */				\
    "r32", "r33", "r34", "r35", "r36", "r37", "r38", "r39", /* 32->63 are caller-saved */ \
    "r40", "r41", "r42", "r43", "r44", "r45", "r46", "r47",		\
    "r48", "r49", "r50", "r51", "r52", "r53", "r54", "r55",		\
    "r56", "r57", "r58", "r59", "r60", "r61", "r62", "r63"

static __inline long __syscall0(long n)
{
	register unsigned long _ret __asm__("r0");
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno) 
		     :  "r1", "r2", "r3", "r4", "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall1(long n, long a)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret) 
		     :  "r1", "r2", "r3", "r4", "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall2(long n, long a, long b)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _b __asm__("r1") = b;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret), "r"(_b)
		     :  "r2", "r3", "r4", "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall3(long n, long a, long b, long c)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _b __asm__("r1") = b;
	register unsigned long _c __asm__("r2") = c;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret), "r"(_b), "r"(_c)
		     :  "r3", "r4", "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall4(long n, long a, long b, long c, long d)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _b __asm__("r1") = b;
	register unsigned long _c __asm__("r2") = c;
	register unsigned long _d __asm__("r3") = d;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret), "r"(_b), "r"(_c), "r"(_d)
		     :  "r4", "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _b __asm__("r1") = b;
	register unsigned long _c __asm__("r2") = c;
	register unsigned long _d __asm__("r3") = d;
	register unsigned long _e __asm__("r4") = e;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret), "r"(_b), "r"(_c), "r"(_d), "r"(_e)
		     :  "r5", ASM_CLOBBERS );
	return _ret;
}

static __inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	register unsigned long _ret __asm__("r0") = a;
	register unsigned long _b __asm__("r1") = b;
	register unsigned long _c __asm__("r2") = c;
	register unsigned long _d __asm__("r3") = d;
	register unsigned long _e __asm__("r4") = e;
	register unsigned long _f __asm__("r5") = f;
	register unsigned long _scno  __asm__("r6") = n;

	__asm__ __volatile__("scall %[r_scno]"
		     : "=r" (_ret)
		     : [r_scno] "r" (_scno), "r"(_ret), "r"(_b), "r"(_c), "r"(_d), "r"(_e), "r"(_f)
		     : ASM_CLOBBERS );
	return _ret;
}

#else

#undef SYSCALL_NO_INLINE
#define SYSCALL_NO_INLINE

#endif

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

/*  Linux provides two set of syscalls handler for msgctl, semctl,
    shmctl. An older set which parses IPC_64 version from the function
    cmd argument and a new set which hardcodes IPC_64 version.
    In kvx-linux we use the newer set, therefore we musn't pass IPC_64 version
    in cmd */
#define IPC_64 0
