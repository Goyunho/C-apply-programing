/*******************************************************************************************************/
/* Title       : ��Ģ���� ���α׷�                                                                     */
/* Programer   : 20121105 ����ȣ                                                                       */
/* date        : 2016-11-11                                                                            */
/* Version     : 2.0.1                                                                                 */
/* Description : v main()         : ����ڿ��� ������ �Է¹޾Ƽ� cal()�� ���� ����� ��ȯ���� ���   */
/*               - i cal(c, i, i) : ��ȣ�� �ν��Ͽ� �� ������ ���                                     */
/*               -- i add(i, i)   : �� ������ ����                                                     */
/*               -- i sub(i, i)   : �� ������ ����                                                     */
/*               -- i mul(i, i)   : �� ������ ����                                                     */
/*               -- i div(i, i)   : �� ������ ������                                                   */
/*******************************************************************************************************/
/* Version ����                                                                                        */
/* 2.0.1 (2016-11-11) : �ڸ�Ʈ �߰�                                                                    */
/* 2.0.0 (2016-11-11) : TEST ��ũ�� �߰�                                                               */
/* 1.1.0 (2016-11-04) : �������� �и� 0�� �� ���� ���                                               */
/* 1.0.0 (2016-11-04) : �ʱ� �ҽ�                                                                      */
/*******************************************************************************************************/
/* �ݺ��Ǵ� �ڸ�Ʈ ����                                                                                */
/* Comment 1 : �׽�Ʈ�� ���� TEST ��ũ�θ� Ȯ���Ͽ� �Լ� �帧�� ���                                   */
/* Comment 2 :                                                                                         */
/* Comment 3 :                                                                                         */
/*******************************************************************************************************/
/* Header                        */
#include <stdio.h>                                                /* ȣ�� : printf()                   */
                                                                  /*        scanf()                    */
                                                                  /*        fflush()                   */
/* Macro                         */
#define ZERO    0                                                 /* ��� 0                            */
#define INIT    ZERO                                              /* �ʱ�ȭ�� ���                     */
#define ERROR   -1                                                /* Error flag                        */
#define TRUE    1                                                 /* ���� ���                         */
#define FALSE   0                                                 /* ������ ���                       */

/* Macro for system control      */
#define TEST    TRUE                                             /* �׽�Ʈ�� ���� �۵����� ���� (F,T) */

/* Function prototype            */
/*  - for calculator             */
int cal(char mark, int num1, int num2);                           /* ����ȣ�� �ľ��Ͽ� �����Լ� ȣ�� */
int add(int num1, int num2);                                      /* �� ������ �����Ͽ� ���� ��ȯ      */
int sub(int num1, int num2);                                      /* �� ������ �����Ͽ� ���� ��ȯ      */
int mul(int num1, int num2);                                      /* �� ������ �����Ͽ� ���� ��ȯ      */
int div(int num1, int num2);                                      /* �� ������ �������Ͽ� ���� ��ȯ    */
/*  - for process                */
void print_func(void);                                     /* TEST ��ũ�ο� ���� �Լ� ���� ���      */

/* ���� ����                     */
int function_depth = 0;                                    /* TEST�� ���� print_func���� �Լ� ����     */

/* main ����                     */
void main(){
    /****************/
    /* ���� ����    */
    /****************/
    int num1, num2;                                        /* num1, num2�� ��꿡 ���Ǵ� �ǿ�����    */
    int result;                                            /* ����� �Ϸ�� �� ����� ����             */
    char mark;                                             /* ��꿡 ���Ǵ� ������                   */

    /****************/
    /* �ʱ�ȭ       */
    /****************/

    /****************/
    /* Code         */
    /****************/
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    while(TRUE)                   /* while continue : ����� ���� Ŀ�ǵ带 ���� ������ ��� �ݺ� �Ѵ�. */
    {
        printf("���� : ��Ģ���� ���α׷�\n");                               /* Comment info Start      */
        printf("������ �� �ּ���.\n");
        printf(" - ����� Ctrl + C�Դϴ�.\n");
        printf("��) 4+3   : ");                                             /* Comment info End        */
        scanf("%d %c %d", &num1, &mark, &num2);                             /* ��� �� �Է¹���        */
        fflush(stdin);                                                      /* �Է� �� �ܿ��� ����     */

        result = cal(mark, num1, num2);                                     /* �������� ��� �м�    */

        printf("����� %d�Դϴ�.\n\n", result);                             /* ����� ���             */
    } /* while continue end */
} /* main() end */

/* �Լ� ���� : - ��� ���� */
int cal(char mark, int num1, int num2)                             /* mark�� �ν��ؼ� ���� ����        */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    switch(mark)                                         /* switch mark : mark�� �ν��ؼ� ���� ����    */
    {
        case '+':                                                  /* ���� ��ȣ�̸� add() ����, ��ȯ   */
            return add(num1, num2);
        case '-':                                                  /* ���� ��ȣ�̸� sub() ����, ��ȯ   */
            return sub(num1, num2);
        case '*':                                                  /* ���� ��ȣ�̸� mul() ����, ��ȯ   */
            return mul(num1, num2);
        case '/':                                                  /* ������ ��ȣ�̸� div() ����, ��ȯ */
            return div(num1, num2);
        default:                                         /* ��ȣ�� �˼� ������ ERROR ���, ��ȯ        */
            printf("��ȣ�� �ľ��� �� �����ϴ�.\n");
            return ERROR;
    } /* switch mark end */
} /* cal() end */

int add(int num1, int num2)                                                 /* �� ���� ����            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 + num2;                                                     /* ��ȯ                    */
} /* add() end */

int sub(int num1, int num2)                                                 /* �� ���� ����            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 - num2;                                                     /* ��ȯ                    */
} /* sub() end */

int mul(int num1, int num2)                                                 /* �� ���� ����            */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    return num1 * num2;                                                     /* ��ȯ                    */
} /* mul() end */

int div(int num1, int num2)                                                 /* �� ���� ������          */
{
#if TEST                                                                    /* Comment 1 Start         */
    print_func();
#endif                                                                      /* Comment 1 End           */
    if(num2 == ZERO)                                    /* 0�� �и�� ������ ���� ���                 */
    {
        printf("0�� �и�� ���ڸ� ������ �����ϴ�.\n");
        return ERROR;
    }
    return (int)(num1 / num2);                          /* ���� ���� �Ǽ��� �� �����Ƿ� int�� ����ȯ   */
} /* div() end */

/* �Լ� ���� : - �ý��� ���� */
void print_func(void)                                   /* TEST ���� �Լ� ���̿� �̸� ���             */
{
#if TEST                                                                    /* Comment 1 Start         */
    function_depth++;                                                       /* �Լ� ���� ����          */
    printf("%d> [current function : %s]\n", function_depth, __func__); /* �Լ� ���̿� ���� �Լ� ���   */
    function_depth--;                                                       /* �Լ� ���� ����          */
#endif                                                                      /* Comment 1 End           */
} /* print_func() end */
