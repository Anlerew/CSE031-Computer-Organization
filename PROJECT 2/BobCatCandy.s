#CSE031 - PROJECT 2 - BOBCAT CANDY SHOP
#COLLABORATOR DAVID NGUYEN

.data 
str0: .asciiz "Welcome to the BobCat Candy, home to the famous BobCat Bars!\n"
str1: .asciiz "Please enter the price of a BobCat Bar:\n"
str2: .asciiz "Please enter the number of wrappers needed to exchange for a new bar:\n"
str3: .asciiz "How much money do you have?\n"
str4: .asciiz "Good! let me run the number ...\n"
str5: .asciiz "You first buy "
str6: .asciiz " bars."
str7: .asciiz "\nYou will then get another "
str8: .asciiz "\nWith $"
str9: .asciiz ", you will receive a maximum of "
str10: .asciiz " BobCat Bars!"
price: .word 0
n: .word 0
money: .word 0
numBars: .word 0

.text
main:						#main function that asks user to input cost per bar wrapper per bar, and money of user.
		addi $sp, $sp -4	
		sw $ra, 0($sp)
		
		li $v0, 4 			#prints str0
		la $a0, str0
		syscall
		
		li $v0, 4			#prints str1
		la, $a0, str1
		syscall
		li $v0, 5			#take price from user
		syscall
		move $a1, $v0
		
		li $v0, 4			#print str2
		la $a0, str2
		syscall
		li $v0, 5			#take wrapper from user
		syscall
		move $t0, $v0
		
		li $v0, 4			#print str3
		la $a0, str3
		syscall
		li $v0, 5			#take money from user
		syscall
		move $a2, $v0
		sw $a2, 12($sp)
		
		li $v0, 4			#print str 4
		la $a0, str4
		syscall
		
		div $s0, $a2, $a1		#calcs the amount of bars user can receive without exchange of wrapper
		
		li $v0, 4			#print purchased bars
		la $a0, str5
		syscall
		move $a0, $s0
		li $v0, 1
		syscall
		
		li $v0, 4			#print str6
		la $a0, str6
		syscall
		
		add $a0, $zero, $t0		#revert $a0 to n
		
		jal maxBars 			#go to maxBars function to calc total bars for user
				
finish:						#statement that tells user the amount of bars they will get
		lw $s0, 4($sp)			#revert back numBars
		add $s0, $v1, $s0		#find maximum amount of bars
		
		li $v0, 4			#print str8	
		la $a0, str8
		syscall
		
		lw $a0, 12($sp)			#revert money
		li $v0, 1
		syscall
		
		li $v0, 4			#print str9
		la $a0, str9
		syscall
		
		move $a0, $s0
		li $v0, 1
		syscall
		
		li $v0, 4			#print str10
		la $a0, str10
		syscall

		j end				#jump to program end

maxBars:					#calcs the total amount of bars user cen get using the priceof the bar, amount of money and exchange rate of wrapper to bar
		div $s0, $a2, $a1		#find quotient of money and price
		sw $s0, 4($sp)			#save the number of bars
		
		add $a1, $zero, $a0		#establish new argument for newBars
		add $a0, $zero, $s0
		add $a2, $zero, $zero

		jal newBars 			#keeps track of the total amount of bars given
		
		jr $ra

newBars:					#calcs the amount of bars the user receives given the amount of wrappers
		div $s0, $a0, $a1		#find the quotient of the bars and wrappers
		sw $s0, 8($sp)			#save the number of bars given by how many wrappers are given
		bne $s0, $zero, remainder	#goes to remainder if the given number of bars from wrappers does not result in zero
		add $v1, $zero, $a2		#return value of all new bars once wrapper are no longer available from user
		
		j finish
		
remainder: 					#statement that tells users the additionals bars they will get in exchange for wrappers
		li $v0, 4			#print str7
		la $a0, str7
		syscall
		
		lw $s0, 8($sp)			#print out value of bars given by wrappers
		move $a0, $s0
		li $v0, 1
		syscall
		
		li $v0, 4			#print str6
		la $a0, str6
		syscall
		
		add $a0, $zero, $s0		#revert arguments back to default
		add $a1, $zero, $a1
		add $a2, $s0, $a2		#add both the bars from wrappers and bars from user
		
		jal newBars

end: 						#end of program
		lw $ra, 0($sp)
		addi $sp, $sp 4
		li $v0, 10 
		syscall
