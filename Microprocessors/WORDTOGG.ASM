;WORD TOGGLE
;DEEPTI SHARMA
;BSC(HONS)COMPUTER SCIENCE 3 YR: 2014315
.model small
.stack 100h
.data
d1 dd 00000000H
array dw 1,2,3,4,5,6,7,8,9,10
a db "Enter number $"

.code
start:
MOV AX,@data
MOV DS,AX

mov bx,0h
mov si, offset array
l:
call inp
mov [si+bx],bp
mov ax,bp
sub ax,2000h
jb a1
mov dx,[si+bx]
mov ah,dl
mov al,dh
mov [si+bx],ax
a1:
inc bx
inc bx
cmp bx,20h

jne l

MOV AH,4CH
INT 21H

INP PROC NEAR
MOV BP,0H
MOV CH,04H
MOV CL,04H
L2:MOV AH,01H
INT 21H
SUB AL,30H
CMP AL,0AH
JC L1
SUB AL,07H
L1:XOR AH,AH
SHL BP,CL
ADD BP,AX
DEC CH
JNZ L2
RET
INP ENDP


OTP PROC NEAR
MOV CH,04H
MOV CL,0CH
L4: MOV DX,BP
SHR DX,CL
AND DX,0FH
ADD DL,30H
CMP DL,3AH
JC L3
ADD DL,07H
L3: MOV AH,02H
INT 21H
SUB CL,04H
DEC CH
JNZ L4
RET
OTP ENDP


END
