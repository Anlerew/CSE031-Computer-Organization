.data
statement: .asciiz "\nPlease enter a number: "
sumPos: .asciiz "\nSum of positive number is: "
sumNeg: .asciiz "\nSum of negative number is: "

.text
li $s0, 0
li $s1, 0

loop:   
#get input from user
li $v0, 4
la $a0, statement
syscall
#get input from user
li $v0, 5
syscall
move $t0, $v0

beqz $t0, done

bltz $t0, numNeg
#add the positvie numbers
add $s0,$s0,$t0
j skip

numNeg:
#adds the negative numbers
add $s1,$s1,$t0

skip:
j loop

done:
#calls the sum of the positive
li $v0,4
la $a0,sumPos
syscall
move $a0,$s0
li $v0,1
syscall

#calls the sum of the negative
li $v0,4
la $a0,sumNeg
syscall
move $a0,$s1
li $v0,1
syscall
