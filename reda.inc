DrawGame macro 
mov ah,0
mov al,13h
int 10h

mov verticalend,133
mov horizotalpostion,18
;call drawvertical


mov verticalend,155
mov horizotalpostion,40
;call drawvertical


mov verticalend,174
mov horizotalpostion,160
;call drawvertical


mov verticalend,133
mov horizotalpostion,300
;call drawvertical


mov verticalend,155
mov horizotalpostion,279
;call drawvertical

mov endrow,320
mov colnum,133
call drawhorziontal
;////////////////////////////////////////
cmp Levelnum,31h
jnz Gameleveltwo
mov verticalstart,145
mov verticalend,155
mov horizotalpostion,10
call drawvertical

mov verticalstart,145
mov horizotalpostion,310
call drawvertical

Gameleveltwo:
mov colnum,155
call drawhorziontal

mov colnum,174
call drawhorziontal

;//draw the rectangel of the game of the flying birds
mov colnum,143
mov startrow , 50
mov endrow,80
call drawhorziontal
mov colnum,153
mov startrow , 50
mov endrow,80
call drawhorziontal
mov verticalstart,143
mov verticalend,153
mov horizotalpostion,50
call drawvertical
mov verticalstart,143
mov horizotalpostion,80
call drawvertical






mov endrow,36
mov colnum,9
drawcells1:
	;;call drawhorziontal
	add colnum,9
cmp colnum,144
jnz drawcells1


mov colnum,9
mov endrow,320
mov startrow,284
drawcells2:
	;;call drawhorziontal
	add colnum,9
cmp colnum,144
jnz drawcells2

;/////////////////////////////////////////////////
;draw the registers vertical lines
mov horizotalpostion,50
;;call drawregsver

;draw the registers horziontal lines
;the below line
mov colnum,24
mov startrow,50
mov endrow,90
;call drawregshor

;the above line
mov colnum,14
mov startrow,50
mov endrow,90
;call drawregshor



;the second four regs
;draw the registers vertical lines
mov horizotalpostion,100
;call drawregsver



;draw the registers horziontal lines
;the below line
mov colnum,24
mov startrow,100
mov endrow,140
;call drawregshor

;the above line
mov colnum,14
mov startrow,100
mov endrow,140
;call drawregshor


;/////////////draw the regs to the second user


;draw the registers vertical lines
mov horizotalpostion,185
;;call drawregsver

;draw the registers horziontal lines
;the below line
mov colnum,24
mov startrow,185
mov endrow,225
;;call drawregshor

;the above line
mov colnum,14
mov startrow,185
mov endrow,225
;;call drawregshor



;the second four regs
;draw the registers vertical lines
mov horizotalpostion,235
;;call drawregsver



;draw the registers horziontal lines
;the below line
mov colnum,24
mov startrow,235
mov endrow,275
;;call drawregshor

;the above line
mov colnum,14
mov startrow,235
mov endrow,275
;;call drawregshor



;///start write the words
mov yx,0003
;call fillmemocells1

mov yx,0035
;call fillmemocells1

mov yx,0000
;call fillmemocells2


mov yx,0038
;call fillmemocells2


mov user, 1
;call fillmemo

mov user, 2
;call fillmemo

mov RegsPosition,7
;call fillreg

mov registerscount,4
mov RegsPosition,24
;call fillreg
mov yx,0107h
;call fillthenamesoftheregs

mov yx,0118h
;call fillthenamesoftheregs

mov user,1
mov bx,0
;call Regtype
call converttostring
;call Regvalue

mov bx,2
;call Regtype
call converttostring
;call Regvalue



;call Regtype
call converttostring
;call Regvalue




;call Regtype
call converttostring
;call Regvalue



;call Regtype
call converttostring
;call Regvalue



;call Regtype
converttostring regvalues
;call Regvalue



;call Regtype
converttostring regvalues
;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue


mov user,2
mov bx,0
;call Regtype
converttostring regvalues

;call Regvalue


mov bx,2
;call Regtype
 converttostring regvalues

;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue



;call Regtype
converttostring regvalues

;call Regvalue
;call usersnames
;call Inlinechat
call showforbiddenchar
mov yx,1100h
call scoretext
mov yx,1123h
call scoretext
endm DrawGame

;/////////////////////////////////////////////////////////////////
;Memory and Registers
Fillmemo proc near
pusha 
pushf
cmp user,1 
jnz default
mov yx,0000
jmp startfill
default: mov yx,0038
startfill:
mov dx,yx
;by using the bx use the bl
add dh,bl
mov yx,dx
mov countmemo, 2
mov si, 0
converttostring memolocationvalue
mov bh, 1
li22:
call setCursor
            mov ah,9
            mov al, memolocationvalue[si]
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
			inc yx
			inc si
	dec countmemo
