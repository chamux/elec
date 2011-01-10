/* Definition des parametres dont vous avez besoin */
        .SET  rPDATC,0x1d20014 @ Adresse du port C
	.SET rPDATD, 0x1d2002c @ Adresse du port E

main: .global main
	ldr r0,=0xFFFFF     	@ valeur a atteindre pour le wait		
	ldr r1,=rPDATC		@ port C
	ldr r2,=rPDATD		@ port E
	ldr r5,=0xFFFFFFF1	@ masque pour c
	ldr r6,=0xFFFFFFDF	@ masque pour e



initial:

	ldr r3,=0x02        	@ valeur initiale pour c

	mov r4, #0 		@ on eteint e       
	bl port_e

loop:
	bl port_c

	lsl r3, #1

	bl wait

	cmp r3, #16
	bne loop   	@ on reste sur le port C si on n'est pas passe trois fois

	mov r4, #0x20	@ on allume la diode de e
	bl port_e

	mov r3, #0	@ on eteint c
	bl port_c
	
	bl wait	

	b initial





port_c:	@ argument r3 : diode a allumer 2 3 ou 4, 0 pour eteindre
	ldr r7,[r1]
	and r7,r7,r5
	orr r7,r7,r3
	str r7,[r1]
	bx lr

port_e: @ argument r4 : 0 eteint, 0x20 allume
	ldr r7,[r2]
	and r7,r7,r6
	orr r7,r7,r4
	str r7,[r2]
	bx lr

wait:
	mov r7,#0
wait1:
	add r7, r7, #1
	cmp r7,r0
	bne wait1
	bx lr

exit:   NOP
        B exit
