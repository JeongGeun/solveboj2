#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101][4];

/***
    1. 3���� �迭�� ��հ� ���� ��ġ
    2. ����� ��� �ؿ� ��ġ�� ���� ����� �ִ� �� Ȯ��
    3. ���� ��� �� �ؿ� ����� �ְų� �� ���̵尡 �ٸ� ���� ����� ��츦 Ȯ��
    4. ������ ���� answer�� �� ��հ� ������ 2,3�� ������ �����ϴ� �� Ȯ��
    5. ��� ��հ� ���� �����ϸ� �������� else ���� �Ұ�
****/

bool checkmake(vector<int>v)
{
    if (v[2] == 0)
    {
        if(v[1]==0)
        { 
           return true;
        }
        else
        {
            for (int i = 1; i < 4; i++)
            {
                if (arr[v[1]][v[0]][i])
                {
                    return true;
                }
            }
        }
    }
    else
    {
        if ((arr[v[1]][v[0]][3] && arr[v[1]][v[0] + 1][1]) || arr[v[1]][v[0]][2]  || arr[v[1]][v[0] + 1][2])
        {
             return true;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i = 0; i < build_frame.size(); i++)
    {
        vector<int> v;
        vector<int>temp;
        vector<int>dtemp;
        int idx = 0;
        v = build_frame[i];

        if (v[3] == 0)//����
        {
            for (int j = 0; j < answer.size(); j++)
            {
                if (v[0] == answer[j][0] && v[1] == answer[j][1] && v[2] == answer[j][2])
                {
                    dtemp = answer[j];
                    idx = j;
                    if (v[2] == 0)
                    {
                        arr[v[1]][v[0]][0] = 0;
                        arr[v[1] + 1][v[0]][2]=0;
                    }
                    else
                    {
                        arr[v[1]][v[0]][1]=0;
                        arr[v[1]][v[0] + 1][3]=0;
                    }
                }
            }
            bool flag = true;
            for (int j = 0; j < answer.size(); j++)
            {
                if (j != idx)
                {
                    if (!checkmake(answer[j]))
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                answer.erase(answer.begin() + idx);
            }
            else
            {
                if (v[2] == 0)
                {
                    arr[v[1]][v[0]][0] = 1;
                    arr[v[1] + 1][v[0]][2] = 1;
                }
                else
                {
                    arr[v[1]][v[0]][1] = 1;
                    arr[v[1]][v[0] + 1][3] = 1;
                }
            }
        }
        else//��ġ
        {
            if (checkmake(v))
            {
                if (v[2] == 0)
                {
                    arr[v[1]][v[0]][0]++;
                    arr[v[1] + 1][v[0]][2]++;
                }
                else
                {
                    arr[v[1]][v[0]][1]++;
                    arr[v[1]][v[0]+1][3]++;
                }
                temp.push_back(v[0]);
                temp.push_back(v[1]);
                temp.push_back(v[2]);
                answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    solution(5, {{0, 0, 0, 1
}, { 2, 0, 0, 1
}, { 4, 0, 0, 1
}, { 0, 1, 1, 1
}, { 1, 1, 1, 1
}, { 2, 1, 1, 1
}, { 3, 1, 1, 1
}, { 2, 0, 0, 0
}, { 1, 1, 1, 0
}, { 2, 2, 0, 1 }});
}