%define cat_count 42
mov rax, cat_count

%macro test 3
dq %1
dq %2
dq %3
%endmacro

test 6 5 4

