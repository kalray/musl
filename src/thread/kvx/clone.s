/*
 * __clone(func, stack, flags, arg, ptid, tls, ctid)
 *         r0,   r1,    r2,    r3,  r4,   r5,  r6
 *
 * sys_clone(flags, stack, ptid, ctid, tls)
 *           r0,    r1,    r2,   r3,   r4
 */
.global __clone
.hidden __clone
.type __clone,%function
__clone:
	/* align stack */
	andd $r1 = $r1, -32
	;;
	/* Set clone_flags */
	copyd $r0 = $r2
	addd $r1 = $r1, -32
	/* Save fn ($r0) on child stack */
	sd -32[$r1] = $r0
	;;
	/* Save args ($r3) on child stack */
	sd 8[$r1] = $r3
	/* Set parent_tidptr */
	copyd $r2 = $r4
	/* Set child_tidptr */
	copyd $r3 = $r6
	/* Set tls */
	copyd $r4 = $r5
	;;
	scall 220 /* __NR_clone */
	;;
	/* If 0, then we are the child */
	cb.deqz $r0? 1f
	;;
	/* Else we are the parent */
	ret
	;;

	/* Let's get the child running the correct function */
1:
	/* get fn from stack */
	ld $r1 = 0[$sp]
	;;
	/* Get args from stack */
	ld $r0 = 8[$sp]
	addd $sp = $sp, 32
	;;
	icall $r1
	;;
	scall 93 /* __NR_exit */
	;;
	/* We should never ever get here ! */
	errop
	;;
