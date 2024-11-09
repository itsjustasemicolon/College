.model small
.stack 100h
.code
main proc
mov ax, @data
mov ds, ax
mov si, 0030h
mov al, [si]
mov cl, 06h
inc si
l1:
cmp al, [si]
jc l2
mov al, [si]
l2:
inc si
loop l1
mov si,0040h
mov [si], al
int 06h
mov ah,4ch
int 21h
main endp
end main