cmp countmemo,0
jnz li22


popf 
popa
ret
endp 


fillmemocells1 proc near 
pusha
pushf
mov memosize, 16
mov bh,1
mov si,0
li:mov countmemo, 2

li2:call setCursor
            mov ah,9
            mov al, memo1[si]
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
			inc yx
			inc si
	dec countmemo
jnz li2
mov cx,yx
inc ch
dec cl
dec cl
mov yx,cx
dec memosize
cmp memosize , 0
jnz li 
popf
popa
ret
endp


fillmemocells2 proc near 
pusha
pushf
mov memosize, 16
mov bh,1
mov si,0
li3:mov countmemo, 2

li4:call setCursor
            mov ah,9
            mov al, memo2[si]
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
			inc yx
			inc si
	dec countmemo
jnz li4
mov cx,yx
inc ch
dec cl
dec cl
mov yx,cx
dec memosize
cmp memosize , 0
jnz li3 
popf
popa
ret
endp
     
fillreg proc near
pusha
pushf
    mov bh, 1  
    mov dh, 2
    mov dl, RegsPosition
    mov yx, dx
    label1:
    mov countmemo, 2
    label2:
    mov regSize, 4
    label3:
    call setCursor
            mov ah,9            
            mov al, '0'
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
            inc yx
    dec regSize
    jnz label3
    
    add dl, 6
    mov yx, dx
    dec countmemo
    jnz label2
    mov dl, RegsPosition
    add dh, 3
    mov yx, dx
    dec registerscount
    jnz label1
popf
popa
ret
endp





;//////////////////////////////////////////////////////////////////////////////
drawvertical proc near 
pusha
pushf
mov bh,1
mov cx,horizotalpostion
mov dx,verticalstart
mov al,0fh
mov ah , 0ch
condraw: int 10h
inc dx
cmp dx,verticalend
jnz condraw
popf
popa
ret
endp

drawhorziontal proc near 
pusha
pushf
mov bh,1
mov cx,startrow
mov dx,colnum
mov al,0fh
mov ah , 0ch
condraw2: int 10h
inc cx
cmp cx,endrow
jnz condraw2
popf
popa
ret
endp




drawregsver proc near 
pusha
pushf
mov si,2
loopregs1:
	mov verticalstart,14
	mov verticalend,24
drawregs1:
	;call drawvertical
	add verticalend,24
	add verticalstart,24
cmp verticalend,96
jle drawregs1
add horizotalpostion,40
dec si
cmp si,0
jnz loopregs1

popf
popa
ret
endp

drawregshor proc near 
pusha
pushf

drawregshor1:
	;call drawhorziontal
	add colnum,24
cmp colnum,100
jle drawregshor1

popf
popa
ret
endp
;//////////////////////function to set the value in the regs 
;this function takes the name of the reg and the user value if user1 takes 1 if the second user takes 2
Regtype proc near
pusha
pushf

cmp user,1 
jnz usertwo



cmp bx,0    ;al
jnz secondcheckreg3
mov regposition,0207h
jmp setlocation1



secondcheckreg3:
cmp bx,1    ;ah
jnz Thridcheck
mov regposition,0209h
jmp setlocation1

Thridcheck:
cmp bx,4  ;cl
jnz Thridcheck3
mov regposition,0507h
jmp setlocation1



Thridcheck3:
cmp bx,5  ;ch
jnz fourcheck3
mov regposition,0509h
jmp setlocation1

fourcheck3:
cmp bx,2  ;bl
jnz fourcheck
mov regposition,0807h
jmp setlocation1

fourcheck:
cmp bx,3  ;bh
jnz fifthckeck3
mov regposition,0809h
jmp setlocation1

fifthckeck3:
cmp bx,6  ;dl
jnz fifthckeck
mov regposition,0b07h
jmp setlocation1

fifthckeck:
cmp bx,7  ;dh 
jnz sixckeck5
mov regposition,0b09h
jmp setlocation1


sixckeck5:  ;sil
cmp bx,8
jnz Sixcheck3
mov regposition,020dh
jmp setlocation1


Sixcheck3:  ;sih
cmp bx,9
jnz sevevcheck
mov regposition,020fh
jmp setlocation1


sevevcheck:  ;dil
cmp bx, 0ah
jnz sevevcheck3
mov regposition,050dh
jmp setlocation1


sevevcheck3:
cmp bx,0bh		;dih
jnz eightcheck3
mov regposition,050fh
jmp setlocation1

eightcheck3:
cmp bx,0ch    ; spl
jnz eightcheck		
mov regposition,080dh
jmp setlocation1

