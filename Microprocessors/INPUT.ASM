.model small
.data
.stack 100h
.code
start:
mov ax,@data
mov ds,ax
call inp
mov bx,bp
call inp
mov cx,bp
add bx,cx
mov ah,4ch
int 21h
inp proc near
push ax
push cx
mov ch,04h
mov cl,04h
xor bp,bp
l2: mov AH,01H
INT 21H
SUB AL,30H
CMP AL,09H
JC l1
sub al,07h
l1:mov ah,0h
shl bp,cl
add bp,ax
dec ch
jnz l2
pop cx
pop ax
ret
inp endp
end

