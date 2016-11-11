/***********************************************************************************************/
/*                                                                                             */
/* Title       : �� ���α׷� (C�������α׷� �ǽ�1)                                             */
/* Writer      : Go yoonho                                                                     */
/* Date        : 2016-10-12                                                                    */
/* Version     : 5.2                                                                           */
/* Explanation : v main(); : n���� m������ �� ���α׷�                                         */
/*               v print_program_info() : ���α׷� ������ ���                                 */
/*               v input_num(char[], *int) : str�� ����ϰ� �Է¹���                           */
/*               v printc(char[], int) : str�� ������ ������ ���                              */
/*               i sigma(int, int) : ���� �ΰ��� �ñ׸� ����                                   */
/*               i plus(int, int)  : ���� �ΰ��� ���� ����                                     */
/*               i minus(int, int) : ���� �ΰ��� ���� ����                                     */
/*               i times(int, int) : ���� �ΰ��� ���� ����                                     */
/*               i div(int, int)   : ���� �ΰ��� ������ ����                                   */
/*                                                                                             */
/***********************************************************************************************/

/* include file        */
#include <stdio.h>
#include <windows.h>

/* define Statement    */
#define ZERO            0
#define INIT            1

/* Logical Statement   */
#define TRUE            1
#define FALSE           0

/* define I/O for test */
#define PRINT_SUM    TRUE                      /* sum ���� ��� ��� ����   TRUE or FALSE      */
#define PRINT_INFO   TRUE                      /* ���α׷� ���� ��� ��� ����   TRUE or FALSE */

/* function            */
void print_program_info();                       /* ���α׷� ���� ���                         */
void input_num(char str[], int *value);          /* str�� ����ϰ� value�� ���ڸ� �Է¹���     */
void printc(char str[], int color_num);          /* str�� ����ϵ� ������ ������.              */
int sigma(int start_num, int end_num);           /* ���� ���� �� ���� �Է� �޾� ���� ����      */
int plus(int num1, int num2);                    /* ù��° ���ڿ� �ι�° ���ڸ� ����           */

void main(){

	/*******************/
	/* �����          */
	/*******************/
	int start_num, end_num;                               /* �ݺ��� ���ۼ�, ���� �Է�          */
	int sum;                                              /* sum�� ��� �� ��                  */


	/*******************/
	/* body            */
	/*******************/
	/* �ʱⰪ */
	sum = start_num = end_num = ZERO;                     /* �Է¹޴� scan_limit �ʱ�ȭ        */


	/* code   */
#if PRINT_INFO
	print_program_info();                                 /* ���α׷� ���� ���                */
#endif

	while(TRUE){                                          /* ��� �ݺ�                         */
		sum = ZERO;                                       /* �ݺ� �� ������ sum �ʱ�ȭ         */
		printf("n���� m������ ���� ���ϴ� ���α׷�\n");
		printf(" ��\n �� ����� 0�Է�\n");
		printf(" ��\n �� ���� �� ���ڴ� 0���� �ν�\n");
		input_num("���� ����(n) : ", &start_num);         /* start_num�� ���� �Է¹���         */
		input_num("���� ����(m) : ", &end_num);           /* end_num�� ���� �Է¹���           */

		if(!(start_num && end_num)) break;   /* start_num Ȥ�� end_num�� �Է°��� 0�̸� ����   */

		sum = sigma(start_num, end_num);     /* start_num�� end_num�� �ñ׸� ���� �� �հ� ���� */

		printf("\n���� �� : %d\n\n", sum);                /* ���������� �հ�� sum�� ���      */
		printf("=========================================\n\n", sum);     /* ���� ����         */
	}
}

void print_program_info(){
	printc(" ���� ���������������������࡬��\n", 14); /* �Ұ� ȭ�� ���ۺκ� */
	printc("�������ࡡ�ࡡ�ࡡ�ࡡ�ࡡ�ࡡ�ࡡ�ࡡ�ࡡ�ࡡ��  ����\n", 14); /* �ι�° ����      */
	printc("����������������������������\n", 14);       /* 14�� ������̴�  */
	printc("��������                                      ��\n", 14);
	printc("��������          ����������������������      ��\n", 14);
	printc("�������� O �ԣ��� <   �հ� ���α׷�   ��      ��\n", 14);
	printc("��������          ��  ���� : ����ȣ   ��      ��\n", 14);
	printc("��������          ��  ���� : 5.2      ��      ��\n", 14);
	printc("��������          ����������������������      ��\n", 14);
	printc("��������                                      ��\n", 14);
	printc("����", 10), printc("����������������������", 14), printc("�ϡ���ϡ�\n\n", 10);   
	                                                                     /* �Ұ� ȭ�� ����κ� */
}

void printc(char str[], int color_num){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color_num);
	printf("%s", str);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}

void input_num(char str[], int *value){
	printf("%s", str);                                    /* �ٳ��� ���� �Է¹��� ���ڿ� ���  */
	scanf("%d", value);
	fflush(stdin);                                        /* scanf�� �ܿ��� stdin ����       */
}

int sigma(int start_num, int end_num){

	/*******************/
	/* �����          */
	/*******************/
	int i;                                                /* i�� �ݺ� Ƚ��                     */
	int sum;                                              /* sum�� ��� �� ��                  */

	/*******************/
	/* body            */
	/*******************/
	/* �ʱⰪ */
	sum = ZERO;                                           /* �ݺ� �� ������ sum �ʱ�ȭ         */

	/* code   */
#if PRINT_SUM
		printf("������������������������������������������\n");            /* ���             */
#endif

	for(i = start_num ; i <= end_num ; i++){              /* ���� ������ �� ������ +1 �ݺ�     */
		sum = plus(sum, i);                               /* sum�� i(1�� �����ϴ�)���� ����    */
#if PRINT_SUM
		printf("��%5d���� %5d������ �� : %5d\t��\n", start_num, i, sum);
		                                          /* ���� ���ڿ� �ݺ��Ǵ� i��, sum�� ����Ѵ�. */
#endif
	}

#if PRINT_SUM
		printf("������������������������������������������\n");            /* ���             */
#endif

	return sum;
}

int plus(int num1, int num2){                            /* ���� 1�� ����2�� ���� ��ȯ         */
	return num1 + num2;
}