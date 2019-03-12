#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
private:
    int n;
    vector< vector<long long int> > A;
    void copy(Matrix &B, Matrix &a, int low1, int low2, int high1, int high2)
    {
        for(int i = low1, m = 0; i <= high1; i++, m++)
        {
            for(int j = low2, n = 0; j <= high2; j++, n++)
            {
                B.A[i][j] = a.A[m][n];
            }
        }
    }
public:
    Matrix(int m)
    {
        n = m;
        for(int i = 0; i <= m - 1;i++)
        {
            vector<long long int> tem;
            for(int j = 0; j <= n - 1; j++)
            {
                tem.push_back(0);
            }
            A.push_back(tem);
        }
    }
    Matrix(Matrix &B, int low1, int low2, int high1, int high2)
    {
        n = high1 - low1 + 1;
        for(int i = 0; i <= n - 1;i++)
        {
            vector<long long int> tem;
            for(int j = 0; j <= n - 1; j++)
            {
                tem.push_back(0);
            }
            A.push_back(tem);
        }
        for(int i = low1, m = 0; i <= high1; i++, m++)
        {
            for(int j = low2, n = 0; j <= high2; j++, n++)
            {
                this->A[m][n] = B.A[i][j];
            }
        }
    }
    Matrix(Matrix *B, int low1, int low2, int high1, int high2)
    {
        n = high1 - low1 + 1;
        for(int i = 0; i <= n - 1;i++)
        {
            vector<long long int> tem;
            for(int j = 0; j <= n - 1; j++)
            {
                tem.push_back(0);
            }
            A.push_back(tem);
        }
        for(int i = low1, m = 0; i <= high1; i++, m++)
        {
            for(int j = low2, n = 0; j <= high2; j++, n++)
            {
                this->A[m][n] = B->A[i][j];
            }
        }
    }
    Matrix operator+(Matrix B)
    {
        Matrix C(B.n);
        for(int i = 0; i <= B.n - 1;i++)
        {
            for(int j = 0; j <= B.n - 1; j++)
            {
                C.A[i][j] = this->A[i][j] + B.A[i][j];
            }
        }
        return C;
    }
    Matrix operator-(Matrix B)
    {
        Matrix C(B.n);
        for(int i = 0; i <= B.n - 1;i++)
        {
            for(int j = 0; j <= B.n - 1; j++)
            {
                C.A[i][j] = this->A[i][j] - B.A[i][j];
            }
        }
        return C;
    }
    Matrix operator*(Matrix B)
    {   Matrix C(B.n);
        if(B.n == 2)
        {
            long long int p1 = this->A[0][0] * (B.A[0][1] - B.A[1][1]);
            long long int p2 = (this->A[0][0] + this->A[0][1]) * B.A[1][1];
            long long int p3 = (this->A[1][0] + this->A[1][1]) * B.A[0][0];
            long long int p4 = this->A[1][1] * (B.A[1][0] - B.A[0][0]);
            long long int p5 = (this->A[0][0] + this->A[1][1])*(B.A[0][0] + B.A[1][1]);
            long long int p6 = (this->A[0][1] - this->A[1][1])*(B.A[1][0] + B.A[1][1]);
            long long int p7 = (this->A[0][0] - this->A[1][0])*(B.A[0][0] + B.A[0][1]);
            C.A[0][0] = p5 + p4 - p2 + p6;
            C.A[0][1] = p1 + p2;
            C.A[1][0] = p3 + p4;
            C.A[1][1] = p1 + p5 - p3 - p7;
        }
        else
        {
            Matrix p1(B.n/2), p2(B.n/2), p3(B.n/2), p4(B.n/2), p5(B.n/2), p6(B.n/2), p7(B.n/2);
            Matrix a(this, 0, 0, n/2 - 1, n/2 - 1);
            Matrix b(this, 0, n/2, n/2 - 1, n - 1);
            Matrix c(this, n/2, 0, n - 1, n/2 - 1);
            Matrix d(this, n/2, n/2, n - 1, n - 1);
            Matrix e(B, 0, 0, n/2 - 1, n/2 - 1);
            Matrix f(B, 0, n/2, n/2 - 1, n - 1);
            Matrix g(B, n/2, 0, n - 1, n/2 - 1);
            Matrix h(B, n/2, n/2, n - 1, n - 1);
            p1 = a*(f-h);
            p2 = (a+b)*h;
            p3 = (c+d)*e;
            p4 = d*(g-e);
            p5 = (a+d)*(e+h);
            p6 = (b-d)*(g+h);
            p7 = (a-c)*(e+f);
            a = p5 + p4 - p2 + p6;
            b = p1 + p2;
            c = p3 + p4;
            d = p1 + p5 - p3 - p7;
            copy(C, a, 0, 0, n/2 - 1, n/2 - 1);
            copy(C, b, 0, n/2, n/2 - 1, n - 1);
            copy(C, c, n/2, 0, n - 1, n/2 - 1);
            copy(C, d, n/2, n/2, n - 1, n - 1);
        }
        return C;
    }
    friend istream &operator>>(istream &input, Matrix &B)
    {
        for(int i = 0; i <= B.n - 1; i++)
        {
            for(int j = 0; j <= B.n - 1; j++)
            {
                input >> B.A[i][j];
            }
        }
        return input;
    }
    friend ostream &operator<<(ostream &output, Matrix &B)
    {
        for(int i = 0 ; i <= B.n - 1; i++)
        {
            for(int j = 0;j <= B.n - 1; j++)
            {
                output << B.A[i][j]<< " ";
            }
            output << endl;
        }
        return output;
    }
};
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        Matrix A(n);
        Matrix B(n);
        Matrix C(n);
        cin >> A;
        B = A;
        C = A * B;
        cout << C << endl;
    }
    return 0;
}
