#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int flag,count=26,i;
	vector <string> v;
	vector <string> v1;
	vector <string> :: iterator it;
	string str,s,tmp;
	cin >> str;
	s=str[0];
	for(i=0;i<str.size();i++)
	{
		flag=0;
		s=s+str[i+1];
		for(it=v1.begin();it!=v1.end();it++)
		{
			if(s==(*it))
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			count++;
			tmp=s.substr(0,s.size()-1);
			v1.push_back(s);
			v.push_back(tmp);
			s=str[i+1];
		}
	}
	for(i=27;i<count;i++)
		cout << i << " ";
	cout << "\n";
	for(it=v1.begin();it!=v1.end();it++)
		cout << (*it) << " ";
	cout << "\n";
//	for(it=v.begin();it!=v.end();it++)
//		cout << (*it) << " ";
//	cout << "\n";
	for(it=v.begin();it!=v.end();it++)
		cout << (*it);
	return 0; 
}
