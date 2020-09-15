#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int>arr[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < info.size(); i++)
    {
        vector<string> vec;
        string temp = "";
        int lan = 0;
        int end = 0;
        int age = 0;
        int me = 0;
        for (int j = 0; j < info[i].size(); j++)
        {
            if (info[i][j] == ' ')
            {
                vec.push_back(temp);
                temp = "";
                continue;
            }
            temp += info[i][j];
        }
        vec.push_back(temp);
        if (vec[0][0]=='j')
        {
            lan = 0;
        }
        if (vec[0][0] == 'c')
        {
            lan = 1;
        }
        if (vec[0][0] == 'p')
        {
            lan = 2;
        }
        if (vec[1][0] == 'b')
        {
            end = 0;
        }
        if (vec[1][0] == 'f')
        {
            end = 1;
        }
        if (vec[2][0] == 'j')
        {
            age = 0;
        }
        if (vec[2][0] == 's')
        {
            age = 1;
        }
        if (vec[3][0] == 'c')
        {
            me = 0;
        }
        if (vec[3][0] == 'p')
        {
            me = 1;
        }
        arr[lan][end][age][me].push_back(stoi(vec[4]));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int x = 0; x < 2; x++)
                {
                    if (!arr[i][j][k][x].empty())
                        sort(arr[i][j][k][x].begin(), arr[i][j][k][x].end());
                }
            }
        }
    }


    for (int i = 0; i < query.size(); i++)
    {
        int ans = 0;
        string temp = "";
        vector<string> vec;
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        vector<int> v4;
        int lan = 0;
        int age = 0;
        int end = 0;
        int me = 0;
        for (int j = 0; j < query[i].size(); j++)
        {
            if (query[i][j] == ' ')
            {
                if (temp.compare("and") != 0)
                {
                    vec.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp = "";
                }
                continue;
            }
            temp += query[i][j];
        }
        vec.push_back(temp);
        if (vec[0][0] == 'j')
        {
            v1.push_back(0);
        }
        else if (vec[0][0] == 'c')
        {
            v1.push_back(1);
        }
        else if (vec[0][0] == 'p')
        {
            v1.push_back(2);
        }
        else
        {
            for (int i = 0; i < 3; i++) v1.push_back(i);
        }
        
        if (vec[1][0] == 'b')
        {
            v2.push_back(0);
        }
        else if (vec[1][0] == 'f')
        {
            v2.push_back(1);
        }
        else
        {
            for (int i = 0; i < 2; i++) v2.push_back(i);
        }

        if (vec[2][0] == 'j')
        {
            v3.push_back(0);
        }
        else if (vec[2][0] == 's')
        {
            v3.push_back(1);
        }
        else
        {
            for (int i = 0; i < 2; i++) v3.push_back(i);
        }

        if (vec[3][0] == 'c')
        {
            v4.push_back(0);
        }
        else if (vec[3][0] == 'p')
        {
            v4.push_back(1);
        }
        else
        {
            for (int i = 0; i < 2; i++) v4.push_back(i);
        }
        for (auto a : v1)
        {
            for (auto b : v2)
            {
                for (auto c : v3)
                {
                    for (auto d : v4)
                    {
                        vector<int>::iterator iter = lower_bound(arr[a][b][c][d].begin(), arr[a][b][c][d].end(), stoi(vec[4]));
                        int idx = iter - arr[a][b][c][d].begin();
                        ans += (arr[a][b][c][d].size() - idx);

                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}

int main()
{
    solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" }, { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"
});
}