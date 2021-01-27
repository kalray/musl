#define JMP_BUF_SIZE 176
#define SS_OFFSET JMP_BUF_SIZE+8+8

.global sigsetjmp
.global __sigsetjmp
.type sigsetjmp,@function
.type __sigsetjmp@function
sigsetjmp:
__sigsetjmp:
.hidden ___setjmp
	cb.deqz $r1? ___setjmp
	;;
	get $r2 = $ra
	;;
	sd (JMP_BUF_SIZE)[$r0] = $r2
	;;
	call ___setjmp
	sd (SS_OFFSET)[$r0] = $r18
	copyd $r18 = $r0
	;;
	copyd $r1 = $r0
	copyd $r0 = $r18
	ld $r2 = (JMP_BUF_SIZE)[$r18]
	;;
	ld $r18 = (SS_OFFSET)[$r0]
	set $ra = $r2
	;;

.hidden __sigsetjmp_tail
	goto __sigsetjmp_tail
	;;
