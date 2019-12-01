;; maintest.asm
%include "./lib.inc.asm"

%define MAX_NUM 9

section .data

newline_char : db 10
codes:         db '0123456789abcdef'
demo1:         dq 0x1122334455667788
demo2:         db 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88
str  :         db 'Selling England by the Pound', 0
test_string:   db 'hello world',0
num_byte:      db 0

section .text
global  _start

strlen:
	xor rax, rax
.loop:
	cmp byte[rdi+rax],0
	je .end
	inc rax
	jmp .loop
.end:
	ret ;; rax contain the string length

print_newline:
	mov rax,1
	mov rdi,1
	mov rsi,newline_char
	mov rdx,1
	syscall
	ret
print_byte:
	mov rax,rdi
	and rax,0xf
	lea rsi,[codes + rax]

	mov rdi,1
	mov rdx,1
	mov rax,1
	syscall
	ret

print_hex:
	mov rax,rdi
	mov rdi,1
	mov rdx,1
	mov rcx,64
iterate:
	push rax
	sub rcx, 4
	sar rax,cl
	and rax,0xf
	lea rsi,[codes + rax]
	mov rax,1
	push rcx
	syscall
	pop rcx

	pop rax
	test rcx,rcx
	jnz iterate

	ret

print_9to0:
	;; print 0~9 number
	mov rcx,MAX_NUM
.p_start:
	cmp rcx,-1
	je .p_end
	mov rdi,rcx
	push rcx
	call print_byte
	pop rcx
	sub rcx,1
	jmp .p_start
.p_end:
	call print_newline
	ret

_start:
	mov rdi,0x1122334455667788
	call print_hex
	call print_newline
	call print_newline
	
	mov rdi,[demo1]
	call print_hex
	call print_newline

	mov rdi,[demo2]
	call print_hex
	call print_newline

	mov rdi, test_string
	call strlen
	mov rdi,rax
	mov [num_byte],rdi

	;; print the length out
	mov rdi,[num_byte]
	call print_byte
	call print_newline

	call print_9to0

_exit:
	EXIT

