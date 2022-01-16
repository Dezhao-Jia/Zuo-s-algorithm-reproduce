#include <iostream>

using namespace std;

int main()
{
    //Pattern 01
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<=2; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=2*i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=4-2*i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }


    //Pattern 02
    char shap = 'A';
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<=2; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=2*i; j++)
        {
            cout << (char)shap;
        }
        shap++;
        cout << endl;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=4-2*i; j++)
        {
            cout << (char)shap;
        }
        shap++;
        cout << endl;
    }


    //Pattern 03
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<=2; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=2*i; j++)
        {
            if(j==0 || j==2*i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << " ";
        }
        for(int j=0; j<=4-2*i; j++)
        {
            if(j==0 || j==4-2*i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}