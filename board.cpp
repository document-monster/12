#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
    //请完成类的设计
    vector <T>a;
public:
    Array(int n)
    {


    };
    
    void input(int n)
    {
        int i = 0;
        for (i = 0;i < n;i++)
        {
            T temp;
            cin >> temp ;
            a.push_back(temp);
        }
    }
    T& operator[](unsigned int temp)
    {
        return a[temp];
   }

};





class Fract
{
    //请完成类的设计
public:
    Fract(int, int);
    Fract() { fz = 0, fm = 1, i = 1; }
    void show();
    friend void operator +=(Fract& a, Fract b);
    friend istream& operator >>(istream& in, Fract& s)
    {
        int a, b;
        in >> a;
        in >> b;
        if (a * b > 0)
            s.i = 1;
        else
            s.i = -1;
        s.fz = a;s.fm = b;
        return in;
    }
private:
    unsigned int fz;
    unsigned int fm;
    int i;
};
void operator +=(Fract& a, Fract b)
{
    double x = (a.i * a.fz * b.fm + b.i * b.fz * a.fm);
    if (x >= 0)
    {
        a.i = 1;
        a.fz = a.fz * b.fm + b.fz * a.fm;
        a.fm = a.fm * b.fm;
    }
    else
    {
        a.i = -1;
        a.fz = a.fz * b.fm + b.fz * a.fm;
        a.fm = a.fm * b.fm;
    }
}
Fract::Fract(int a, int b)
{
    if (a * b >= 0)
        i = 1;
    else
        i = -1;
    fz = a;fm = b;
    int j;
    if (fz == 0 || fm == 1)
    {
        fz = a; fm = b;
    }
    else
    {
        for (j = 2;;j++)
        {
            if (fz % j == 0 && fm % j == 0)
            {
                fz = fz / j;
                fm = fm / j;
            }
            else break;
        }
    }
}
void Fract::show()
{
    Fract x(i * fz, fm);   
    if (x.fz == 0)
        cout << 0 << endl;
    else
        if (fz == fm)
            cout << '1' << endl;
        else
            if (x.fm == 1)
                cout << x.fz * x.i << endl;
            else
                if (i > 0)
                    cout << x.fz << '/' << x.fm << endl;
                else
                    cout << '-' << x.fz << '/' << x.fm << endl;
}
int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}