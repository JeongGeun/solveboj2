#include <string>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
int answer;

class Trie
{
public:
    Trie* next[26];
    int cnt;
    set <int>s;
    Trie()
    {
        cnt = 0;
        memset(next, 0, sizeof(next));
    }
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (next[i]) delete next[i];
        }
    }

    void insert(char* key)
    {
        if (*key=='\0')
        {
            return;
        }
        else
        {
            int cur = *key - 'a';
            if (next[cur] == NULL)
            {
                next[cur] = new Trie();                
            }
            next[cur]->cnt++;
            s.insert(cur);
            next[cur]->insert(key+1);
        }
    }

    void cal(Trie* node)
    {
        for (auto i=node->s.begin();i!= node->s.end();i++)
        {
    
                if (node->next[*i]->cnt == 1)
                {
                    answer += 1;
                }
                else if (node->next[*i]->cnt > 1)
                {
                    answer += node->next[*i]->cnt;
                    cal(node->next[*i]);
                }
           
        }
    }
};

int solution(vector<string> words) {
    Trie* root =new Trie();
    for (auto i : words)
    {
        vector<char> writable(i.begin(), i.end());
        writable.push_back('\0');
        char* ptr = &writable[0];
        root->insert(ptr);
    }
    root->cal(root);
    //delete root;
    return answer;
}

int main()
{
    solution({ "go","gone","guild" });
}