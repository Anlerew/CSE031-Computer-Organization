        .data

# TPS 2 #3 (statement to be displayed)
str1: .asciiz "Please enter an integer\n"

        .text
               
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# TPS 2 #3 (display statement)
		la $a0, str1
		addi $v0, $zero, 4
		syscall
		
	addi	 $v0, $zero, 5
		syscall
		
		add $a0, $zero, $v0
		
		# TPS 2 #4 (read user input)

		
		jal recursion	# Call recursion(x)
		
		# TPS 2 #6 (read user input)
	add	$a0, $v0, $zero
	addi	$v0, $zero, 1
		syscall
		j end		# Jump to end of program


# Implementing recursion
recursion:	addi $sp, $sp, -12	# Push stack frame for local storage

		# TPS 2 #7 
		sw $ra, 0($sp)
		
		
		addi $t0, $a0, -10
		bne $t0, $zero, not_ten
		
		# TPS 2 #8 (update returned value)
		addi $v0,$zero, 2 
		
		j end_recur
			
not_ten:	addi $t0, $a0, -11
		bne $t0, $zero, not_eleven

		# TPS 2 #9 (update returned value)
		addi $v0, $zero, 1
		
		j end_recur		

not_eleven:	sw $a0, 4($sp) 	
		# TPS 2 #11 (Prepare new input argument, i.e. m + 1)
		addi $a0, $a0, 2
		
		
		jal recursion	# Call recursion(m - 2)
		
		# TPS 2 #12 
		sw $v0, 8($sp)
		
		
		
		# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
		lw $a0, 4($sp)
		addi $a0, $a0, 1
		
		jal recursion	# Call recursion(m - 1)
		lw $t1, 8($sp)
		add $v0, $t1, $v0
		lw $t1, 4($sp)
		add $v0, $t1, $v0
		# TPS 2 #14 (update returned value)
		
		
		j end_recur
		

# End of recursion function	
end_recur:	# TPS 2 #15 
		lw $ra, 0($sp)
		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

# Terminating the program
end:	addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall
