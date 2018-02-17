;32 BIT MULTIPLICATION
;DEEPTI SHARMA
;BSC(HONS)COMPUTER SCIENCE 3 YR: 2014315

.model SMALL
.386
.stack 100h
.data
a1 dd 00000000H ,2
a2 dd 00000000H ,3
s  db "Enter a number $"
RESULT dd 00000000H ,5
s2 db "Result $"
.code
start:
MOV AX,@data
MOV DS,AX

MOV DX , offset s
mov ah,09h
int 21h
MOV SI,offset a1
CALL INP
ADD SI,2H
MOV [SI],BP
SUB SI,2H
CALL INP
MOV [SI],BP

MOV  EBX,[SI]

MOV Dx ,offset s
mov ah,09h
int 21h
MOV SI,offset a2
CALL INP
ADD SI,2H
MOV [SI],BP
SUB SI,2H
CALL INP
MOV [SI],BP

MOV EAX,[SI]
MUL EBX
MOV SI,offset result
mov [si],eax
add si,04h
mov [si],edx
add si,02h
mov bx,06h
n1:
mov bp,[si]
call otp
sub si,2h
sub bx,2h
jnz n1
mov bp,[si]
call otp

 




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

