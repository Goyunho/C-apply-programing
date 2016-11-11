/***********************************************************************************************/
/*                                                                                             */
/* Title       : 합 프로그램 (C응용프로그램 실습1)                                             */
/* Writer      : Go yoonho                                                                     */
/* Date        : 2016-10-12                                                                    */
/* Version     : 5.2                                                                           */
/* Explanation : v main(); : n부터 m까지의 합 프로그램                                         */
/*               v print_program_info() : 프로그램 정보를 출력                                 */
/*               v input_num(char[], *int) : str을 출력하고 입력받음                           */
/*               v printc(char[], int) : str을 색깔을 입혀서 출력                              */
/*               i sigma(int, int) : 정수 두값을 시그마 연산                                   */
/*               i plus(int, int)  : 정수 두값을 덧셈 연산                                     */
/*               i minus(int, int) : 정수 두값을 뺄셈 연산                                     */
/*               i times(int, int) : 정수 두값을 곱셈 연산                                     */
/*               i div(int, int)   : 정수 두값을 나눗셈 연산                                   */
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
#define PRINT_SUM    TRUE                      /* sum 과정 출력 허용 여부   TRUE or FALSE      */
#define PRINT_INFO   TRUE                      /* 프로그램 정보 출력 허용 여부   TRUE or FALSE */

/* function            */
void print_program_info();                       /* 프로그램 정보 출력                         */
void input_num(char str[], int *value);          /* str을 출력하고 value에 숫자를 입력받음     */
void printc(char str[], int color_num);          /* str을 출력하되 색상을 입힌다.              */
int sigma(int start_num, int end_num);           /* 시작 수와 끝 수를 입력 받아 합을 구함      */
int plus(int num1, int num2);                    /* 첫번째 인자와 두번째 인자를 덧셈           */

void main(){

	/*******************/
	/* 선언부          */
	/*******************/
	int start_num, end_num;                               /* 반복될 시작수, 끝수 입력          */
	int sum;                                              /* sum은 계산 된 합                  */


	/*******************/
	/* body            */
	/*******************/
	/* 초기값 */
	sum = start_num = end_num = ZERO;                     /* 입력받는 scan_limit 초기화        */


	/* code   */
#if PRINT_INFO
	print_program_info();                                 /* 프로그램 정보 출력                */
#endif

	while(TRUE){                                          /* 계속 반복                         */
		sum = ZERO;                                       /* 반복 될 때마다 sum 초기화         */
		printf("n부터 m까지의 합을 구하는 프로그램\n");
		printf(" │\n ├ 종료는 0입력\n");
		printf(" │\n └ 숫자 외 글자는 0으로 인식\n");
		input_num("시작 숫자(n) : ", &start_num);         /* start_num에 정수 입력받음         */
		input_num("끝날 숫자(m) : ", &end_num);           /* end_num에 정수 입력받음           */

		if(!(start_num && end_num)) break;   /* start_num 혹은 end_num의 입력값이 0이면 종료   */

		sum = sigma(start_num, end_num);     /* start_num과 end_num을 시그마 연산 후 합계 리턴 */

		printf("\n최종 합 : %d\n\n", sum);                /* 최종적으로 합계된 sum을 출력      */
		printf("=========================================\n\n", sum);     /* 종료 괘선         */
	}
}

void print_program_info(){
	printc(" ／／ □■■■■■■■■■■■■■■■■■■■□＼＼\n", 14); /* 소개 화면 시작부분 */
	printc("／／　□　□　□　□　□　□　□　□　□　□　□  ＼＼\n", 14); /* 두번째 인자      */
	printc("　　　□■■■■■■■■■■■■■■■■■■■□\n", 14);       /* 14는 노란색이다  */
	printc("　　　│                                      │\n", 14);
	printc("　　　│          ┌─────────┐      │\n", 14);
	printc("　　　│ O ∇）づ <   합계 프로그램   │      │\n", 14);
	printc("　　　│          │  저자 : 고윤호   │      │\n", 14);
	printc("　　　│          │  버전 : 5.2      │      │\n", 14);
	printc("　　　│          └─────────┘      │\n", 14);
	printc("　　　│                                      │\n", 14);
	printc("√√√", 10), printc("□■■■■■■■■■■■■■■■■■■■□", 14), printc("♀√√√♀√\n\n", 10);   
	                                                                     /* 소개 화면 종료부분 */
}

void printc(char str[], int color_num){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color_num);
	printf("%s", str);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}

void input_num(char str[], int *value){
	printf("%s", str);                                    /* 줄내림 없이 입력받은 문자열 출력  */
	scanf("%d", value);
	fflush(stdin);                                        /* scanf로 잔여된 stdin 비우기       */
}

int sigma(int start_num, int end_num){

	/*******************/
	/* 선언부          */
	/*******************/
	int i;                                                /* i는 반복 횟수                     */
	int sum;                                              /* sum은 계산 된 합                  */

	/*******************/
	/* body            */
	/*******************/
	/* 초기값 */
	sum = ZERO;                                           /* 반복 될 때마다 sum 초기화         */

	/* code   */
#if PRINT_SUM
		printf("┌───────────────────┐\n");            /* 모양             */
#endif

	for(i = start_num ; i <= end_num ; i++){              /* 시작 수부터 끝 수까지 +1 반복     */
		sum = plus(sum, i);                               /* sum에 i(1씩 증가하는)값을 더함    */
#if PRINT_SUM
		printf("│%5d부터 %5d까지의 합 : %5d\t│\n", start_num, i, sum);
		                                          /* 시작 숫자와 반복되는 i값, sum을 출력한다. */
#endif
	}

#if PRINT_SUM
		printf("└───────────────────┘\n");            /* 모양             */
#endif

	return sum;
}

int plus(int num1, int num2){                            /* 인자 1과 인자2를 더해 반환         */
	return num1 + num2;
}