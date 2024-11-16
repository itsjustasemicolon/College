.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov ax,0000h

mov al,[si]
mov bl,al

clc
rcr al,01h

xor al,bl

mov si,0040h
mov [si],ax

int 03h
mov ah,4ch
int 21h
main endp
end main
