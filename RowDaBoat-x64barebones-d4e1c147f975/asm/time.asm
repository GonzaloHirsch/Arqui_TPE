GLOBAL getTimeParticle

section .text


;;getTimeParticle devuelve la particula de tiempo
;;especificada a partir de un int que se corresponde
;;con los establecidos por la documentacion de RTC
getTimeParticle: 
	
	push rbp
	mov rbp, rsp

	mov rax, 0
	mov al, byte [rbp + 8]
	out 70h, al
	in ax, 71h
	int 80h

	mov rsp, rbp
	pop rbp
	ret