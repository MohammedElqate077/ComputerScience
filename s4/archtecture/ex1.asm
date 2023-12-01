;affichage d'un message

assume		DS:data;
data		Segement
message: DB "archtecture des ordinateur","$"
data ends
code Segment
start:	mov ax,data;initialisation
	mov ds,ax;de ds par l'adress data

	mov dx,OFFSET message
	mov ah,9;affichcage
	int 21h;... affichage
	
	mov ah,4ch
	int 21h

code ends
end start
