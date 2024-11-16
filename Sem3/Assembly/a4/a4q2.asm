
.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov ds,ax
mov ax,0000h
mov dx,0000h
mov si,0030h
mov cl,[si]
l2:
	cmp cl,00h
	jz l1
	dec cl
	MOV AL,DL
	add al,01h
	daa
	mov dl,al
	mov al,dh
	adc al,00h
	daa
	mov dh,al
jmp l2

l1:
	mov si,0040h
	mov [si],dx

int 03h
mov ah,4ch
int 21h
main endp
end main
