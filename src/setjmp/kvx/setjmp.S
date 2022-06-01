#define REG_SIZE 8

/*
 * int setjmp(jmpbuf env)
 * Save the user context to $r0 (jmpbuf)
 * jmpbuf layout:
 * [0]  = $ra,  $sp,  $cs,  $r14,
 * [4]  = $r20, $r21, $r22, $r23,
 * [8]  = $r24, $r25, $r26, $r27,
 * [12] = $r28, $r29, $r30, $r31,
 * [16] = $r18, $r19,
 * [18] = $lc,  $le,  $ls,  xxxx
 */
.global ___setjmp
.hidden ___setjmp
.global __setjmp
.global _setjmp
.global setjmp
.type __setjmp,@function
.type _setjmp,@function
.type setjmp,@function
___setjmp:
__setjmp:
_setjmp:
setjmp:
	sq (16 * REG_SIZE)[$r0] = $r18r19
	get $r40 = $ra
	copyd $r41 = $sp
	;;
	so (4 * REG_SIZE)[$r0] = $r20r21r22r23
	get $r42 = $cs
	copyd $r43 = $r14
	;;
	so (0 * REG_SIZE)[$r0] = $r40r41r42r43
	get $r40 = $lc
	;;
	so (8 * REG_SIZE)[$r0] = $r24r25r26r27
	get $r41 = $le
	;;
	so (12 * REG_SIZE)[$r0] = $r28r29r30r31
	get $r42 = $ls
	;;
	so (18 * REG_SIZE)[$r0] = $r40r41r42r43
	make $r0 = 0
	ret
	;;
