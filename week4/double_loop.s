# This program prints out a danish flag, by
# looping through the rows and columns of the flag.
# Each element inside the flag is a single character.
# (i.e., 1 byte).

# Constants
FLAG_ROWS = 6
FLAG_COLS = 12

# Registers:
# - row in $t0
# - col in $t1
main:
main__row_loop_init:
	li	$t0, 0			# int row = 0;
main__row_loop_cond:
	bge 	$t0, FLAG_ROWS, main__row_loop_end

main__row_loop_body:
	li	$a0, '\n'		# printf("\n");
	li	$v0, 11
	syscall

main__col_loop_init:
	li 	$t1, 0			# int col = 0;
main__col_loop_cond:
	bge 	$t1, FLAG_COLS, main__col_loop_end

main__col_loop_body:
	la 	$t2, flag		# &flag[0];

	mul 	$t3, $t0, 12
	mul 	$t3, $t3, 1
	add 	$t3, $t2, $t3 		# &flag[row][0];

	mul	$t4, $t1, 1
	add 	$t5, $t3, $t4		# &flag[row][col];

	lb	$t6, ($t5)	
	move 	$a0, $t6
	li	$v0, 11
	syscall 			# printf("%c", flag[row][col]);

main__col_loop_step:
	addi 	$t1, 1			# col++;
	j 	main__col_loop_cond
main__col_loop_end:

main__row_loop_step:
	addi 	$t0, 1			# row++;
	j 	main__row_loop_cond
main__row_loop_end:
	li	$v0, 0                  
	jr	$ra			# return 0;

.data
# This label inside the data region refers to the bytes of the flag.
# Note that even thought the bytes are listed on separate lines,
# they are actually stored as a single contiguous chunk or 'string' in memory.
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'