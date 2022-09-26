// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;
int DP[500];
int length;
int dataline[500];
int answer = -1;
int main()
{
    cin >> length;
    cin >> DP[0];
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> dataline[j];
        }
        int temp[500];
        temp[0] = DP[0] + dataline[0];
        temp[i] = DP[i-1] + dataline[i];
        for (int j = 1; j < i; j++)
        {
            if (DP[j - 1] > DP[j])
            {
                temp[j] = DP[j - 1] + dataline[j];
            }
            else
            {
                temp[j] = DP[j] + dataline[j];
            }
        }   
        copy(&temp[0], &temp[0] + 500, &DP[0]);
    }
    for (int i = 0; i < length; i++)
    {
        if (answer < DP[i])
        {
            answer = DP[i];
        }
    }
    cout << answer;
}
