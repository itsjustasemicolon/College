dosseg
.model small
.stack 100h
.data
.code

main proc
mov ax,@data
mov es,ax
mov ds, ax
mov si,0030h
mov di,0040h
mov bx,0050h
mov cx,0009h

l1:
	mov al,[si]
	add al,[di]
	mov [bx],al
	inc di
	inc bx
	inc si
	loop l1

int 03h
mov ah,4ch
int 21h    

main endp
end main
