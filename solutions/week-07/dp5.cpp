#include<bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 1000;

string s1, s2;
int memo[MAX_LENGTH][MAX_LENGTH];

int solve(int i, int j){
    if(i >= s1.length() || j >= s2.length())
        return 0;

    if(memo[i][j] > -1)
        return memo[i][j];
    
    if(s1[i] == s2[j])
        memo[i][j] = max({ 1 + solve(i+1,j+1), solve(i+1,j), solve(i,j+1) });
    else
        memo[i][j] = max( solve(i+1,j), solve(i,j+1) );

    return memo[i][j];
}

string get_solution(int i, int j){
    if(i >= s1.length() || j >= s2.length() || memo[i][j] == 0)
        return "";

    if( j+1 < s2.length() && memo[i][j] == memo[i][j+1] )
        return get_solution(i, j+1);
    if( i+1 < s1.length() && memo[i][j] == memo[i+1][j] )
        return get_solution(i+1, j);
    else
        return s1[i] + get_solution(i+1, j+1);
}

int main(){
    cin >> s1 >> s2;
    fill(&memo[0][0], &memo[0][0] + (MAX_LENGTH*MAX_LENGTH), -1);

    cout << solve(0, 0) << endl;
    // cout << get_solution(0, 0) << endl;

    return 0;
}
