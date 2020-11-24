#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int landSize = land.size();
    for(int i = 0; i<4;i++){
        dp[0][i] = land[0][i];
    }
    for(int i = 1;i<landSize;i++){
        for(int j = 0;j<4;j++){
            for(int k = 0;k<4;k++){
                if(j!=k)
                    dp[i][j] = dp[i][j]>dp[i-1][k]+land[i][j]?dp[i][j]:dp[i-1][k]+land[i][j];
            }
        }
    }
    // dp[landSIze-1]의 max값 구하기
    answer = *max_element(dp[landSize-1], dp[landSize-1]+4);
    return answer;
}