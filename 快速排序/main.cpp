#include <iostream>
using namespace std;

void quickSort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) //从后向前找到第一个比基准数小的数，放到前面
                j--;
            if (i != j)
                s[i++] = s[j];
            while (i < j && s[i] < x) //从前向后找到第一个比基准数大的数，放到后面
                i++;
            if (i != j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); //递归调用
        quickSort(s, i + 1, r);
    }
}

int main()
{
    int array[] = {34, 65, 12, 43, 67, 5, 78, 10, 3, 70};
    int length = sizeof(array) / sizeof(int);
    quickSort(array, 0, length - 1);
    for (int k = 0; k < length; k++)
        cout << array[k] << ',' << endl;

    return 0;
}
