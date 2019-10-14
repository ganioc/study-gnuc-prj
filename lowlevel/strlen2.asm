global _start

section .data
test_string: db "abcdefg",0

section .text

strlen:
.loop:
	cmp byte[rdi+r13],0
	je .end
	inc r13
	jmp .loop
.end:
	mov rax, r13
	ret

_start:
	mov rdi, test_string
	call strlen
	mov rdi, rax

	mov rax, 60
	syscall

