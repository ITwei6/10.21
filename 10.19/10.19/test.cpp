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
////        //���������ĺʹδ��������Ҫ�ѱȽ�С��ȫ�����ꡣ
////        //�ұ���Ҫ���Ͻ�С�ĺ����ġ�
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
//			//���ﳤ��һ������ô��ֻ����һ����
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
//				else//һ��������һ������ĸ�϶�����ĸһ�ߴ�
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
//        //��������ĸ��ת����Сд��ĸ
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
//����һ�������Σ�������������ҵ�n��λ��
int Find(int n)
{
    //���ö�ά���鴴��. ��Ҫע��ÿ�еĵڶ��к͵����ڶ��е�������
    vector<vector<int>> vv(n,vector<int>(2*n-1));
   //��ά���ֿ���������
 
    for (int i = 0; i < n; i++)
    {
      
        //ÿ�еĵ�һ�к����һ�е�һ������1;
        vv[i][0] = vv[i][2 * i] = 1;
        for (int j = 0; j < 2 * (i+1) - 1; j++)
        {
            if (j == 1)//�ڶ���
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            else if (j == 2*i-1)//�����ڶ���
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j - 2];
            }
            else//���������������֮�� 
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
            }
        }
    }
    //ѭ����������������Ǿʹ��������ˣ�Ȼ���ڵ�n���ҵ�һ��ż��
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
// 64 λ������� printf("%lld")