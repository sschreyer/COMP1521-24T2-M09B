	.text
main:
main__prologue:
	begin 
	push 	$ra

main__body:
	li 	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal 	sum4 		# sum4(11, 13, 15, 17);

	move 	$a0, $v0	
	li	$v0, 1
	syscall			# printf("%d", result);

	li	$a0, '\n'
	li	$v0, 11
	syscall			# printf("\n");

	li	$v0, 0
	
main__epilogue:
	pop 	$ra
	end

	jr 	$ra 	#return 0;


sum4:
sum4__prologue:
	begin 
	push	$ra
	push 	$s0 
	push 	$s1 
	push 	$s2
sum4__body:
	move 	$s0, $a2 
	move 	$s1, $a3

	jal 	sum2 
	move	$s2, $v0	# sum2(a, b);

	move 	$a0, $s0
	move 	$a1, $s1
	jal 	sum2		# sum2(c, d);
	move 	$t0, $v0 

	move 	$a0, $s2
	move 	$a1, $t0
	jal 	sum2 		# sum2(res1, res2);

sum4__epilogue:
	pop 	$s2 
	pop	$s1
	pop 	$s0
	pop 	$ra
	end 

	jr 	$ra

sum2: 
sum2__prologue:
	# prologue and epilogue here for convention,
	# but we don't need to do anything as this
	# is a leaf function
sum2__body:
	add 	$v0, $a0, $a1	
	jr	$ra		# return x + y;
sum2__epilogue:


