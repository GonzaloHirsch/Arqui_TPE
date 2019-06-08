GLOBAL _cli
GLOBAL _sti
GLOBAL pic_master_mask
GLOBAL pic_slave_mask

GLOBAL _irq00Handler

EXTERN irqDispatcher

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

_irq00Handler:
    irqHandlerMaster 0

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