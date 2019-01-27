; D.N.D. Spring Festival Issue
; Filename: Assembly - wxx9248.asm
; Compiler: Microsoft (R) Macro Assembler (x64)
; File Format: ANSI (WCHAR_HARD_CODE)
; Author: wxx9248

Includelib User32.lib
Includelib Kernel32.lib

Extern MessageBoxA:Proc
Extern CreateThread:Proc
Extern CloseHandle:Proc

.data
	szTitle					db	'原地跑圈中', 0
	szContent  				db 	'夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！', 0

.code
WinMain Proc
	sub rsp, 40h
	
	L1:
	mov	QWORD PTR [rsp+38h], 0
	mov	DWORD PTR [rsp+30h], 0
	xor r9, r9
	lea	r8, ShowWindow
	xor rdx, rdx
	xor rcx, rcx

	call CreateThread
	
	mov rcx, rax
	call CloseHandle
	
	mov rcx, 104857600
	L2:
	nop
	loop L2
	
	loop L1
	xor rax, rax
	add rsp, 40h
	ret
WinMain Endp

ShowWindow Proc
	mov	QWORD PTR [rsp+8], rcx
	sub rsp, 28h
	
	mov r9, 64
	lea r8, offset szTitle
	lea rdx, offset szContent
	xor rcx, rcx
	
	call MessageBoxA
	
	xor rax, rax
	add rsp, 28h
	ret
ShowWindow Endp

End