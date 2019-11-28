global _start

section .data

name_prompt db "Please type your name: ",0
out_msg     db "Your name in capitals is: ",0

section .bss
in_name     resb 31

section .text
_start:
	push 2
	push 3
	call myadd
	; exit
_exit:
	mov rax, 60
	xor rdi, rdi
	syscall

myadd:
	xor rax, rax
	mov rax, [rsp+4]
	add rax, [rsp+8]
	ret 
