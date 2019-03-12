#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int> &a, int left, int right, int pivot)
{
    for(int i = left; i <= right; i++)
    {
        if(a[i] == pivot)
        {
            swap(a[i], a[right]);
            break;
        }
    }
    int leftpointer = left - 1;
    int rightpointer = right;
    for(;;)
    {
        for(;a[++leftpointer] < pivot;)
        {

        }
        for(;rightpointer > left && a[--rightpointer] > pivot;)
        {

        }
        if(leftpointer >= rightpointer)
        {
            break;
        }
        swap(a[leftpointer], a[rightpointer]);
    }
    swap(a[leftpointer], a[right]);
    return leftpointer;
}
int medianOfmedians(vector<int> &a, int left, int right, int k)
{
    int i = left, x, n = right - left + 1;
    while(i+5 < right)
    {
        sort(a.begin() + i, a.begin()+i+5);
        i += 5;
    }
    sort(a.begin()+i, a.begin()+right);
    int count = 0, j;
    vector<int> b;
    for(j = left + 4; j <= right; j = j + 5)
    {
        b.push_back(a[j-2]);
        count++;
    }
    j -= 5;
    if(j != right)
    {
        b.push_back(a[j + 1 + (right-j)/2]);
        count++;
    }
    if(count == 1)
    {
        x = b[0];
    }
    else
    {
        x = medianOfmedians(b, 0, count - 1, count/2);
    }
    int position = partition(a, left, right, x);
    if(position - left == k - 1)
    {
        return a[position]; 
    }
    else if(position - left > k - 1)
    {
        return medianOfmedians(a, left, position - 1, k);
    }
    return medianOfmedians(a, position + 1, right, k - position + left-1);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for(int i = 0; i <= n - 1; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
       cout << medianOfmedians(a, 0, n - 1, k) << endl;
    }
}