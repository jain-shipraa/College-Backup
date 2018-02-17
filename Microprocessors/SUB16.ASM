.model small
.stack 100h
.data
d db "-$"
.code
start:
MOV AX,@data
MOV DS,AX
call inp
mov bx,bp
call inp
sub bx,bp
mov bp,bx
jnc a2
mov ax,0h
sub ax,bx
MOV BP,AX
mov dx,offset d
mov ah,09h
int 21h
a2:
call otp


MOV AH,4CH
INT 21H

INP PROC NEAR
PUSH CX
PUSH DX
PUSH AX
PUSH BX
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
POP BX
POP AX
POP DX
POP CX
RET
INP ENDP


OTP PROC NEAR
PUSH CX
PUSH DX
PUSH BX
PUSH AX
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
POP AX
POP BX
POP DX
POP CX
RET
OTP ENDP


END

