/* kvx uses variant I, but with the twist that tp points to the end of TCB */
static inline uintptr_t __get_tp()
{
	uintptr_t tp;
	__asm__ ("copyd %0 = $r13\n"
		 ";;"
		 : "=r" (tp));
	return tp;
}

#define MC_PC pc
#define GAP_ABOVE_TP 0
#define TLS_ABOVE_TP
#define TPOFF_K (0)
