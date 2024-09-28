.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov es,ax
mov bx,0030h
mov cx,0007h
mov dl,0000h
mov si,0040h
mov [si],dl
mov di,0041h
mov [di],dl
l2:
mov al, [bx]
ROL al,01h
jnc l1
mov dl,[di]
inc dl
mov [di],dl
jmp l3
l1:
mov dl,[si]
inc dl
mov [si],dl
l3:
inc bx
loop l2

int 03h
mov ah,4ch
int 21h
main endp
end main