eightcheck:
cmp bx,0dh    ; sph
jnz ninecheck3		
mov regposition,080fh
jmp setlocation1

ninecheck3:
cmp bx,0eh    ; Bpl
jnz ninecheck		
mov regposition,0B0dh
jmp setlocation1

ninecheck:
cmp bx,0fh    ; Bph
jmp setlocation1	
mov regposition,0B0fh
jmp setlocation1


usertwo:


cmp bx,0    ;al
jnz secondcheckreg4
mov regposition,0218h
jmp setlocation1



secondcheckreg4:
cmp bx,1    ;ah
jnz Thridcheck1
mov regposition,021Ah
jmp setlocation1

Thridcheck1:
cmp bx,4  ;cl
jnz Thridcheck4
mov regposition,0518h
jmp setlocation1



Thridcheck4:
cmp bx,5  ;ch
jnz fourcheck4
mov regposition,051Ah
jmp setlocation1

fourcheck4:
cmp bx,2  ;bl
jnz fourcheck1
mov regposition,0818h
jmp setlocation1

fourcheck1:
cmp bx,3  ;bh
jnz fifthckeck4
mov regposition,081Ah
jmp setlocation1

fifthckeck4:
cmp bx,6  ;dl
jnz fifthckeck1
mov regposition,0b18h
jmp setlocation1

fifthckeck1:
cmp bx,7  ;dh 
jnz sixckeck1
mov regposition,0b1Ah
jmp setlocation1


sixckeck1:  ;sil
cmp bx,8
jnz Sixcheck4
mov regposition,021eh
jmp setlocation1


Sixcheck4:  ;sih
cmp bx,9
jnz sevevcheck1
mov regposition,0221h
jmp setlocation1


sevevcheck1:  ;dil
cmp bx, 0ah
jnz sevevcheck4
mov regposition,051eh
jmp setlocation1


sevevcheck4:
cmp bx,0bh		;dih
jnz eightcheck4
mov regposition,0521h
jmp setlocation1

eightcheck4:
cmp bx,0ch    ; spl
jnz eightcheck1		
mov regposition,081eh
jmp setlocation1

eightcheck1:
cmp bx,0dh    ; sph
jnz ninecheck4		
mov regposition,0821h
jmp setlocation1

ninecheck4:
cmp bx,0eh    ; Bpl
jnz ninecheck1		
mov regposition,0B1eh
jmp setlocation1

ninecheck1:
cmp bx,0fh    ; Bph
jmp setlocation1	
mov regposition,0B21h
jmp setlocation1

setlocation1:
cmp user,1
jnz usertwoval
mov dx,RegeistersArray[bx]
jmp endselection
usertwoval:
mov dx,RegeistersArray2[bx]
endselection:
mov regvalues,dx
popf 
popa
ret
endp
converttostring macro varabilevalue
push ax
push bx
push cx
push dx
pushf
mov si,0
mov countmemo ,2
loopagain:
cmp  varabilevalue[si],9
jle lessthannine
jmp greaterthannine
lessthannine:
add  varabilevalue[si],30h
jmp endconvert
greaterthannine:
add  varabilevalue[si],37h
endconvert:
dec countmemo
cmp countmemo ,0
jnz loopagain


popf
popa
endm converttostring

Regvalue proc
pusha
pushf
mov dx,regposition
mov yx,dx
mov bh,1
mov regSize,2
mov si,0

label:
mov bh,1
    call setCursor
            mov ah,9            
            mov al, regvalues[si]
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
			inc si
            inc yx
    dec regSize
    jnz label


popf
popa
ret
endp


;/i don't need this function
compareregs proc
 pusha 
 pushf
 mov di,0
 mov si,0
 ;add si , shift
 mov cx,2
 labelll:
 ;mov al, regname[di]
 mov dl,tempregname[si]
 cmp dl,al
 jnz notequalchar
 inc si
 inc di
