#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Node
{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->value = data;
        }
};

class Solution
{
    public:
        vector<vector<int>> Print(Node* root)
        {
            // 存储结果
            vector<vector<int>> result;
            vector<int> rlt_temp;

            // 边界条件
            if(root == nullptr)
            {
                return result;
            }

            // 辅助容器
            stack<Node*> stk[2]; // stk[0]是奇数层，stk[1]是偶数层
            int now = 0;
            int next = 1;
            Node* temp = root;

            // 根节点入栈
            stk[now].push(temp);

            // 遍历两个栈，当前两个栈为空时，跳出循环
            while(!stk[now].empty() || !stk[next].empty())
            {
                // 存储遍历结果
                temp = stk[now].top();
                rlt_temp.push_back(temp->value);
                stk[now].pop();

                // 当前层为奇数或偶数
                if(now == 0)
                {
                    // 当前层是奇数时，左子树先入栈，右子树后入栈
                    if(temp->left != nullptr)
                        stk[next].push(temp->left);

                    if(temp->right != nullptr)
                        stk[next].push(temp->right);
                }
                else
                {
                    // 当前层是偶数时，右子树先入栈，左子树后入栈
                    if(temp->right != nullptr)
                    {
                        stk[next].push(temp->right);
                    }
                    
                    if(temp->left != nullptr)
                    {
                        stk[next].push(temp->left);
                    }
                }

                // 当前层为空时，打印下一层
                if(stk[now].empty())
                {
                    result.push_back(rlt_temp);
                    rlt_temp.clear();
                    now = 1 - now;
                    next = 1 - next;
                }
            }
            return result;
        }
};

int main()
{
    return 0;
}