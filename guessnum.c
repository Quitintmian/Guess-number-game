//��������Ϸ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nums[4];
void creat() //������λ������ͬ��4λ�����
{
    srand((unsigned)time(NULL));
    int randsave[10] = {0}; //0~9����Ϊ1��δ����Ϊ0
    nums[0] = rand() % 10;
    randsave[nums[0]]++;
    int i = 1;
    for (int i = 1; i < 4; i++)
    {
        do
        {
            nums[i] = rand() % 10;
        } while (randsave[nums[i]] != 0); //��ǰ���ֳ��ֹ�,���¸�ֵ��ֱ������δ����
        randsave[nums[i]]++;
    }
}

int judge(int in_num[4], int nums[4]) //��������������ȷ���������ֶ�Ӧλ����ȷ����
{
    //��λ�Ƚ�
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (in_num[i] == nums[i])
            count++;
    }

    int save[10] = {0};
    for (int i = 0; i < 4; i++)
    {
        save[nums[i]]++;
    }

    int pos = 0;

    for (int i = 0; i < 4; i++)
    {
        if (save[in_num[i]] == 1)
            pos++;
    }
    if (count == 4 && pos == 4)
    {
        printf("��ϲ��¶���!\n");
        return 1;
    }
    printf("��ȷ������%d������ȷ��λ����%d����\n", pos, count);
    return 0;
}

int main()
{
    creat(); //temp������ÿһ�����ֳ��ֵĴ���
    printf("������4����ͬ�����ֿ�ʼ��Ϸ������0000���Բ鿴�𰸣�\n");
    char temp[4];
    int in_num[4];
    int flag;
    int answer;
    do
    {
        scanf("%s", temp);
        answer=0;
        for (int i = 0; i < 4; i++)
        {
            in_num[i] = temp[i] - '0';
            if (in_num[i] == 0)
                answer++;//������0000ʱ�鿴��
        }
        if (answer == 4)
        {
            printf("Answer------>");
            for (int i = 0; i < 4; i++)
            {
                printf("%d", nums[i]);
            }
            printf("\n");
            system("pause");
            exit(0);
        }
        flag = judge(in_num, nums);

    } while (!flag);

    system("pause");
}