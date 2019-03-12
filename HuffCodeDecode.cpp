#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<map>
#include<bitset>
using namespace std;

class Node
{
public:
    int data;
    char c;
    Node *left;
    Node *right;
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
int function1(priority_queue<Node *, vector<Node *>, comp> &heap)
{
    map<char, int> counter;
    fstream input_file;
    input_file.open("input.txt", ios::in | ios::out);
    string ch;
    counter['\n'] = 0;
    while(getline(input_file, ch))
    {
        for(int i = 0; i <= ch.size() - 1; i++)
        {
            if(counter.find(ch[i]) != counter.end())
            {
                counter[ch[i]] += 1;
            }
            else
            {
                counter[ch[i]] = 1;
            }
        }
        counter['\n'] += 1;
    }
    for(map<char, int>::iterator i = counter.begin(); i != counter.end(); ++i)
    {
        Node *temp = new Node(i->first, i->second);
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
    input_file.clear();
    input_file.seekg(0, ios::beg);
    fstream output_file;
    output_file.open("output.txt", fstream::out);
    string r = "";
    while(getline(input_file, ch))
    {
        for(int i = 0; i <= ch.size() - 1; i++)
        {
            r = r + s[ch[i]];
        }
        r = r + s['\n'];
    }
    int i;
    for(i = 0; i + 8 <= r.size();i += 8)
    {
        char tem;
        bitset<8> bits(r.substr(i, 8));
        tem = bits.to_ulong();
        output_file << tem;
    }
    string z(8 - r.size()%8, '0');
    if(r.size()%8 != 0)
    {
        char tem;
        bitset<8> bits(r.substr(i, 8) + z);
        tem = bits.to_ulong();
        output_file << tem;
    }
    input_file.close();
    output_file.close();
    return (8 - r.size()%8);
}
void function2(priority_queue<Node *, vector<Node *>, comp> &heap, int ext)
{
    fstream input_file;
    input_file.open("output.txt", ios::in | ios::out);
    string ch, r,temp;
    while(getline(input_file, ch))
    {
        if(ch.size() == 0)
        {
            r = r + "\n";
        }
        r = r + ch;
    }
    for(int i = 0; i <= r.size() - 1; i++)
    {
        int t = r[i];
        temp = temp + bitset<8>(t).to_string();
    }
    temp = temp.substr(0, temp.size() - ext%8);
    Node *curr = heap.top();
    for(int i = 0; i <= temp.size()-1;i++)
    {
        if(temp[i] == '0')
        {
            curr = curr->left;
            if(curr->c != '#')
            {
                cout << curr->c;
                curr = heap.top();
            }
        }
        else if(temp[i] == '1')
        {
            curr = curr->right;
            if(curr->c != '#')
            {
                cout << curr->c;
                curr = heap.top();
            }
        }
    }
    input_file.close();
}
int main()
{
    priority_queue<Node *, vector<Node *>, comp> heap;
    int ext = function1(heap);
    function2(heap, ext);
}