#include<iostream>
#include<iomanip>
using namespace std;

class obst
{
    float a[20], b[20], wt[20][20], c[20][20];
    int r[20][20], n;
public:
    obst()
    {
        for (int i = 0; i < 20; i++)
        {
            a[i] = 0.0;
            b[i] = 0.0;
            for (int j = 0; j < 20; j++)
            {
                wt[i][j] = 0.0;
                c[i][j] = 0.0;
                r[i][j] = 0;
            }
        }
    }

    void input()
    {
        int i;
        cout << "\n**** PROGRAM FOR OBST ******\n";
        cout << "\nEnter the no. of nodes : ";
        cin >> n;
        cout << "\nEnter the probability for successful search :: " << endl;
        for (i = 1; i <= n; i++)
        {
            cout << "p[" << i << "]: ";
            cin >> a[i];
        }
        cout << "\nEnter the probability for unsuccessful search :: " << endl;
        for (i = 0; i <= n; i++)
        {
            cout << "q[" << i << "]: ";
            cin >> b[i];
        }
        con_obst();
        display_obst();
        cout << endl;
        cout << "Optimal Binary Search Tree Structure: " << endl;
        print(0, n);
        cout << endl;
    }

    void display_obst()
    {
        int i, j;
        cout << "W = { " << endl;
        for (i = 0; i <= n; i++)
        {
            cout << "      ";
            for (j = 0; j <= n; j++)
            {
                cout << setw(3) << wt[i][j] << " , ";
            }
            cout << "\b\b " << endl;
        }

        cout << "     }" << endl;
        cout << "C = { " << endl;
        for (i = 0; i <= n; i++)
        {
            cout << "      ";
            for (j = 0; j <= n; j++)
            {
                cout << setw(3) << c[i][j] << " , ";
            }
            cout << "\b\b " << endl;
        }
        cout << "     }" << endl;

        cout << "R = { " << endl;
        for (i = 0; i <= n; i++)
        {
            cout << "      ";
            for (j = 0; j <= n; j++)
            {
                cout << setw(3) << r[i][j] << " , ";
            }
            cout << "\b\b " << endl;
        }
        cout << "     }" << endl;
    }

    void con_obst()
    {
        int i, j, k, l;
        for (i = 0; i <= n; i++)
        {
            c[i][i] = 0.0;
            r[i][i] = 0;
            wt[i][i] = b[i];
        }

        for (int s = 1; s <= n; s++)
        {
            for (i = 0; i <= n - s; i++)
            {
                j = i + s;
                wt[i][j] = wt[i][j - 1] + a[j] + b[j];
                c[i][j] = 9999;
                for (k = i + 1; k <= j; k++)
                {
                    if (c[i][j] > c[i][k - 1] + c[k][j])
                    {
                        c[i][j] = c[i][k - 1] + c[k][j];
                        r[i][j] = k;
                    }
                }
                c[i][j] += wt[i][j];
            }
        }
    }
    
void print(int l1, int r1)
{
  if (l1 >= r1)
      return;
  if (r[l1][r[l1][r1] - 1] != 0)
      cout << "\n Left child of " << r[l1][r1] << " :: " << r[l1][r[l1][r1] - 1];
  if (r[r[l1][r1]][r1] != 0)
      cout << "\n Right child of " << r[l1][r1] << " :: " << r[r[l1][r1]][r1];
  print(l1, r[l1][r1] - 1);
  print(r[l1][r1], r1);
  return;
}
};

int main()
{
    obst o;
    o.input();
    return 0;
}

