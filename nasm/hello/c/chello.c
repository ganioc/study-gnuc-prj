#include <stdio.h>

int main() {
    // int num = 24;
    // char name[] = "CHN";

    __asm__(
	""
	:
	: 
	: "rax", "rdx");

    return printf("Hello World!\n") - 13; }
