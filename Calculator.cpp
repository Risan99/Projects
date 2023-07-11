#include <bits/stdc++.h>
using namespace std;

class Calc
{
public:
   double addition(double a, double b)
   {
      return a + b;
   }

   double subtraction(double a, double b)
   {
      return a - b;
   }
   double multi(double a, double b)
   {
      return a * b;
   }
   double division(double a, double b)
   {
      return a / b;
   }
   double persent(double a, double b)
   {
      return a * (b / 100);
   }
   double squareroot(double a)
   {
      return sqrt(a);
   }
   double power(double a, double b)
   {
      return pow(a, b);
   }
   void solve(double a, double b, double c)
   {
      double z = (b * b) - (4 * a * c), x1, x2;
      if (z >= 0)
      {
         x1 = ((-b + sqrt(z)) / (2 * a));
         x2 = ((-b - sqrt(z)) / (2 * a));
         cout << "X1= " << x1 << endl;
         cout << "X2= " << x2 << endl;
      }
      else
         cout << "The roots of this equation is Imaginary\n";
   }
};
class logarith : private Calc
{
public:
   double logbase(double n)
   {
      return log(n);
   }
   double apower(double a, double n)
   {
      if (n == 1)
         return a;
      return a * apower(a, n - 1);
   }
};
class trigonmetry : public Calc
{
public:
   double sinc(double n)
   {
      return sin(n);
   }
   double cosine(double n)
   {
      return cos(n);
   }
   double tang(double n)
   {
      return tan(n);
   }
};
class square : private Calc
{
   double psqr(double n)
   {
      return pow(n, 2);
   }
};
int main()
{
   Calc obj = Calc();
   logarith child = logarith();
   trigonmetry child2 = trigonmetry();
   bool p = 1;
   while (p)
   {
      long long a, b, c, op;
      double x, y, z;
      cout << "[1] Addition.\n";
      cout << "[2] Subtraction.\n";
      cout << "[3] Multiplication.\n";
      cout << "[4] Division.\n";
      cout << "[5] Persentage.\n";
      cout << "[6] Equation Solving.\n";
      cout << "[7] X^n Exponentioal\n";
      cout << "[8] Square Root\n";
      cout << "[9] Trigonmetry value\n";

      cout << "Or press Any other Number to Exit\n";
      cin >> op;
      if (op == 1)
      {
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         cout << obj.addition(x, y) << endl;
      }
      else if (op == 2)
      {
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         cout << child2.subtraction(x, y) << endl;
      }
      else if (op == 3)
      {
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         cout << obj.multi(x, y) << endl;
      }
      else if (op == 4)
      {
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         if (y == 0)
         {
            cout << "No number can be Devided by 0(Zero)\n";
            p = 0;
         }
         else
         {
            cout << fixed << setprecision(2) << obj.division(x, y) << endl;
         }
      }
      else if (op == 5)
      {
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         cout << obj.persent(x, y) << endl;
      }
      else if (op == 6)
      {
         cout << "Equation format ax^2+bx+c=0\n";
         cout << "a= ";
         cin >> x;
         cout << "b= ";
         cin >> y;
         cout << "c= ";
         cin >> z;
         obj.solve(x, y, z);
      }
      else if (op == 7)
      {
         int key;
         cout << "[1] to Do it with funcion\n";
         cout << "[2] with requrtion\n";
         cin >> key;
         cout << "x= ";
         cin >> x;
         cout << "n= ";
         cin >> y;
         if (key == 1)
            cout << obj.power(x, y) << endl;
         else
            cout << child.apower(x, y) << endl;
      }
      else if (op == 8)
      {
         cout << "a= ";
         cin >> x;
         cout << obj.squareroot(x) << endl;
      }
      else if (op == 9)
      {
         int key;
         cout << "[1] sin\n";
         cout << "[2] cos\n";
         cout << "[3] tan\n";

         cin >> key;
         cout << "x= ";
         cin >> x;

         if (key == 1)
            cout << child2.sinc(x) << endl;
         else if (key == 2)
            cout << child2.cosine(x) << endl;
         else
            cout << child2.tang(x) << endl;
      }
      else
      {
         cout << "OOPS!! Invalid Input. Good Bye\n";
         p = 0;
      }
   }
   return 0;
}
