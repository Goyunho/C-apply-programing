/**********************************************************************************************/
/* Call Relationship                                                                          */
/* v init(v)            : ���α׷� ���� �޽��� ���                                           */
/* i menu(v)            : �޴��� ���, ������ �Է�, rtn - ��� �� ����                        */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/*                                                                                            */
/**********************************************************************************************/
#include "yhgo.h"                                    /* yhgo ��� ���� : �Լ� ���� ����       */

void init()                                          /* ���α׷� ���� �޽��� ���             */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                 */
#endif
    printf("��Ģ���� ���α׷��Դϴ�.\n");            /* ���α׷� ���Խ� ���α׷� ����         */
#if TEST_PRT
    printf("[DEBUG] �׽�Ʈ ����Դϴ�.\n");
    printf("[DEBUG] ������ ���� ����Դϴ�.\n");
    printf("[DEBUG] 1, '+' : 30 + 13 = 43\n");
    printf("[DEBUG] 2, '-' : 30 - 13 = 17\n");
    printf("[DEBUG] 3, '*' : 30 * 13 = 390\n");
    printf("[DEBUG] 4, '/' : 30 / 13 = 2.31\n");
    printf("[DEBUG] 5, '%%' : 30 %% 13 = 4\n");
#endif
}/* init() End */

int menu()                                           /* ��� ������ ����, ����                */
{
    /****************/
    /* ���� ����    */
    /****************/
    char op;                                         /* ��� ������ ����                      */
    
    /****************/
    /* source       */
    /****************/
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
#if MENU_PRT
    printf("1. +\n");                                /* menu_print : �޴� ���                */
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");
    printf("5. %%\n");
    printf("x. exit\n");
    printf(">>> ");                                  /* menu_print End                       */
#else
    printf("������ : ");                             /* ������ �Է�                          */
#endif
    scanf("%c", &op);                                /* ��� ������ �Է¹���                 */
    fflush(stdin);                                   /* buffer �ܿ��� ����                   */

    return calc(op);                                 /* calc() ���� �� ���°� ��ȯ           */
}/* menu() End */

int calc(char op)                          /* �����ڸ� ���� switch ����, �ǿ����� �Է�       */
{
    /****************/
    /* ���� ����    */
    /****************/
    int operand1, operand2;                          /* �ǿ�����1,2                          */
    int result_i;                                    /* ������ ����� ����                   */
    double result_f;                                 /* �Ǽ��� ����� ����                   */

    /****************/
    /* source       */
    /****************/
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(op == 'x')                                    /* �Է°��� 'x'�̸� ���� ��ȯ           */
    {
        return ZERO;                                 /* ���� ��ȯ                            */
    }

    printf("ù��° �� : ");                          /* �ǿ�����1                            */
    scanf("%d", &operand1);                          /* �ǿ�����1 ���� �Է�                  */
    fflush(stdin);                                   /* ���� ��ȯ                            */
    printf("�ι�° �� : ");                          /* �ǿ�����2                            */
    scanf("%d", &operand2);                          /* �ǿ�����2 ���� �Է�                  */
    fflush(stdin);                                   /* ���� ��ȯ                            */

    switch(op)                                       /* switch_op : ������ ����              */
    {
        case '+':                                    /* op�� +, 1�̸� ������ ���            */
        case '1':
            result_i = plus(operand1, operand2);     /* ���� ����                            */
            printf("��� �� : %d\n", result_i);      /* ���� ��� ���                       */
            return ONE;                              /* ���� ���� ��ȯ                       */

        case '-':                                    /* op�� -, 2�̸� ������ ���            */
        case '2':
            result_i = minus(operand1, operand2);    /* ���� ����                            */
            printf("��� �� : %d\n", result_i);      /* ���� ��� ���                       */
            return ONE;                              /* ���� ���� ��ȯ                       */

        case '*':
        case '3':
            result_i = mul(operand1, operand2);      /* ���� ����                            */
            printf("��� �� : %d\n", result_i);      /* ���� ��� ���                       */
            return ONE;                              /* ���� ���� ��ȯ                       */

        case '/':
        case '4':
            result_f = divi(operand1, operand2);     /* ���� ����                            */
            if(result_f == ERROR)                    /* ������ ������ ���                   */
            {
                return ERROR;                        /* ������ ���� ��ȯ                     */
            }
            printf("��� �� : %.2f\n", result_f);    /* �Ǽ� ��� ���                       */
            return ONE;                              /* ���� ���� ��ȯ                       */

        case '%':
        case '5':
            result_i = mod(operand1, operand2);      /* ������ ����                          */
            if(result_i == ERROR)                    /* ������ ������ ���                   */
            {
                return ERROR;                        /* ������ ���� ��ȯ                     */
            }
            printf("��� �� : %d\n", result_i);      /* ���� ��� ���                       */
            return ONE;                              /* ���� ���� ��ȯ                       */
            
        default :
            printf("Error!\n");                      /* ������ �м� ����                     */
            return ERROR;                            /* ������ ��� ���                     */
    }/* switch_op End */
}/* calc() End */

int plus(int operand1, int operand2)                 /* ���� ���� �Լ� : ����(����, ����)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 + operand2;
}/* plus() End */

int minus(int operand1, int operand2)                /* ���� ���� �Լ� : ����(����, ����)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 - operand2;
}/* minus() End */

int mul(int operand1, int operand2)                  /* ���� ���� �Լ� : ����(����, ����)    */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    return operand1 * operand2;
}/* mul() End */

double divi(int operand1, int operand2)              /* ������ ���� �Լ� : �Ǽ�(����, ����)  */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(!operand2)                                    /* chk_opr2 : �и� 0�̸� ����         */
    {
#if ERR_MSG
        printf("0���δ� ���� �� �����ϴ�.\n");
#endif
        return ERROR;                                /* ������ ��ȯ                          */
    }/* if chk_opr2 End */
    return (double)operand1 / (double)operand2;      /* �Ҽ��� ��ȯ�� ���� �Ǽ��� ��ȯ       */
}/* divi() End */

int mod(int operand1, int operand2)                  /* ������ ���� �Լ� : ����(����, ����)  */
{
#if DBG_PRT
    print_func(__func__);                            /* Cmt_1                                */
#endif
    if(!operand2)                                    /* chk_opr2 : �и� 0�̸� ����         */
    {
#if ERR_MSG
        printf("0���δ� ���� �� �����ϴ�.\n");
#endif
        return ERROR;                                /* ������ ��ȯ                          */
    }/* if chk_opr2 End */
    return operand1 % operand2;
}/* mod() End */

/* �Լ� ���� : - �ý��� ���� */
void print_func(const char func_name[])       /* TEST ���� �Լ� ���̿� �̸� ���             */
{
    /****************/
    /* ���� ����    */
    /****************/
    static int func_depth = ZERO;                   /* ����׽� ���� ���� ���               */
    
    /****************/
    /* source       */
    /****************/
    func_depth++;                                            /* �Լ� ���� ����               */
    printf("%d> [current function : %s]\n", 
        func_depth, func_name);                              /* �Լ� ���̿� ���� �Լ� ���   */
    func_depth--;                                            /* �Լ� ���� ����               */
} /* print_func() end */