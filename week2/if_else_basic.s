	.text 
SQUARE_MAX = 46340
main:
	# x in $t0, y in $t1
	la	$a0, enter_num_str	# printf("Enter a number: ");
	li 	$v0, 4
	syscall 

	li 	$v0, 5			# scanf("%d", &x);
	syscall 
	move 	$t0, $v0 # $t0 = $v0

	ble   	$t0, SQUARE_MAX, do_multiplication	# if (x <= SQUARE_MAX) goto do_multiplication;

	la 	$a0, square_too_big_str	# printf("square too big for 32 bits\n");
	li 	$v0, 4
	syscall

	j 	epilogue 

do_multiplication:
	mul	$t1, $t0, $t0 		# y = x * x;
	
	move 	$a0, $t1 		# printf("%d", y);
	li 	$v0, 1
	syscall 

	li	$a0, '\n'		# printf("\n");
	li 	$v0, 11
	syscall

epilogue: 
	li 	$v0, 0			# return 0;
	jr 	$ra

	.data
enter_num_str: .asciiz "Enter a number: "
square_too_big_str: .asciiz "square too big for 32 bits\n"