%define i 1

%define d i*3
%xdefine xd i*3
%assign a i*3

mov rax, d
mov rax, xd
mov rax, a

%define i 100
mov rax, d
mov rax, xd
mov rax, a

%assign x 1
%assign a 0
%rep 10
%assign a x+a
%assign x x+1
%endrep

result: dq a
