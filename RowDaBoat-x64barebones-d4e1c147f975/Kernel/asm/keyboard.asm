GLOBAL read_key

read_key:
_loop:
	in al, 64h				;lee del puerto 64h
	and al, 01h				;le hace un AND con 0000 0001 para que quede en 1
	cmp al, 01h				;compara para ver que haya quedado en 0000 0001
	jz _show				
	jmp _loop
_show:
	in al, 60h	
    ret