section .data
codes:
	db '0123456789ABCDEF'

section .text
global _start
_start:
	mov rax, 0x112233445566778a
	mov rdi,1  ; 1 stdout
	mov rdx,1  ; msg length
	mov rcx,64
.loop:
	push rax
	sub rcx,4

	sar rax,cl
	and rax,0xf

	lea rsi,[codes+rax] ; msg address
	mov rax,1

	; syscall leaves rcx and r11 changed
	push rcx
	syscall
	pop rcx
	pop rax

	test rcx, rcx
	jnz .loop
_exit:
	mov rax,60
	xor rdi,rdi
	syscall


