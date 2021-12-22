	.file	"mstore.c"
	.text
	.globl	_multstore
	.def	_multstore;	.scl	2;	.type	32;	.endef
_multstore:
LFB0:
	.cfi_startproc
	movl	8(%esp), %eax
	imull	4(%esp), %eax
	movl	12(%esp), %edx
	movl	%eax, (%edx)
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
