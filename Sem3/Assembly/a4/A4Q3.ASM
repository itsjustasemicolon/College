.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov al,[si]
mov bl,al
AND AL,0F0H
mov cl,04h
ror al,cl
mov dl,0Ah
mul dl
mov dx,ax
mov al,bl
and al,0fh
mov ah,00h
add ax,dx
mov si,0040h
mov [si],ax

int 03h
mov ah,4ch
int 21h
main endp
end main
