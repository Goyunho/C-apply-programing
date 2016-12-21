/*******************************************************************************************************/
/* Title       : 사칙연산 프로그램                                                                     */
/* Programer   : 20121105 고윤호                                                                       */
/* date        : 2016-11-11                                                                            */
/* Version     : 2.0.1                                                                                 */
/* Description : v main()         : 사용자에게 계산식을 입력받아서 cal()을 통해 계산한 반환값을 출력   */
/*               - i cal(c, i, i) : 부호를 인식하여 두 정수를 계산                                     */
/*               -- i add(i, i)   : 두 정수를 덧셈                                                     */
/*               -- i sub(i, i)   : 두 정수를 뺄셈                                                     */
/*               -- i mul(i, i)   : 두 정수를 곱셈                                                     */
/*               -- i div(i, i)   : 두 정수를 나눗셈                                                   */
/*******************************************************************************************************/
/* Version 정보                                                                                        */
/* 2.0.1 (2016-11-11) : 코멘트 추가                                                                    */
/* 2.0.0 (2016-11-11) : TEST 매크로 추가                                                               */
/* 1.1.0 (2016-11-04) : 나눗셈에 분모가 0일 때 에러 출력                                               */
/* 1.0.0 (2016-11-04) : 초기 소스                                                                      */
/*******************************************************************************************************/
/* 반복되는 코멘트 참조                                                                                */
/* Comment 1 : 테스트를 위해 TEST 매크로를 확인하여 함수 흐름을 출력                                   */
/* Comment 2 :                                                                                         */
/* Comment 3 :                                                                                         */
/*******************************************************************************************************/
/* Header                        */
#include <stdio.h>                                                /* 호출 : printf()                   */
                                                                  /*        scanf()                    */
                                                                  /*        fflush()                   */
/* Macro                         */
#define ZERO    0                                                 /* 상수 0                            */
#define INIT    ZERO                                              /* 초기화에 사용                     */
#define ERROR   -1                                                /* Error flag                        */
#define TRUE    1                                                 /* 참에 사용                         */
#define FALSE   0                                                 /* 거짓에 사용                       */

/* Macro for system control      */
#define TEST    TRUE                                             /* 테스트를 위해 작동여부 결정 (F,T) */

/* Function prototype            */
/*  - for calculator             */
int cal(char mark, int num1, int num2);                           /* 계산부호를 파악하여 연산함수 호출 */
int add(int num1, int num2);                                      /* 두 정수를 덧셈하여 정수 반환      */
int sub(int num1, int num2);                                      /* 두 정수를 뺄셈하여 정수 반환      */
int mul(int num1, int num2);                                      /* 두 정수를 곱셈하여 정수 반환      */
int div(int num1, int num2);                                      /* 두 정수를 나눗셈하여 정수 반환    */
/*  - for process                */
void print_func(void);                                     /* TEST 매크로에 따라서 함수 진행 출력      */

/* 전역 변수                     */
int function_depth = 0;                                    /* TEST에 따라 print_func에서 함수 깊이     */

/* main 시작                     */
void main(){
    /****************/
    /* 변수 선언    */
    /****************/
    int num1, num2;                                        /* num1, num2는 계산에 사용되는 피연산자    */
    int result;                                            /* 계산이 완료된 후 결과값 저장             */
    char mark;                                             /* 계산에 사용되는 연산자                   */

    /****************/
    /* 초기화       */
    /****************/

    /****************/
    /* Code         */
    /****************/
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    while(TRUE)                   /* while continue : 계산을 종료 커맨드를 받을 때까지 계속 반복 한다. */
    {
        printf("제목 : 사칙연산 프로그램\n");                               /* Comment info Start      */
        printf("계산식을 써 주세요.\n");
        printf(" - 종료는 Ctrl + C입니다.\n");
        printf("예) 4+3   : ");                                             /* Comment info End        */
        scanf("%d %c %d", &num1, &mark, &num2);                             /* 계산 식 입력받음        */
        fflush(stdin);                                                      /* 입력 후 잔여값 삭제     */

        result = cal(mark, num1, num2);                                     /* 계산식으로 계산 분석    */

        printf("결과는 %d입니다.\n\n", result);                             /* 결과값 출력             */
    } /* while continue end */
} /* main() end */

/* 함수 정의 : - 계산 관련 */
int cal(char mark, int num1, int num2)                             /* mark를 인식해서 연산 실행        */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    switch(mark)                                         /* switch mark : mark를 인식해서 연산 실행    */
    {
        case '+':                                                  /* 덧셈 기호이면 add() 실행, 반환   */
            return add(num1, num2);
        case '-':                                                  /* 뺄셈 기호이면 sub() 실행, 반환   */
            return sub(num1, num2);
        case '*':                                                  /* 곱셈 기호이면 mul() 실행, 반환   */
            return mul(num1, num2);
        case '/':                                                  /* 나눗셈 기호이면 div() 실행, 반환 */
            return div(num1, num2);
        default:                                         /* 기호를 알수 없으면 ERROR 출력, 반환        */
            printf("기호를 파악할 수 없습니다.\n");
            return ERROR;
    } /* switch mark end */
} /* cal() end */

int add(int num1, int num2)                                                 /* 두 정수 덧셈            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 + num2;                                                     /* 반환                    */
} /* add() end */

int sub(int num1, int num2)                                                 /* 두 정수 뺄셈            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 - num2;                                                     /* 반환                    */
} /* sub() end */

int mul(int num1, int num2)                                                 /* 두 정수 곱셈            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 * num2;                                                     /* 반환                    */
} /* mul() end */

int div(int num1, int num2)                                                 /* 두 정수 나눗셈          */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    if(num2 == ZERO)                                    /* 0을 분모로 나누면 에러 출력                 */
    {
        printf("0을 분모로 분자를 나눌수 없습니다.\n");
        return ERROR;
    }
    return (int)(num1 / num2);                          /* 나눈 값이 실수일 수 있으므로 int로 형변환   */
} /* div() end */

/* 함수 정의 : - 시스템 관련 */
void print_func(void)                                   /* TEST 관련 함수 깊이와 이름 출력             */
{
#if TEST                                                                    /* Comment 1 Start         */
    function_depth++;                                                       /* 함수 깊이 증가          */
    printf("%d> [current function : %s]\n", function_depth, __func__); /* 함수 깊이와 현재 함수 출력   */
    function_depth--;                                                       /* 함수 깊이 감소          */
#endif                                                                      /* Comment 1 End           */
} /* print_func() end */
