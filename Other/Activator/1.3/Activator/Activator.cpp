#include <iostream>
#include <conio.h>
#include <fstream>
#include <UrlMon.h>
#include <ctime>
#include <cstdlib>
#include <string>
#define random(x) rand()%(x)
#pragma comment(lib, "urlmon.lib")
using namespace std;
char s[29] = {0,0,0,0,0,45,0,0,0,0,0,45,0,0,0,0,0,45,0,0,0,0,0,45,0,0,0,0,0};
char key[10];
char c=' ', example[29];
int place = 0,num = 0;
bool yes = true;
bool b[10] = { 0 };
bool kv[29];
LCID lcid = GetSystemDefaultLangID();
int main()
{
	SetConsoleTitle("Switcher Activator");
	for (int i = 0;i <= 28;i++)
	{
		if (lcid == 2052)
			cout << "Switcher 激活程序" << endl << "Activator 1.3, Switcher LTS" << endl << "请输入激活码：";
		else
			cout << "Switcher Activate Tool" << endl << "Activator 1.3, Switcher LTS" << endl << "Please enter your key: ";
		for (int j = 0;j <= 28;j++)
		{
			cout << s[j];
		}
		c = _getch();
		if (c >= 'a' && c <= 'z')
		{
			c = c - 'a' + 'A';
		}
		if (c == 8&&i > 0)
		{
			i--;
			if (s[i] == '-') i--;
			s[i] = 0;
			i--;
			system("CLS");
			continue;
		}
		if (c == ' '||c == '-')
		{
			i--;
			system("CLS");
			continue;
		}
		if (s[i] == 0) s[i] = c;
		else i++, s[i] = c;
		system("CLS");
	}
	ifstream in;
	if (lcid == 2052)
		cout << "正在验证激活码...";
	else
		cout << "Verifying your key...";
	in.open(".\\config\\server");
	string Server;
	in >> Server;
	if(Server=="Github")
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/SN.ssn"), TEXT(".\\Resources\\SN.ssn"), 0, NULL);
	else
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/SN.ssn"), TEXT(".\\Resources\\SN.ssn"), 0, NULL);
	in.close();
	system("CLS");
	in.open(".\\Resources\\SN.ssn");
	for(int i = 0; i <= 28; i++)
		in >> example[i];
	in.close();
	for (int i = 0; i <= 28; i++)
	{
		if (example[i] != s[i])
		{
			if (lcid == 2052)
				cout << "序列号 " << i << "：错误" << endl;
			else
				cout << "Key No. " << i << ": Incorrect" << endl;
			yes = false;
			kv[i] = 1;
		}
		else
		{
			if (lcid == 2052)
				cout << "序列号 " << i << "：正确" << endl;
			else
				cout << "Key No. " << i << ": Correct" << endl;
		}
	}
	if (yes == false)
	{
		if (lcid == 2052)
			cout << "激活失败" << endl;
		else
			cout << "Failed to activate Switcher." << endl;
	}
	if (yes == true)
	{
		system("CLS");
		if (lcid == 2052)
			cout << "生成随机验证链...";
		else
			cout << "Generating verify file...";
		srand((int)time(0));
		memset(b, 0, sizeof(b));
		place = random(9);
		while (b[place] == true || place == 0)
		{
			place = random(9);
		}
		key[place] = 'S';
		b[place] = 1;
		place = random(9);
		while (b[place] == true || place == 0)
		{
			place = random(9);
		}
		key[place] = 'A';
		b[place] = 1;
		place = random(9);
		while (b[place] == true || place == 0)
		{
			place = random(9);
		}
		key[place] = 'U';
		b[place] = 1;
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= 9; i++)
		{
			if (key[i] == 0)
			{
				num = random(9);
				key[i] = num + 48;
			}
		}
		if (lcid == 2052)
			cout << endl << "激活成功" << endl;
		else
			cout << endl << "Success." << endl;
		ofstream out;
		out.open(".\\Resources\\Activate.sact");
		out << '{';
		for (int i = 1; i <= 9; i++)
		{
			out << key[i];
		}
		out << '}' << endl;
		out.close();
		DeleteFile(".\\config\\DEMO");
	}
	DeleteFile(".\\Resources\\SN.ssn");
	if (lcid == 2052)
		cout << "激活码：   ";
	else
		cout << "Key:     ";
	for (int i = 0; i <= 28; i++)
	{
		cout << s[i];
	}
	cout << endl;
	if (lcid == 2052)
		cout << "验证情况：[";
	else
		cout << "Status: [";
	for (int i = 0; i <= 28; i++)
	{
		if (kv[i] == 1) cout << "x";
		else cout << " ";
	}
	cout << "]" << endl;
	system("PAUSE");
}
