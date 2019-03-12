#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    char c;
    Node *left;
    Node *right;
    Node()
    {
        
    }
    Node(char d, int e)
    {
        this->data = e;
        this->c = d;
        this->left = this->right = NULL; 
    }
    bool operator>(const Node& n)
    {
        return (this->data>n.data);
    }
    bool operator<(const Node& n)
    {
        return (this->data<n.data);
    }
    bool operator>=(const Node& n)
    {
        return (this->data>=n.data);
    }
    bool operator<=(const Node& n)
    {
        return (this->data<=n.data);
    }
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class comp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
void HuffCode(map<char, string> &s, Node *temp, string code)
{
    if(temp->c != '#')
    {
        s[temp->c] = code;
    }
    else
    {
        HuffCode(s, temp->left, code+"0");
        HuffCode(s, temp->right, code+"1");
    } 
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<char> ch;
        int n;
        priority_queue<Node *, vector<Node *>, Node> heap;
        cin >> n;
        int z = n;
        while(n--)
        {
            char ch_temp;
            int fr_temp;
            cin >> ch_temp >> fr_temp;
            ch.push_back(ch_temp);
            Node *temp = new Node(ch_temp, fr_temp);
            heap.push(temp);
        }
        while(heap.size() != 1)
        {
            Node *left = heap.top();
            heap.pop();
            Node *right = heap.top();
            heap.pop();
            if(*left > *right)
            {
                swap(left, right);
            }
            Node *root = new Node('#', (left->data + right->data));
            root->left = left;
            root->right = right;
            heap.push(root);
        }
        map<char, string> s;
        HuffCode(s, heap.top(), "");
        for(int i = 0; i <= z - 1; i++)
        {
            cout << s[ch[i]] << endl;
        }
    }
}