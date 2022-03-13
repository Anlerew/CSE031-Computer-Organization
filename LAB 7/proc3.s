		.data
x:		.word 5
y:		.word 10

		.text
MAIN:		la $t0, x
		lw $s0, 0($t0)	# s0 = x
		la $t0, y
		lw $s1, 0($t0) 	# s1 = y
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0
		add $a1, $zero, $s1	# Set a0 as input argument for SUM
		jal SUM
		add $t0, $s1, $s0
		add $s1, $t0, $v0
		addi $a0, $s1, 0 
		li $v0, 1		 
		syscall	
		j END
		
SUM:		addi $sp, $sp, -4
		sw $ra, 0($sp)
		
		addi $a0, $s0, 1
		addi $a1, $s1, 1
		jal SUB
		
		addi $sp, $sp, -4
		sw $v1, 0($sp)
		
		addi $a0, $s1, -1
		addi $a1, $s0, -1
		jal SUB
		
		add $v0, $zero, $v1
		lw $v1, 0($sp)
		add $v0, $v0, $v1
		addi $sp, $sp, 4
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra
		

SUB:		sub $v1, $a1, $a0
		jr $ra
		
END: 		li $v0, 10
		syscall
