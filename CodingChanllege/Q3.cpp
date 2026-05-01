#include <bits/stdc++.h>
using namespace std;

static const int MOD = 30011;

int p = 3;

/* Expression tree node */
struct Node
{
    char type; // 'c' = constant, 'v' = variable, '+', '*', '^'
    int value; // constant value or exponent (for ^)
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *parse(const string &s)
{
    stack<Node *> st;

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];

        if (isdigit(c))
        {
            Node *n = new Node();
            n->type = 'c';
            n->value = c - '0';
            st.push(n);
        }
        else if (c >= 'a' && c <= 'z')
        {
            Node *n = new Node();
            n->type = 'v';
            n->value = c - 'a';
            st.push(n);
        }
        else if (c == '+' || c == '*')
        {
            Node *n = new Node();
            n->type = c;
            st.push(n);
        }
        else if (c == '^')
        {
            Node *n = new Node();
            n->type = '^';
            i++; // read exponent
            n->value = s[i] - '0';
            st.push(n);
        }
        else if (c == ')')
        {
            Node *top = st.top();
            st.pop();

            if (top->type == '^')
            {
                // unary operator
                Node *A = st.top();
                st.pop();
                top->left = A;
                st.push(top);
            }
            else
            {
                // binary operator
                Node *B = top;
                Node *op = st.top();
                st.pop();
                Node *A = st.top();
                st.pop();
                op->left = A;
                op->right = B;
                st.push(op);
            }
        }
    }

    return st.top();
}

/* Convolution for addition */
vector<int> addConv(const vector<int> &A, const vector<int> &B)
{
    vector<int> C(p, 0);
    for (int i = 0; i < p; i++)
        if (A[i])
            for (int j = 0; j < p; j++)
                if (B[j])
                {
                    int idx = (i + j) % p;
                    C[idx] = (C[idx] + A[i] * B[j]) % MOD;
                }
    return C;
}

/* Convolution for multiplication */
vector<int> mulConv(const vector<int> &A, const vector<int> &B)
{
    vector<int> C(p, 0);
    for (int i = 0; i < p; i++)
        if (A[i])
            for (int j = 0; j < p; j++)
                if (B[j])
                {
                    int idx = (int)((1LL * i * j) % p);
                    C[idx] = (C[idx] + A[i] * B[j]) % MOD;
                }
    return C;
}

/* Fast exponentiation of DP */
vector<int> powerConv(vector<int> base, int exp)
{
    vector<int> res(p, 0);
    res[1 % p] = 1; 

    while (exp)
    {
        if (exp & 1)
            res = mulConv(res, base);
        base = mulConv(base, base);
        exp >>= 1;
    }
    return res;
}


vector<int> solve(Node *node)
{
    if (node->type == 'c')
    {
        vector<int> dp(p, 0);
        dp[node->value % p] = 1;
        return dp;
    }

    if (node->type == 'v')
    {
        vector<int> dp(p, 1); 
        return dp;
    }

    if (node->type == '+')
    {
        auto A = solve(node->left);
        auto B = solve(node->right);
        return addConv(A, B);
    }

    if (node->type == '*')
    {
        auto A = solve(node->left);
        auto B = solve(node->right);
        return mulConv(A, B);
    }

    
    auto A = solve(node->left);
    vector<int> dp(p, 0);
    dp[0] = A[0]; 
    return dp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "(((a+y)*(z+8))^2)";

    Node *root = parse(s);
    vector<int> dp = solve(root);

    cout << dp[0] % MOD << "\n";
    return 0;
}
