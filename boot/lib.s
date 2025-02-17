	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"app.c"
	.text
	.global	x
	.bss
	.align	2
	.type	x, %object
	.size	x, 1024
x:
	.space	1024
	.text
	.align	2
	.global	printfn
	.syntax unified
	.arm
	.type	printfn, %function
printfn:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	bl 	print_uart0
	bx	lr
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	printfn, .-printfn
	.align	2
	.global	printf
	.syntax unified
	.arm
	.type	printf, %function
printf:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L3
.L4:
	ldr	r2, .L7
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	mov	r2, #0
	strb	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L3:
	ldr	r3, [fp, #-8]
	cmp	r3, #1024
	blt	.L4
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L5
.L6:
	ldr	r3, [fp, #-12]
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldrb	r1, [r3]	@ zero_extendqisi2
	ldr	r2, .L7
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, r1
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L5:
	ldr	r3, [fp, #-12]
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L6
	bl	printfn
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L8:
	.align	2
.L7:
	.word	x
	.size	printf, .-printf
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Helloworld!\000"
	.text
	.align	2
	.global	entry
	.syntax unified
	.arm
	.type	entry, %function
entry:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r0, .L10
	bl	printf
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L11:
	.align	2
.L10:
	.word	.LC0
	.size	entry, .-entry
	.ident	"GCC: (Arm GNU Toolchain 14.2.Rel1 (Build arm-14.52)) 14.2.1 20241119"
