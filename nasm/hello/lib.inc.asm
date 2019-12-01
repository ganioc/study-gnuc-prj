;; lib.inc
;; To do chap 2 , exercises

%define Author        "Spikey"
%define DEFAULT_NUM   12

%macro EXIT 0
	mov rax,60
	syscall
	ret
%endmacro