loop labelll
;mov isexist,1
notequalchar:
 popf
 popa
 ret
 endp


 fillthenamesoftheregs proc 
 pusha
 pushf
 mov si,0
 mov regSize,4
 loop11:
 mov shift,2
 loop0:
 mov countmemo,2
 loop1:
 mov bh,1
 call setcursor
		    mov ah,9            
            mov al, tempregname[si]
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
            inc si
			inc yx
			dec countmemo

 cmp countmemo,0
 jnz loop1
 add yx,6
 dec shift
 cmp shift,0
 jnz loop0
 mov cx,yx
 sub cl,10h
 add  ch ,3
 mov yx,cx
 dec regsize
 cmp regsize,0
 jnz loop11
 


 popf
 popa
 ret
 endp


 ;fucntion to fill the names of the users
 usersnames proc
 pusha
 pushf
 mov yx,1600h
 mov bh,1
 call setcursor
 mov cl,Firstcountname
 dec cl
 mov ch,0
 mov si,2
 labelloop:
			call setcursor
			mov ah,9            
            mov al, firstUsername[si]
            mov bh,1
			push cx
            mov cx,1
            mov bl,0Fh 
            int 10h
			pop cx
			inc yx
            inc si
 loop labelloop
 mov si,2
 mov yx,1700h
 mov bh,1
 call setcursor
 mov cl,secondcountname
 dec cl
 mov ch,0
 labelloop2:
			call setcursor
			mov ah,9            
            mov al, secondUsername[si]
            mov bh,1
			push cx
            mov cx,1
            mov bl,0Fh 
            int 10h
			pop cx
			inc yx
            inc si
 loop labelloop2


 popf
 popa
 ret
 endp


 showforbiddenchar proc 
 pusha
 pushf
 cmp levelnum,31h
 jnz leveltwo
 mov ah,0
 int 16h 
 mov yx,1200h
 mov bh,1
 call setcursor
 mov ah,9            
 mov al,ForbiddenChar1
 mov cx,1
 mov bl,0Fh 
 int 10h
 mov al,ForbiddenChar2
 mov yx,1227h
 pusha
 call setcursor
 popa
 int 10h
 jmp endshow
 leveltwo:
 endshow:

 popf
 popa
 ret
 endp


 scoretext proc 
 pusha
 pushf
 mov si,0
 mov regSize,5
 looptofillscoretext:
 mov bh,1
 call setcursor
 mov ah,9            
 mov al,scoreintialization[si]
 mov cx,1
 mov bl,0Fh 
 int 10h
 inc si
 inc yx
 dec regsize
 cmp regsize,0
 jnz looptofillscoretext



 popf
 popa
 ret
 endp

;///////////////////////////////////////////////////////////////////
 Inlinechat proc near
pusha
pushf
    mov inlineFirstOneTalk,1600h
    mov dx,inlineFirstOneTalk 
	add dl,Firstcountname
	mov inlineFirstOneTalk,dx
	mov yx,dx
    mov bh,1
	mov di,0
    call setCursor

    inline_rec_more_char:
            mov ah,0
            int 16h     
        
            cmp al,8h
            jz inlinechatbackspace
            cmp al,0dh
            jz endmassage
            
            mov dx,inlineFirstOneTalk
            cmp dl,27h                ;if he arrivel to the end of the line
            jz msgmax
            
            ;;;; ptint the char in al
            mov ah,9
            mov bh,1
            mov cx,1
            mov bl,0Fh 
            int 10h
            ;;;;;;;;;;
            mov bx,inlineFirstOneTalk
            mov bh,0
            mov di,bx
            mov stringmsg[di],al                      
            ;;;;;; mov cursr to right
            mov ax,inlineFirstOneTalk
            inc al                    ; mov cursur one right
            mov inlineFirstOneTalk,ax
            mov yx,ax
            mov bh,1
            call setCursor
        

            jmp inline_rec_more_char
            
            
            inlinechatbackspace:
            call inlinespace
            jmp inline_rec_more_char 
            
            msgmax:
            call msgmaxlength
            jmp inline_rec_more_char
             
             
            endmassage:
            call msgenter
popf
popa
ret
endp


;/////////////////////
; BACK SPACE

inlinespace proc near
    pusha
    pushf
    
        call msginnermovleft

        mov al,' '
        mov ah,9
        mov bh,1
        mov cx,1
        mov bl,0Fh 
        int 10h

        mov dx,inlineFirstOneTalk
        mov yx,dx
        mov bh,1
        call setCursor

    popf
    popa
    ret
endp

;///////////////////////////////////////
; MOVE LEFT
msginnermovleft proc near
    pusha
    pushf

        mov dx,inlineFirstOneTalk 
        cmp dl,00h
        jz finsh_move_left
        dec dl 
        mov inlineFirstOneTalk,dx
        mov yx,dx   
        mov bh,1
        call setCursor
          
        finsh_move_left:
        
    popf
    popa
    ret
endp

;//////////////////////////////////////////
; PRRESS ENTER

msgenter proc near
    pusha
    pushf
    
    mov bx,inlineFirstOneTalk
    mov bh,0
    mov di,bx
    mov stringmsg[di],"$"
    
    popf
    popa
    ret
endp

;//////////////////////////////////////
; ARRIVE MAX LENGTH  

msgmaxlength proc near
    pusha
    pushf

    lea dx ,arrive_max_message
    mov msg,dx
    mov bh,1

    popf
    popa
    ret
endp