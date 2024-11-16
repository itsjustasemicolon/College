.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov ax,0000h
mov bx,0000h
mov cx,0001h
mov si,0030h
mov bl,[si]
mov al,bl
l2:
	cmp bl,00h
	jz l1
	dec bl
	cmp bl,00h
	jz l1
	MUL BX
	mov cx,ax
jmp l2

l1:
	mov si,0040h
	mov [si],cx

int 03h
mov ah,4ch
int 21h
main endp
end main
