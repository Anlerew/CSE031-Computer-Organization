        .data
#n:      .word 13
str0:	.asciiz "Please enter an integer: \n"

        .text
main:		#print string str0
		la $a0, str0
		addi $v0, $zero, 4
		syscall
		#input integer
		addi $v0, $zero, 5
		syscall	#input will be stored at $v0
		add $t3, $v0, $zero
		
		add $t0, $0, $zero
		addi $t1, $zero, 1
		
fib: 	beq     $t3, $0, finish
		add     $t2,$t1,$t0
		move    $t0, $t1
		move    $t1, $t2
		subi    $t3, $t3, 1
		j       fib
		
finish: addi    $a0, $t0, 0
		li      $v0, 1		
		syscall			
		li      $v0, 10		
		syscall			

