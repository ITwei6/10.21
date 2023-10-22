//
//
//#include <iostream>
//using namespace std;
//
////class A
////{
////public:
////	 void f()
////	{
////		cout << "A" << endl;
////	}
////
////};
////class B :public A
////{
////	virtual void f()
////	{
////		cout << "B" << endl;
////	}
////};
////int main()
////{
////	//B* p1 = new A;
////	A* p = new B;
////	p->f();
////	delete p;
////	return 0;
////}
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////int findMinimum(int n, vector<int> left, vector<int> right)
////{
////    sort(left.begin(), left.end());
////    sort(right.begin(), right.end());
////    int ret1 = 0, ret2 = 0;
////    for (int i = 0; i < n - 2; i++)
////    {
////        ret1 += left[i];
////        //不加上最大的和次大，左边至少要把比较小的全部拿完。
////        //右边需要加上较小的和最大的。
////        ret2 += right[i];
////    }
////    ret1 += 1;
////    ret2 += right[n - 1] + 1;
////    return ret1 + ret2;
////}
////int main()
////{
////    vector<int> v1 = { 0,7,1,6 };
////    vector<int> v2 = { 1,5,0,6 };
////    cout<<findMinimum(4, v1, v2);
////}
//////1010
//#include <string>
//#include <vector>
//int main()
//{
//
//	string str;
//	getline(cin,str);
//	int pos = str.find('-');
//	string s1(str.begin(), str.begin() + pos);
//	string s2(str.begin() + pos + 1, str.end());
//		if (s1.size() > s2.size())
//		{
//			if (s1[0] == '1' && s2[0] >= 'A')
//			{
//				cout << s2 << endl;
//			}
//				
//			else cout << s1 << endl;
//		}
//		else if(s1.size() < s2.size())
//		{
//			if (s2[0] == '1' && s1[0] >= 'A')
//			{
//				cout << s1 << endl;
//			}
//				
//			else cout << s2 << endl;
//		}
//		else
//		{
//
//
//			//这里长度一样，那么就只能是一张牌
//			if (s1[0] == '2')cout << s1 << endl;
//			else if (s2[0] == '2')cout << s2 << endl;
//			else
//			{
//				if (s1[0] >= 'A' && s1[0] <= 'Q' && s2[0] >= 'A' && s2[0] <= 'Q')
//				{
//					if (s1[0] > s2[0])cout << s2;
//					else cout << s1;
//				}
//				else if (s1[0] >= '3' && s1[0] <= '10' && s2[0] >= '3' && s2[0] <= '10')
//				{
//					
//					if (s1[0] > s2[0])cout << s1;
//					else cout << s2;
//				}
//				else//一边是数字一边是字母肯定是字母一边大
//				{
//					if (s1[0] > s2[0])cout << s2;
//					else cout << s1;
//				}
//
//				
//			}
//
//		}
//		
//	
//	
//}
////int main()
////{
////	cout << 'A' << " " << '10' << endl;
////}
//#include <iostream>
//using namespace std;
//#include<map>
//#include <string>
//int main()
//{
//    map<char, int> m;
//    string str;
//    getline(cin, str);
//    char ch;
//    cin >> ch;
//    for (auto& e : str)
//    {
//        //将所有字母都转换成小写字母
//   
//        m[tolower(e)]++;
//    }
//
//    cout << m[tolower(ch)] << endl;
//
//
//}
#include <iostream>
using namespace std;
#include <vector>
//创建一个三角形，在三角形里查找第n行位置
int Find(int n)
{
    //利用二维数组创建. 但要注意每行的第二列和倒数第二列的特殊性
    vector<vector<int>> vv(n,vector<int>(2*n-1));
   //二维数字开创多少行
 
    for (int i = 0; i < n; i++)
    {
      
        //每行的第一列和最后一列第一个都是1;
        vv[i][0] = vv[i][2 * i] = 1;
        for (int j = 0; j < 2 * (i+1) - 1; j++)
        {
            if (j == 1)//第二列
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            else if (j == 2*i-1)//倒数第二列
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j - 2];
            }
            else//正常情况是三个数之和 
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
            }
        }
    }
    //循环下来，类杨辉三角就创建出来了，然后在第n行找第一个偶数
    for (int i = 1; i < vv[n-1].size(); i++)
    {
        if (vv[n - 1][i] % 2 == 0)
            return i+1;
    }
    return -1;
}
int main()
{

    int n;
    cin >> n;
    cout << Find(n);

}
// 64 位输出请用 printf("%lld")