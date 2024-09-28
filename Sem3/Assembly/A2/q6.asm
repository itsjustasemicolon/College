.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov es,ax
mov bx,0030h
mov si,0040h
mov di,0050h
mov cx,0007h
l3:
mov al,[bx]
ror al,01h
jnc l1
rol al,01h
mov [di],al
inc di
jmp l2
l1:
rol al,01h
mov [si],al
inc si
l2:
inc bx
loop l3

int 03h
mov ah,4ch
int 21h
main endp
end main
