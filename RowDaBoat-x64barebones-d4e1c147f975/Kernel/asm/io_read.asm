GLOBAL read_key
GLOBAL check_key
GLOBAL read_port
GLOBAL write_port

read_key:
  push rbp
  mov rbp, rsp

	in al, 60h
  and rax, 0ffh

  mov rsp, rbp
  pop rbp
  ret

check_key:
  push rbp
  mov rbp, rsp

  in al, 64h				;lee del puerto 64h
  and al, 01h				;le hace un AND con 0000 0001 para que quede en 1
  cmp al, 01h

  mov rsp, rbp
  pop rbp
  ret

read_port:
  push rbp
  mov rbp, rsp

  ;todo el registro en 0
  mov rax, 0
  ;conservo rdx
  push rdx
  ;muevo el puerto al RDX
  mov rdx, rdi
  ;hago la lectura
  in al, dx
  ;recupero el registro
  pop rdx

  mov rsp, rbp
  pop rbp
  ret

write_port:
  push rbp
  mov rbp, rsp

  ;preservo estos registros
  push rdx
  push rax

  ;cargo el puerto
  mov rdx, rdi
  ;cargo el valor
  mov rax, rsi
  ;hago el write
  out dx, al

  ;recupero los registros
  pop rax
  pop rdx

  mov rsp, rbp
  pop rbp
  ret
