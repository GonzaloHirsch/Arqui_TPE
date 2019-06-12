GLOBAL _cli
GLOBAL _sti
GLOBAL pic_master_mask
GLOBAL pic_slave_mask

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq80Handler

GLOBAL _exception00Handler
GLOBAL _exception06Handler

EXTERN irqDispatcher
EXTERN handleSyscall
EXTERN exceptionDispatcher

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

%macro irqHandlerMaster 1
     pushState
     mov rdi, %1 ; pasaje de parámetro
     call irqDispatcher
     ; signal pic EOI (End of Interrupt)
     mov al, 20h
     out 20h, al
	popState
     iretq
%endmacro

%macro exceptionHandlerMaster 1
    pushState
        mov rdi, %1
        call exceptionDispatcher
        mov al, 20h
        out 20h, al
    popState
    iretq
%endmacro

_irq00Handler:
    irqHandlerMaster 0

_irq01Handler:
    irqHandlerMaster 1

_irq80Handler:

    call handleSyscall

    ; signal pic EOI
    mov al, 20h
    out 20h, al

    iretq

_exception00Handler:
    exceptionHandlerMaster 0

_exception06Handler:
    exceptionHandlerMaster 6

_cli:
	cli
	ret


_sti:
	sti
	ret

pic_master_mask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

pic_slave_mask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  			; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn