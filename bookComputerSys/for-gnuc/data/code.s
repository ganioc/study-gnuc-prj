	.file	"code.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	leal	(%rdi,%rsi), %eax
	addl	%eax, accum(%rip)
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.globl	accum
	.bss
	.align 4
	.type	accum, @object
	.size	accum, 4
accum:
	.zero	4
	.globl	y
	.data
	.align 4
	.type	y, @object
	.size	y, 4
y:
	.long	1
	.globl	x
	.bss
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.zero	4
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
