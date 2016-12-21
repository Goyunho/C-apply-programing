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
void init();                                         /* �ʱ� ��¹���                         */
int menu();                                          /* �޴� ���                             */
int calc(char op);                                   /* ������ Ȯ���Ͽ� ��� �Լ� ȣ��        */
int plus(int operand1, int operand2);                /* ���� ����                             */
int minus(int operand1, int operand2);               /* ���� ����                             */
int mul(int operand1, int operand2);                 /* ���� ����                             */
double divi(int operand1, int operand2);             /* ������ ����                           */
int mod(int operand1, int operand2);                 /* ������ ����                           */

/* function for system   */
void print_func(const char func_name[]);             /* ����׽� �Լ� ���� ���� ���          */

/* global valiable       */
