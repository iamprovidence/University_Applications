	.386P
	.MODEL	SMALL	; ������ ������� (������ SMALL)
CODESG	SEGMENT  DWORD PUBLIC USE16 'CODE'	;;;USE16 !
	ASSUME	CS:CODESG,DS:CODESG,SS:CODESG,ES:CODESG
	ORG	100H	;   ������ ��� PSP-�������� �����. ��������
BEGIN:	JMP	MAINPROG	;   ����� �����
MESS1	DB	'Testing: print a line:'
	DB	'$'
MAINPROG	PROC	NEAR	;  ��������� ��������� ����
	MOV	AH,09	;  ������� �� ����� ����� �� '$'
	LEA	DX,MESS1	;  ������ ������� ����� ����������
	INT	21H
	CALL	READLINE
	CALL	WRITELN
	JMP	EXIT	;  ����� �� 4c/Int 21h
MAINPROG	ENDP
; ��������� ������� �����
READLINE	PROC	NEAR
	MOV	AH,0AH	; ��������� � ��������� ����� �� Enter
	LEA	DX,MAXLEN	; ������ ������ ���������
	INT	21H
	RET	;
READLINE	ENDP
;  ���'��� �� ���  ��� ��������� ������� �����
MAXLEN	DB	30	;  ����������� ������� ��������� �����
REALLEN	DB	?	;  ������� �������� �������� �������
POLE	DB	30  DUP ('_')	;  ���� ( 30 ���� ) ��� �������� �������
;  ��������� ��������� �� �����
WRITELN	PROC	NEAR
	MOV	AH,09
	LEA	DX,MESS2	;  �����-�����������
	INT	21H
; ������� �����, ���� ���������
	MOV	AH,40H	;  ������� ����� ������� �������
	MOV	BX,1	;  �� �����
; CX = ������� �����
	MOV	CH,0	;  ������� ���� CX =0
	MOV	CL,REALLEN	;  ������� �������� �������
	LEA	DX,POLE	;  ������ ������� �����
	INT	21H
; ����� �� ��������� ����� ��� �������� �� ������ �����
	MOV	AH,09
	LEA	DX,NEWLINE
	INT	21H
	RET
MESS2	DB	10,13,'This line:'
NEWLINE	DB	10,13	; (10,13) - ����� �����
	DB	'$'
WRITELN	ENDP
EXIT:   MOV     AX,4C00h  ;  ������� 4C (76)
        INT     21h    ;  "��������� ��������"
CODESG	ENDS
	END	BEGIN
