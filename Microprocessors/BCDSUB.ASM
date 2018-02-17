.model small
.stack 100h
.data
d1 dd 00000000h
d2 dd 00000000h
res dd 00000000h
a db " Error $"
.code
START:
mov ax,@DATA
mov ds,ax

MOV SI, OFFSET D1
CALL INP
MOV [SI+2],BP
CALL INP
MOV [SI],BP

MOV SI, OFFSET D2
CALL INP
MOV [SI+2],BP
CALL INP
MOV [SI],BP

MOV CX,4H
MOV DI,OFFSET D1
MOV BX,OFFSET RES

LP:
MOV AL,[DI]
MOV DL,[SI]
SBB AL,DL
DAS
MOV [BX],AL
INC SI
INC DI
INC BX
DEC CX
JNZ LP

jnc new
MOV SI, OFFSET RES
mov bx,9999h
sub bx,[si]
add bx,1
mov [si],bx
mov bx,9999h
sbb bx,[si+2]
mov [si+2],bx

;mov cx,10h
;a1:
;mov al,[si]
;das
;mov [si],al
;inc si
;dec cx
;jnz a1
new:
MOV SI, OFFSET RES
MOV BP,[SI+2]
CALL OTP
MOV BP,[SI]
CALL OTP




mov ah,4Ch
int 21h

INP PROC NEAR
PUSH CX
MOV BP,0H
MOV CH,04H
MOV CL,04H
L2:MOV AH,01H
INT 21H
SUB AL,30H
CMP AL,0AH
JC L1
MOV DX,OFFSET A
MOV AH,09H
INT 21H
JMP E
L1:XOR AH,AH
SHL BP,CL
ADD BP,AX
DEC CH
JNZ L2
E:
POP CX
RET
INP ENDP



OTP PROC NEAR
PUSH CX
MOV CH,04H
MOV CL,0CH
L4: MOV DX,BP
SHR DX,CL
AND DX,0FH
ADD DL,30H
CMP DL,3AH
MOV AH,02H
INT 21H
SUB CL,04H
DEC CH
JNZ L4
POP CX
RET
OTP ENDP


END


