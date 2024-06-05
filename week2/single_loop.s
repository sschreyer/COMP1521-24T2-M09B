# Prints every 3rd number from 24 to 42

main:                           		# int main(void) {
        # Locals:
        #   - $t0: int i, loop counter
count3_loop_init:
	li 	$t0, 24				# int x = 24;
count3_loop_cond:
	bge 	$t0, 42, count3_loop_end	# if (x >= 42) goto for_loop_end;
count3_loop_body:
	move 	$a0, $t0			# printf("%d", x);
	li 	$v0, 1
	syscall

	li 	$a0, '\n'			# printf("\n");
	li 	$v0, 11
	syscall 
count3_loop_incr:
add 	$t0, $t0, 3				# x += 3; 
	j	count3_loop_cond
count3_loop_end:          

epilogue:
	li 	$v0, 1				# return 0;
        jr      $ra             