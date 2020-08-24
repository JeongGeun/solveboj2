#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

long long cal(vector<int>op,vector<int>op2, vector<long long int>number)
{
    vector<long long int>temp;
    vector<int>op3;
    for (int i = 0; i < op.size(); i++)
    {
        temp.clear();
        op3.clear();
        temp.push_back(number[0]);
        for (int j = 0; j < op2.size(); j++)
        {
            if (op[i] == op2[j])
            {
                if (op[i] == 0)
                {
                    temp[temp.size() - 1] += number[j + 1];
                }
                else if (op[i] == 1)
                {
                    temp[temp.size() - 1] -= number[j + 1];
                }
                else
                {
                    temp[temp.size() - 1] *= number[j + 1];
                }
            }
            else
            {
                op3.push_back(op2[j]);
                temp.push_back(number[j + 1]);
            }
        }
        op2 = op3;
        number = temp;
    }
    return abs(temp[0]);
}

long long solution(string expression) {
    long long answer = 0;
    vector<int> op;
    vector<int> op2;
    vector<long long int>number;
    string num = "";
    int visit[3] = { 0, };

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            if (expression[i] == '+') {
                op2.push_back(0);
                visit[0] = 1;
            }
            if (expression[i] == '-') {
                op2.push_back(1);
                visit[1] = 1;
            }
            if (expression[i] == '*') {
                op2.push_back(2);
                visit[2] = 1;
            }

            number.push_back(stoi(num));
            num.clear();
        }
        else
        {
            num += expression[i];
        }
    }
    number.push_back(stoi(num));

    for (int i = 0; i < 3; i++)
    {
        if (visit[i]) op.push_back(i);
    }

    do {
        answer=max(answer,cal(op,op2, number));
    } while (next_permutation(op.begin(), op.end()));
    //cout << answer << endl;
    return answer;
}

int main()
{
    solution("50*6-3*2");
}