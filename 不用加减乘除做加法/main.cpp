#include <iostream>

int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        // 异或 ：相等为0，不相等为1
        sum = num1 ^ num2;
        // 位与 ：两个数都为1时结果为1
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;

        std::cout << "num1: " << num1 << std::endl;
        std::cout << "num2: " << num2 << std::endl;
    } while (num2 != 0);

    return num1;
}


void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if (result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. Failed\n", num1, num2, result);
}

int main(int argc, char *argv[])
{
    Test(10, 2, 12);
    return 1;
}
