.model small
.stack 100h
.data
.code

main proc
    mov ax, @data
    mov es, ax
    mov ds, ax
    mov si, 0030h
    mov cx, 0006h

l1:
    mov si, 0030h
    mov bx, cx              

l2:
    mov ax, [si]          
    mov dx, [si + 2]        
    cmp ax, dx              
    jnc l3                

    mov [si], dx          
    mov [si + 2], ax        

l3:
    add si, 2                
    dec bx                  
    jnz l2                

    loop l1                  

    int 03h                  
    mov ah, 4ch            
    int 21h

main endp
end main.model small
.stack 100h
.code
main proc
mov ax, @data
mov ds, ax
mov bl, 06h
l3:
mov si,0030h
mov cl,06h
l1:
mov al,[si]
inc si
cmp al,[si]
jc l2
mov dl,[si]
mov [si],al
dec si
mov [si],al
inc si
l2:
loop l1
dec bl
cmp bl,00h
jnz l3
int 03h
mov ah,4ch
int 21h
main endp
end main
