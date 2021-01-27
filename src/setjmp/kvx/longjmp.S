#define REG_SIZE 8

/* void __longjmp(__jmp_buf __env, int __val) */
.global _longjmp
.global longjmp
.type _longjmp,@function
.type longjmp,@function
_longjmp:
longjmp:
	lo $r40r41r42r43 = (0 * REG_SIZE)[$r0]
	;;
	lo $r44r45r46r47 = (18 * REG_SIZE)[$r0]
	set $ra = $r40
	copyd $sp = $r41
	;;
	lo $r20r21r22r23 = (4 * REG_SIZE)[$r0]
	set $cs = $r42
	copyd $r14 = $r43
	;;
	lo $r24r25r26r27 = (8 * REG_SIZE)[$r0]
	set $lc = $r44
	;;
	lo $r28r29r30r31 = (12 * REG_SIZE)[$r0]
	set $le = $r45
	;;
	lq $r18r19 = (16 * REG_SIZE)[$r0]
	set $ls = $r46
	;;
	/* According to man, if retval is equal to 0, then we should return 1 */
	maxud $r0 = $r1, 1
	ret
	;;
