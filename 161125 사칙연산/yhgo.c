/**********************************************************************************************/
/* Call Relationship                                                                          */
/* v init(v)            : 프로그램 시작 메시지 출력                                           */
/* i menu(v)            : 메뉴를 출력, 연산자 입력, rtn - 계산 후 상태                        */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/**********************************************************************************************/
#include "yhgo.h"                                    /* yhgo 헤더 포함 : 함수 원형 포함       */

void init()                                          /* 프로그램 시작 메시지 출력             */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                 */
#endif
    printf("사칙연산 프로그램입니다.\n");            /* 프로그램 진입시 프로그램 설명         */
#if TEST_PRT
    printf("[DEBUG] 테스트 모드입니다.\n");
    printf("[DEBUG] 다음은 예상 출력입니다.\n");
    printf("[DEBUG] 1, '+' : 30 + 13 = 43\n");
    printf("[DEBUG] 2, '-' : 30 - 13 = 17\n");
    printf("[DEBUG] 3, '*' : 30 * 13 = 390\n");
    printf("[DEBUG] 4, '/' : 30 / 13 = 2.31\n");
    printf("[DEBUG] 5, '%%' : 30 %% 13 = 4\n");
#endif
}/* init() End */

int menu()                                           /* 계산 연산자 선택, 종료                */
{
    /****************/
    /* 변수 선언    */
    /****************/
    char op;                                         /* 계산 연산자 저장                      */
    
    /****************/
    /* source       */
    /****************/
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
#if MENU_PRT
    printf("1. +\n");                                /* menu_print : 메뉴 출력                */
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");
    printf("5. %%\n");
    printf("x. exit\n");
    printf(">>> ");                                  /* menu_print End                       */
#else
    printf("연산자 : ");                             /* 연산자 입력                          */
#endif
    scanf("%c", &op);                                /* 계산 연산자 입력받음                 */
    fflush(stdin);                                   /* buffer 잔여값 제거                   */

    return calc(op);                                 /* calc() 실행 후 상태값 반환           */
}/* menu() End */

int calc(char op)                          /* 연산자를 보고 switch 실행, 피연산자 입력       */
{
    /****************/
    /* 변수 선언    */
    /****************/
    int operand1, operand2;                          /* 피연산자1,2                          */
    int result_i;                                    /* 정수형 결과값 저장                   */
    double result_f;                                 /* 실수형 결과값 저장                   */

    /****************/
    /* source       */
    /****************/
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(op == 'x')                                    /* 입력값이 'x'이면 종료 반환           */
    {
        return ZERO;                                 /* 종료 반환                            */
    }

    printf("첫번째 수 : ");                          /* 피연산자1                            */
    scanf("%d", &operand1);                          /* 피연산자1 정수 입력                  */
    fflush(stdin);                                   /* 종료 반환                            */
    printf("두번째 수 : ");                          /* 피연산자2                            */
    scanf("%d", &operand2);                          /* 피연산자2 정수 입력                  */
    fflush(stdin);                                   /* 종료 반환                            */

    switch(op)                                       /* switch_op : 연산자 구별              */
    {
        case '+':                                    /* op가 +, 1이면 덧셈후 출력            */
        case '1':
            result_i = plus(operand1, operand2);     /* 덧셈 연산                            */
            printf("결과 값 : %d\n", result_i);      /* 정수 결과 출력                       */
            return ONE;                              /* 정상 상태 반환                       */

        case '-':                                    /* op가 -, 2이면 뺄셈후 출력            */
        case '2':
            result_i = minus(operand1, operand2);    /* 뺄셈 연산                            */
            printf("결과 값 : %d\n", result_i);      /* 정수 결과 출력                       */
            return ONE;                              /* 정상 상태 반환                       */

        case '*':
        case '3':
            result_i = mul(operand1, operand2);      /* 곱셈 연산                            */
            printf("결과 값 : %d\n", result_i);      /* 정수 결과 출력                       */
            return ONE;                              /* 정상 상태 반환                       */

        case '/':
        case '4':
            result_f = divi(operand1, operand2);     /* 곱셈 연산                            */
            if(result_f == ERROR)                    /* 비정상 상태일 경우                   */
            {
                return ERROR;                        /* 비정상 상태 반환                     */
            }
            printf("결과 값 : %.2f\n", result_f);    /* 실수 결과 출력                       */
            return ONE;                              /* 정상 상태 반환                       */

        case '%':
        case '5':
            result_i = mod(operand1, operand2);      /* 나머지 연산                          */
            if(result_i == ERROR)                    /* 비정상 상태일 경우                   */
            {
                return ERROR;                        /* 비정상 상태 반환                     */
            }
            printf("결과 값 : %d\n", result_i);      /* 정수 결과 출력                       */
            return ONE;                              /* 정상 상태 반환                       */
            
        default :
            printf("Error!\n");                      /* 연산자 분석 오류                     */
            return ERROR;                            /* 비정수 결과 출력                     */
    }/* switch_op End */
}/* calc() End */

int plus(int operand1, int operand2)                 /* 덧셈 연산 함수 : 정수(정수, 정수)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 + operand2;
}/* plus() End */

int minus(int operand1, int operand2)                /* 뺄셈 연산 함수 : 정수(정수, 정수)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 - operand2;
}/* minus() End */

int mul(int operand1, int operand2)                  /* 곱셈 연산 함수 : 정수(정수, 정수)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 * operand2;
}/* mul() End */

double divi(int operand1, int operand2)              /* 나눗셈 연산 함수 : 실수(정수, 정수)  */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(!operand2)                                    /* chk_opr2 : 분모가 0이면 실행         */
    {
#if ERR_MSG
        printf("0으로는 나눌 수 없습니다.\n");
#endif
        return ERROR;                                /* 에러값 반환                          */
    }/* if chk_opr2 End */
    return (double)operand1 / (double)operand2;      /* 소숫점 반환을 위해 실수형 변환       */
}/* divi() End */

int mod(int operand1, int operand2)                  /* 나머지 연산 함수 : 정수(정수, 정수)  */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(!operand2)                                    /* chk_opr2 : 분모가 0이면 실행         */
    {
#if ERR_MSG
        printf("0으로는 나눌 수 없습니다.\n");
#endif
        return ERROR;                                /* 에러값 반환                          */
    }/* if chk_opr2 End */
    return operand1 % operand2;
}/* mod() End */

/* 함수 정의 : - 시스템 관련 */
void print_func(const char func_name[])       /* TEST 관련 함수 깊이와 이름 출력             */
{
    /****************/
    /* 변수 선언    */
    /****************/
    static int func_depth = ZERO;                   /* 디버그시 파일 깊이 출력               */
    
    /****************/
    /* source       */
    /****************/
    func_depth++;                                            /* 함수 깊이 증가               */
    printf("%d> [current function : %s]\n", 
        func_depth, func_name);                              /* 함수 깊이와 현재 함수 출력   */
    func_depth--;                                            /* 함수 깊이 감소               */
} /* print_func() end */