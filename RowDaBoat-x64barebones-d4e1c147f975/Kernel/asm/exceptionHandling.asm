GLOBAL printRegisters

extern goToUserland
extern ncNewline
extern ncPrint


section .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro	popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

printRegisters:

    pushState
    mov rdi, rax
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rbx
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rcx
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rdx
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rbp
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rsp
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rdi
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, rsi
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, r8
    call ncPrint
    call ncNewline
    popState

    pushState
    mov rdi, r9
    call ncPrint
    call ncNewline
    popState

    ret