; title


global _start

section .data
message db 'Hello',10, 0
input_prompt db "Please enter at most 10 numbers: ",0
end_msg      db "No more numbers? Enter 0 to end: " ,0
sum_msg      db "The sum is: ",0
variable     db "ABC",0

section .bss


section .text
_start:
	mov rax,1  ; write
	mov rdi, 1 ; 1 
	mov rsi, message
	mov rdx, 6
	syscall
	
	; read a byte from stdin
	mov rax,0 ; read
	mov rdi,0 ; read from 0
	mov rsi,variable
	mov rdx,1
	syscall
	
	; print out the variable
	mov rax,1
	mov rdi,1
	mov rsi,variable
	mov rdx,1
	syscall

_exit:
	mov rax, 60 ; exit()
	xor rdi, rdi
	syscall






