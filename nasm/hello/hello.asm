global _start

; constants
%define SYS_WRITE 1
%define SYS_EXIT  60
%define STDOUT    1

section .data
hello     db "Hello world!",10
hello_len equ $-hello
mydata    db "ab",0

section .text

_start:
	mov rax,SYS_WRITE
	mov rdi,STDOUT
	mov rsi,hello
	mov rdx,hello_len
	syscall
	push rax ;; put something , it is num of bytes sent

	;; exit
	mov rax, SYS_EXIT
	pop rdi
	sub rdi,hello_len
	;; mov rdi, 010h
	syscall


