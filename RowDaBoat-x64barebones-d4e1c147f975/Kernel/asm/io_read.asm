GLOBAL read_key
GLOBAL check_key

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
