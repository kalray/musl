.global __cp_begin
.hidden __cp_begin
.global __cp_end
.hidden __cp_end
.global __cp_cancel
.hidden __cp_cancel
.hidden __cancel
.global __syscall_cp_asm
.hidden __syscall_cp_asm
.type   __syscall_cp_asm,@function
__syscall_cp_asm:
__cp_begin:
	lwz $r0 = 0[$r0]
	;;
	cb.dnez $r0? __cp_cancel
	;;
	copyd $r16 = $r1
	copyd $r0 = $r2
	copyd $r1 = $r3
	copyd $r2 = $r4
	;;
	copyd $r3 = $r5
	copyd $r4 = $r6
	copyd $r5 = $r7
	copyd $r6 = $r16
	;;
	scall $r6
	;;
__cp_end:
	ret
	;;
__cp_cancel:
	goto	__cancel
	;;
