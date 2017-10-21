# include <iostream>
# include <cstdio>

using namespace std;

int BinarySearch(int array[], int len, int requst)
{
    int left = 0;
    int right = len-1;
    int mid;

    while (left<right)
    {
        mid = (left+right)/2;
        if (request<=array[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if(request>array[len-1])
    {
        left++;
    }

    return left;
}

int main()
{
    int wanted;
    int test[5] = {1,2,3,4,5};
    wanted = BinarySearch(test,5,3);
    printf("The number you need is :",wanted);
    return 0;
}
