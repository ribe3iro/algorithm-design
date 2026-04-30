#include<bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 100;

string s1, s2, s3;
int memo[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH*2];

bool solve(int i, int j, int k){
    if(i >= s1.length()-1 && j >= s2.length()-1 && k >= s3.length())
        return true;

    if(memo[i][j][k] > -1)
        return memo[i][j][k];

    if(s1[i] == s3[k] && s2[j] == s3[k])
        memo[i][j][k] = solve(i+1, j, k+1) || solve(i, j+1, k+1);
    else if(s1[i] == s3[k])
        memo[i][j][k] = solve(i+1, j, k+1);
    else if(s2[j] == s3[k])
        memo[i][j][k] = solve(i, j+1, k+1);
    else
        memo[i][j][k] = false;

    return memo[i][j][k];
}

int main(){
    cin >> s1 >> s2 >> s3;
    s1 += '\0';
    s2 += '\0';
    fill(&memo[0][0][0], &memo[0][0][0] + (MAX_LENGTH*MAX_LENGTH*MAX_LENGTH*2), -1);

    cout << (solve(0, 0, 0) ? "True" : "False") << endl;

    return 0;
}
