//猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nums[4];
void creat() //产生各位各不相同的4位随机数
{
    srand((unsigned)time(NULL));
    int randsave[10] = {0}; //0~9出现为1，未出现为0
    nums[0] = rand() % 10;
    randsave[nums[0]]++;
    int i = 1;
    for (int i = 1; i < 4; i++)
    {
        do
        {
            nums[i] = rand() % 10;
        } while (randsave[nums[i]] != 0); //当前数字出现过,重新赋值，直到该数未出现
        randsave[nums[i]]++;
    }
}

int judge(int in_num[4], int nums[4]) //返回所猜数字正确个数和数字对应位置正确个数
{
    //逐位比较
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
        printf("恭喜你猜对啦!\n");
        return 1;
    }
    printf("正确的数有%d个，正确的位置有%d个。\n", pos, count);
    return 0;
}

int main()
{
    creat(); //temp数组存放每一个数字出现的次数
    printf("请输入4个不同的数字开始游戏，输入0000可以查看答案！\n");
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
                answer++;//当输入0000时查看答案
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