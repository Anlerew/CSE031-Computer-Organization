.data
result: .asciiz "Sum is: "
	
.text
main:
	move $t0,$s0
	move $t1,$s1

	add $t2,$t0,1
	add $t3,$t1,2
	add $t4,$t2,3
	add $t5,$t3,4
	add $t6,$t4,5
	add $t7,$t5,6
	
	la $a0, result
	li $v0, 4
	syscall
	
	addi $a0, $t7, 0
	li $v0, 1
	syscall
