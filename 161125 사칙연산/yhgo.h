#include <stdio.h>                                   /* call : printf(), scanf()              */
#include <stdlib.h>                                  /* call : fflush()                       */

/* Define                */
#define ZERO    0                                    /* = 0, exit                             */
#define ONE     1                                    /* = 1, state good                       */
#define ERROR   -1                                   /* = -1, state error                     */
#define TRUE    ONE                                  /* = 1, True                             */
#define FALSE   ZERO                                 /* = 0, False                            */

/* Define for Debug      */
#define INIT_PRT    TRUE                             /* start running massege : print - T     */
#define TEST_PRT    TRUE                            /* TEST_DISCRIPTION      : print - T     */
#define MENU_PRT    TRUE                             /* menu print            : print - T     */
#define ERR_MSG     TRUE                             /* = T, PRINT = TRUE / else    = FALSE   */
#define DBG_PRT     TRUE                            /* = T, Debug = TRUE / release = FALSE   */

/* function prototype    */
void init();                                         /* 초기 출력문장                         */
int menu();                                          /* 메뉴 출력                             */
int calc(char op);                                   /* 연산자 확인하여 계산 함수 호출        */
int plus(int operand1, int operand2);                /* 덧셈 연산                             */
int minus(int operand1, int operand2);               /* 뺄셈 연산                             */
int mul(int operand1, int operand2);                 /* 곱셈 연산                             */
double divi(int operand1, int operand2);             /* 나눗셈 연산                           */
int mod(int operand1, int operand2);                 /* 나머지 연산                           */

/* function for system   */
void print_func(const char func_name[]);             /* 디버그시 함수 진입 상태 출력          */

/* global valiable       */
