//Variable:
            //number = 파일에서 숫자를 받는 변수
            //count = 숫자의 개수를 세는 변수
            //data = 숫자를 저장하는 변수
            //max = maximum value
            //min = minimum value
            //min_idx = index of minimum value
            //max_idx = index of maximum value

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void findMin(int data[], int n, int &min_idx, int &min);
void findMax(int data[], int n, int &max_idx, int &max);


int main()
{
    int number;
    int count=0;
    int data[10];
    int max = 0;
    int min = 0;
    int min_idx = 0;
    int max_idx = 0;
    ifstream infile("/Users/hyunjoon/Desktop/자료구조/LAB/lab1-2/lab1-2/lab1-2.txt");
    while (infile>>number)
    {
        data[count++]=number;
    }
    findMax(data, count, max_idx, max);
    findMin(data, count, min_idx, min);
    cout << "Minimum number is " << min << " at position " << min_idx+1 << endl;
    cout << "Maximum number is " << max << " at position " << max_idx+1 << endl;
    return 0;
}

void findMin(int data[], int n, int &min_idx, int &min)
{
    min = data[0];
    for(int i=0; i<n;i++)
    {
        if(data[i]<min)
        {
            min = data[i];
            min_idx = i;
        }
    }
}

void findMax(int data[], int n, int &max_idx, int &max)
{
    max = data[0];
    for(int i=0; i<n;i++)
    {
        if(data[i]>max)
        {
            max = data[i];
            max_idx = i;
        }
    }
}
