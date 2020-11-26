#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][4];
int d(vector<vector<int> > &land, int n, int c) {
    int temp = 0;
    if (c < 0 && c>3)
        return 0;
    if (n == 0) {
        return dp[0][c];
    }
    if (dp[n][c] != 0) {
        return dp[n][c];
    }
    for (int i = 0; i < 4; i++) {
        if (i != c) {
            dp[n-1][i] = d(land, n - 1, i);
            temp = dp[n-1][i]>temp?dp[n-1][i]:temp;
        }
    }

    return dp[n][c] = temp + land[n][c];
}
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int landSize = land.size();
    int tempAnswer = 0;

    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }
    
    for (int i = 0; i < 4; i++) {
        tempAnswer = d(land, landSize - 1,i);
        answer = answer > tempAnswer ? answer : tempAnswer;
    }
    return answer;
}