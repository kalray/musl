/*
 * This file is subject to the terms and conditions of the LGPL V2.1
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2019 Kalray Inc.
 */

#define QUAD_REG_SIZE 32
#define DBL_REG_SIZE 16

/**
 * Simply save the user context to $r0 (jmpbuf)
 *
 * This function has the following prototype:
 * int setjmp (r0 = jmp_buf env)
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
	/* Save r20r21r22r23 */
	so (QUAD_REG_SIZE)[$r0] = $r20r21r22r23
	get $r40 = $ra
	copyd $r36 = $sp
	;;
	/* Save r24r25r26r27 */
	so (2 * QUAD_REG_SIZE) [$r0] = $r24r25r26r27
	get $r41 = $cs
	/* Store $ra and cs*/
	copyd $r38 = $r18
	;;
	copyd $r37 = $r14
	copyd $r39 = $r19
	;;
	/* Save r12(sp) r14 r18 r19 stored in $r36r37r38r39 */
	so (0)[$r0] = $r36r37r38r39
	get $r32 = $lc
	;;
	/* Save r28r29r30r31 */
	so (3 * QUAD_REG_SIZE) [$r0] = $r28r29r30r31
	get $r33 = $le
	;;
	/* Save $cs and $ra */
	sq (4 * QUAD_REG_SIZE)[$r0] = $r40r41
	get $r34 = $ls
	;;
	/* Save $lc, $le and $ls */
	so (4 * QUAD_REG_SIZE + DBL_REG_SIZE)[$r0] = $r32r33r34r35
	make $r0 = 0
	ret
	;;
