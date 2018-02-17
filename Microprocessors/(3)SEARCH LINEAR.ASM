BBBBBB;LINEAR SEARCH
;DEEPTI SHARMA
;BSC(HONS)COMPUTER SCIENCE 3 YR: 2014315

.model small
.stack 100h
.data
Arr dw 1,2,3,47AFH,5,6,11H,8,888EH ,0ABCDH
a db "Enter no to be searched:$" 
s db "Not found $"
.code
START:
MOV AX,@data
MOV DS,AX

MOV DX,OFFSET a
mov ah,09H
int 21h
CALL INP
mov ax,bp

MOV DX,0AH
MOV CX,1 
MOV SI,0h

lp:
CMP Arr[SI],AX
JNZ a1
JZ a2
a1:
add si,2h
inc cx
dec dx
jnz lp

mov dx,offset s
mov ah,09h
int 21h
jmp e

a2:

mov bp,cx
call otp

e: 

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

