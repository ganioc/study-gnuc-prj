	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2               ## -- Begin function main
LCPI0_0:
	.long	1084227584              ## float 5
LCPI0_1:
	.long	1065353216              ## float 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movss	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	LCPI0_1(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movss	%xmm1, -20(%rbp)
	movss	%xmm0, -24(%rbp)
	movss	-20(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movss	-24(%rbp), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	callq	_add_and_multiply
	xorl	%eax, %eax
	movss	%xmm0, -28(%rbp)
	movl	$1, _nCompletionStatus(%rip)
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_nCompletionStatus      ## @nCompletionStatus
.zerofill __DATA,__common,_nCompletionStatus,4,2

.subsections_via_symbols
