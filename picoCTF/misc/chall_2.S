	.arch armv8-a
	.file	"chall_2.c"
	.text
	.align	2
	.global	func1
	.type	func1, %function
func1:
	sub	sp, sp, #32 # Allocate 32 bits on the stack pointer
	str	w0, [sp, 12] # store the value of the 1st argument in w0 to the 12th offset of the stack pointer
	str	wzr, [sp, 24] # store the value of wzr (write-zero-value) to the 24th offset of the stack pointer
	str	wzr, [sp, 28] # store the value of wzr (write-zero-value) to the 28th offset of the stack pointer 
	b	.L2
.L3:
	# start -> sp-24 = 0, sp-28 = 0
	ldr	w0, [sp, 24] # load the value stored at the 24th ofset of the sp into w0, so that w0 = 0
	add	w0, w0, 3 # add 3 to w0, and store in w0, so w0 = w0 + 3 = 0 + 3 = 3
	str	w0, [sp, 24] # store w0 as 3 at the 24th ofset of the sp, so that sp-24 = 3
	ldr	w0, [sp, 28] # sp-28 contains 0, so w0 = 0
	add	w0, w0, 1 # add 1 to w0, and store in w0, so wo = w0 + 1 = 0 + 1 = 3
	str	w0, [sp, 28] # sp-28 = 1
	# end -> sp-28 = 1, sp-24 = 3
.L2:
	ldr	w1, [sp, 28] # load the value stored at 28th offset of the sp to w1, so w1 = 0
	ldr	w0, [sp, 12] # load the value stored at 12th offset of the sp to w0, so w0 = argument passed to method
	cmp	w1, w0 # compare w1 and w0
	bcc	.L3 # Branch to .L3 if the carry flag is clear (i.e., if w1 < w0)
	ldr	w0, [sp, 24] # w0 = 3 if above is true, else w0 = 0
	add	sp, sp, 32
	ret
	.size	func1, .-func1
	.section	.rodata
	.align	3
.LC0:
	.string	"Result: %ld\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	stp	x29, x30, [sp, -48]!
	add	x29, sp, 0
	str	w0, [x29, 28]
	str	x1, [x29, 16]
	ldr	x0, [x29, 16]
	add	x0, x0, 8
	ldr	x0, [x0]
	bl	atoi
	bl	func1
	str	w0, [x29, 44]
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	ldr	w1, [x29, 44]
	bl	printf
	nop
	ldp	x29, x30, [sp], 48
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
