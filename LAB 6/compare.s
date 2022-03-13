.data	
str1: 	.asciiz " is less than " 
str2: 	.asciiz " is less than/greater than or equal to "
str3: 	.asciiz " is greater than "
str4: 	.asciiz " is greater than or equal to "
ask: 	.asciiz "Enter your number here: "
message:.asciiz "Your number "
n:      .word 	25
	
.text	
	
	
main:	
	#$t1 = n
	addi $t1, $zero, 25 
	
	#Prompt user to enter number
	li $v0, 4 
	la $a0, ask
	syscall
	
	#Get user's number
	li $v0, 5
	syscall
	
	#Store number in $t0
	move $t0, $v0
	
	#Display user's number
	li $v0, 4
	la $a0, message
	syscall 
	li $v0, 1
	move $a0, $t0
	syscall
	
	#Comparison
	slt $s0, $t0, $t1
	bne $s0, $zero, less
	
	slt $s0, $t1, $t0
	bne $s0, $zero, greater

	beq $t0, $t1, lessequal

	#Ending comparison
	li $v0, 1
	move $a0, $t1
	syscall
	 
	#End Program 
	li $v0, 10
	syscall
	
less:
	li $v0, 4
	la $a0, str1
	syscall
	li $v0, 1
	move $a0, $t1
	syscall
	li $v0, 10
	syscall
	
lessequal:
	li $v0, 4
	la $a0, str2
	syscall 
	li $v0, 1
	move $a0, $t1
	syscall
	li $v0, 4
	la $a0, message
	li $v0, 10
	syscall
	
greater:
	li $v0, 4
	la $a0, str3
	syscall
	li $v0, 1
	move $a0, $t1
	syscall
	li $v0, 10
	syscall
	

	
	
