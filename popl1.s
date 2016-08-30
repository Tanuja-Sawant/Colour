	.file	"popl1.c"
	.section	.rodata
.LC0:
	.string	"heppy monday"
.LC1:
	.string	"go sunday"
.LC2:
	.string	"qghfd"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$1, -20(%rbp)
	movl	$2, -16(%rbp)
	movl	$3, -12(%rbp)
	movl	$4, -8(%rbp)
	cmpl	$0, -20(%rbp)
	je	.L2
	cmpl	$0, -16(%rbp)
	jne	.L3
.L2:
	cmpl	$0, -12(%rbp)
	je	.L4
	cmpl	$0, -8(%rbp)
	je	.L4
.L3:
	movl	$1, %eax
	jmp	.L5
.L4:
	movl	$0, %eax
.L5:
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$10, %eax
	je	.L7
	cmpl	$20, %eax
	je	.L8
	jmp	.L11
.L7:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L8:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L11:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
.L9:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
