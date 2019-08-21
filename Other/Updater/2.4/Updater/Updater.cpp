#include "stdafx.h"
#include "upd.hpp"
#pragma comment (lib,"User32.lib")
#pragma comment( lib,"Urlmon.lib")
#pragma comment( lib, "wininet.lib") 
using namespace std;
int adon=0;
LCID lcid = GetSystemDefaultLangID();
bool SwitcherActivateJudgeFunc()
{
	ifstream in;
	string KeyUsed;
	bool VerifyPoints[3] = { 0 };
	in.open(".\\Resources\\Activate.sact");
	in >> KeyUsed;
	in.close();
	for (int i = 1; i <= 9; i++)
	{
		if (KeyUsed[i] == 'U')
			VerifyPoints[0] = TRUE;
		if (KeyUsed[i] == 'S')
			VerifyPoints[1] = TRUE;
		if (KeyUsed[i] == 'A')
			VerifyPoints[2] = TRUE;
	}
	if (KeyUsed.size() == 11
		&& KeyUsed[0] == '{'
		&& KeyUsed[10] == '}'
		&& VerifyPoints[0]
		&& VerifyPoints[1]
		&& VerifyPoints[2])
		return TRUE;
	else return FALSE;
}
void cleancachegit()
{
	if (lcid == 2052)
		cout << "�������� Url ���棬���Ժ�..." << endl;
	else
		cout << "Cleaning Url caches, please wait..." << endl;
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/AAS.exe");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/av.sver");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfa.conform");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xyl.exe");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xv.sver");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfx.conform");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/Setup.exe");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfs.conform");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/addon.exe");
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfado.conform");
}
void downloadgitaas()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			if (lcid == 2052)
				cout << "׼������" << endl;
			else
				cout << "Ready to retry." << endl;
		}
		if (lcid == 2052)
			cout << "���� AAS..." << endl;
		else
			cout << "Downloading AAS..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/AAS.exe"), TEXT(".\\Resources\\AAS.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/av.sver"), TEXT(".\\Resources\\av.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfa.conform"), TEXT(".\\Resources\\cfa.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfa.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�AAS ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download AAS after 3 tries, skipped." << endl;
	}
}
void downloadgitxyl()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			if (lcid == 2052)
				cout << "׼������" << endl;
			else
				cout << "Ready to retry." << endl;
		}
		if (lcid == 2052)
			cout << "����Ф���ֵĹ���..." << endl;
		else
			cout << "Downloading The Story of XYL..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xyl.exe"), TEXT(".\\Resources\\xyl.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xv.sver"), TEXT(".\\Resources\\xv.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfx.conform"), TEXT(".\\Resources\\cfx.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfx.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�Ф���ֵĹ��� ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download The Story of XYL after 3 tries, skipped." << endl;
	}
}
void downloadgitsetup()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			{
				if (lcid == 2052)
					cout << "׼������" << endl;
				else
					cout << "Ready to retry." << endl;
			}
		}
		if (lcid == 2052)
			cout << "���� Switcher Setup..." << endl;
		else
			cout << "Downloading Switcher Setup..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/Setup.exe"), TEXT(".\\Resources\\Setup.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfs.conform"), TEXT(".\\Resources\\cfs.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfs.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�Switcher Setup ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download Switcher Setup after 3 tries, skipped." << endl;
	}
}
void downloadgitaddon()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			{
				if (lcid == 2052)
					cout << "׼������" << endl;
				else
					cout << "Ready to retry." << endl;
			}
		}
		if (lcid == 2052)
			cout << "���ظ��Ӹ���..." << endl;
		else
			cout << "Downloading Add-on Update..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/addon.exe"), TEXT(".\\Resources\\addon.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfado.conform"), TEXT(".\\Resources\\cfado.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfado.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ󣬸��Ӹ��� ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download Add-on Update after 3 tries, skipped." << endl;
	}
}
void killgit()
{
	system("taskkill /im Activator.exe /f");
	system("taskkill /im AAS.exe /f");
	system("taskkill /im xyl.exe /f");
	system("taskkill /im Switcher.exe /f");
}
void cleangit()
{
	if (lcid == 2052)
		cout << "����������ʱ�ļ������Ժ�" << endl;
	else
		cout << "Cleaning temp files, please wait..." << endl;
	if ((_access(".\\Resources\\upver.sver", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\upver.sver"));
	}
	if ((_access(".\\Resources\\cfa.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfa.conform"));
	}
	if ((_access(".\\Resources\\cfx.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfx.conform"));
	}
	if ((_access(".\\Resources\\cfs.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfs.conform"));
	}
	if ((_access(".\\Resources\\cfado.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfado.conform"));
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\addon.exe"));
	}
	if ((_access(".\\Resources\\Setup.exe", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\Setup.exe"));
	}
}
void applygit()
{
	if ((_access(".\\Resources\\Setup.exe", 0)) != -1)
	{
		if (lcid == 2052)
			cout << "�������̲�Ӧ�� Switcher ����" << endl;
		else
			cout << "Killing processes to apply Switcher updates..." << endl;
		killgit();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\Setup.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		if (lcid == 2052)
			cout << "�������̲�Ӧ�ø��Ӹ���" << endl;
		else
			cout << "Killing processes to apply Add-on updates..." << endl;
		killgit();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\addon.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
}
void nonegit()
{
	system("CLS");
	if (lcid == 2052)
		cout << "��������Ҫ���ص������" << endl << "���������1-4����0 �˳���";
	else
		cout << "Input what you want to download:" << endl << "Numbers (1-4), Exit: 0" << endl;
	int n,op;
	n = _getch()-48;
	while(n<0||n>4)
	{
		if (lcid == 2052)
			cout << endl << "��Ч���룬�����ԣ�";
		else
			cout << "Invalid input, please try again: ";
		n = _getch() - 48;
	}
	if (n == 0) exit(0);
	if (lcid == 2052)
		cout << endl << "����������ţ�" << endl << "1.AAS 2.Ф���ֵĹ��� 3.Switcher Setup 4.���Ӹ��� No." << adon << endl;
	else
		cout << endl << "Which is program you want to download?" << endl << "1.AAS 2.The Story of XYL 3.Switcher Setup 4.Add-on Update No. " << adon << endl;
	int a[5];
	memset(a,1,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		a[op]=1;
	}
	system("CLS");
	if (lcid == 2052)
		cout << "������..." << endl;
	else
		cout << "downloading..." << endl;
	if(a[1]==1)
	{
		downloadgitaas();
	}
	if(a[2]==1)
	{
		downloadgitxyl();
	}
	if(a[3]==1)
	{
		downloadgitsetup();
	}
	if (a[4] == 1)
	{
		downloadgitaddon();
	}
}
int maingit()
{
	SetConsoleTitle("Switcher Updater From Github");
	killgit();
	cleangit();
	cleancachegit();
	system("CLS");
	int op;
	string NewAASVersion, NewXYLVersion, CurrentAASVersion, CurrentXYLVersion, HeadOfAAS, CurrentHeadOfAAS, addonName;
	int na=0,nx=0,upn=0,nado=0,ado=0;
	ifstream in;
	if (lcid == 2052)
	{
		cout << "Switcher ���³��򣨴� Github ���أ�" << endl;
		cout << "׼�������£���ȷ����������" << endl;
		cout << "Updater 2.4 Github, Switcher LTS" << endl;
		cout << "1.���� 2.ȡ�� 3.ת�������ؽ��� 4.����" << endl;
	}
	else
	{
		cout << "Switcher Online Updater (Download From Github)" << endl;
		cout << "Ready to check for update, please stay online." << endl;
		cout << "Updater 2.4 Github, Switcher LTS" << endl;
		cout << "1.continue 2.cancel 3.jump to download page 4.declaration" << endl;
	}
start:	op=_getch()-48;
	while(op!=1&&op!=2&&op!=3&&op!=4)
	{
		if (lcid == 2052)
			cout << endl << "��Ч���룬�����ԣ�";
		else
			cout << endl << "Invalid input, please try again:";
		op=_getch()-48;
	}
	if (op == 2)
	{
		cleangit();
		exit(0);
	}
	if (op == 4)
	{
		if (lcid == 2052)
			::MessageBox(NULL, "�������Ķ������������\n1.����Ʒ�� Switcher LTS һͬ��װ�����е������ۣ��ǲ�����ġ�\n2.�������ߵ��������ݾ�Ϊ���°� Updater ���ƣ���������ݴ�λ������������ Updater�����⣬�벻Ҫ���Ծɰ�� Updater���������Ը���\n3.����Ʒ�����ٶ��������кܴ�Ĺ�ϵ��һ�㵥һ�������ʱ�䲻����4-5���ӣ��������ʱ��������뿼�Ǹ������硣", "����", MB_ICONINFORMATION);
		else
			::MessageBox(NULL, "Please read this carefully:\n1.This online update tool is installed together with Switcher LTS. Do not use a single version.\n2.All online data is written for the newest version of Updater. Please keep this tool up-to-date. Moreover, do not downgrade Updater.\n3.If you cannot finish download in 3-5 minutes, please consider changing another network.", "Declaration", MB_ICONINFORMATION);
		goto start;
	}
	if (op == 1) {
		if (lcid == 2052)
			cout << endl << "���ڼ�����..." << endl;
		else
			cout << endl << "Checking update..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/upver.sver"), TEXT(".\\Resources\\upver.sver"), 0, NULL);
		if ((_access(".\\Resources\\upver.sver", 0)) == -1)
		{
			if (lcid == 2052)
				cout << "������ʧ��" << endl;
			else
				cout << "Failed to check for update." << endl;
			system("PAUSE");
			cleangit();
			exit(0);
		}
		in.open(".\\Resources\\upver.sver");
		in >> HeadOfAAS >> NewAASVersion >> NewXYLVersion >> adon;
		getline(in, addonName);
		in.get();
		in.close();
		in.open(".\\Resources\\av.sver");
		in >> CurrentHeadOfAAS>>CurrentAASVersion;
		in.close();
		in.open(".\\Resources\\xv.sver");
		in >> CurrentXYLVersion;
		in.close();
		in.open(".\\Resources\\addon.sver");
		in >> ado;
		in.close();
		system("CLS");
		for (int i = 0; i <= 4; i = i ++)
		{
			if (NewAASVersion[i] > CurrentAASVersion[i]) { na = 1; break; }
			else
			{
				if (NewAASVersion[i] < CurrentAASVersion[i])
				{
					na = -1; break;
				}
			}
		}
		for (int i = 0; i <= 4; i = i + 2)
		{
			if (NewXYLVersion[i] > CurrentXYLVersion[i]) { nx = 1; break; }
			else
			{
				if (NewXYLVersion[i] < CurrentXYLVersion[i])
				{
					nx = -1; break;
				}
			}
		}
		if (adon > ado) nado = 1;
		if (adon < ado) nado = -1;
		if (CurrentXYLVersion.size() != 5)
			nx = -1;
		if (CurrentHeadOfAAS[0] == 'A') na = -3;
		if ((_access(".\\Resources\\av.sver", 0)) == -1) na = -2;
		if ((_access(".\\Resources\\xv.sver", 0)) == -1) nx = -2;
		if ((_access(".\\Resources\\addon.sver", 0)) == -1) nado = -2;
		if (na == 1 || nx == 1 || nado == 1) upn = 1;
		if (na == -2 || nx == -2 || nado == -2) upn = -2;
		if (na == -1 || nx == -1 || nado == -1) upn = -2;
		if (lcid == 2052)
		{
			cout << "Updater 2.4, Switcher LTS\n�������" << endl << "AAS ���°汾�� " << HeadOfAAS << ' ' << NewAASVersion << endl << "���У� " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "Ф���ֵĹ��� ���°汾��" << NewXYLVersion << endl << "����:" << CurrentXYLVersion << endl << endl;
			cout << "���Ӹ��� ���£�No." << adon << endl << "���У�No." << ado << endl;
			cout << "���Ӹ��� No." << adon << " ���ݣ�" << addonName << endl << endl;
			cout << "AAS ";
			if (na == 0) cout << "�޸���" << endl;
			if (na == 1) cout << "�и���" << endl;
			if (na == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (na == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			if (na == -3) cout << "�� Updater 2.1, Switcher LTS ( Final Release ) ��ʼ��Alpha �� AAS �޷��� Updater ��ȡ���£��볢�ԣ�\n�������µ� AAS��ֱ����������ѡ��3�������أ�" << endl << endl;
			cout << "Ф���ֵĹ��� ";
			if (nx == 0) cout << "�޸���" << endl;
			if (nx == 1) cout << "�и���" << endl;
			if (nx == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (nx == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			cout << "���Ӹ��� ";
			if (nado == 0) cout << "�޸���" << endl;
			if (nado == 1) cout << "�и���" << endl;
			if (nado == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (nado == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			cout << endl;
			if (upn == 1) cout << "׼�����£���ȷ����������" << endl << "1.���� 2.ȡ��";
			if (upn == 0) cout << "������£��Ƿ���Ҫ������" << endl << "1.��Ȼ���� 2.ȡ��";
			if (upn == -2) cout << "������" << endl << "1.���� 2.ȡ��";
			cout << endl;
		}
		else
		{
			cout << "Updater 2.4, Switcher LTS\nResult:" << endl << "Newest version of AAS: " << HeadOfAAS << ' ' << NewAASVersion << endl << "Current version of AAS: " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "Newest version of The Story of XYL: " << NewXYLVersion << endl << "Current version of The Story of XYL: " << CurrentXYLVersion << endl << endl;
			cout << "Newest version of Add-on Update: No. " << adon << endl << "Current version of Add-on Update: No. " << ado << endl;
			cout << "Add-on Update No." << adon << " What is it? " << addonName << endl << endl;
			cout << "AAS ";
			if (na == 0) cout << "Up-to-dated." << endl;
			if (na == 1) cout << "Ready to update." << endl;
			if (na == -1) cout << "[ERR:COMP]" << endl;
			if (na == -2) cout << "[ERR:FILE]" << endl;
			if (na == -3) cout << "Since Updater 2.1, Switcher LTS (Final Release), AAS Alpha cannot get update from Updater. Please try:\nDownload AAS Beta (Press 3 when main menu is displayed)." << endl << endl;
			cout << "The Story of XYL ";
			if (nx == 0) cout << "Up-to-dated." << endl;
			if (nx == 1) cout << "Ready to update." << endl;
			if (nx == -1) cout << "[ERR:COMP]" << endl;
			if (nx == -2) cout << "[ERR:FILE]" << endl;
			cout << "Add-on Update ";
			if (nado == 0) cout << "Up-to-dated." << endl;
			if (nado == 1) cout << "Ready to update." << endl;
			if (nado == -1) cout << "[ERR:COMP]" << endl;
			if (nado == -2) cout << "[ERR:FILE]" << endl;
			cout << endl;
			if (upn == 1) cout << "Ready to update, please stay online." << endl << "1.continue 2.cancel";
			if (upn == 0) cout << "You're up-to-dated." << endl << "1.download anyway 2.cancel";
			if (upn == -2) cout << "Error" << endl << "1.quick fix 2.cancel";
			cout << endl;
		}
		op = _getch() - 48;
		while (op != 1 && op != 2)
		{
			if (lcid == 2052)
				cout << endl << "��Ч���룬�����ԣ�";
			else
				cout << endl << "Invalid input, please try again:";
			op = _getch() - 48;
		}
		if (op == 2)
		{
			cleangit();
			exit(0);
		}
		system("CLS");
		if (lcid == 2052)
			cout << "������..." << endl;
		else
			cout << "Downloading..." << endl;
		if (na == 1 || na == -1 || na == -2)
		{
			downloadgitaas();
		}
		if (nx == 1 || nx == -1 || nx == -2)
		{
			downloadgitxyl();
		}
		if (nado == 1 || nado == -1 || nado == -2)
		{
			downloadgitaddon();
		}
		if (upn == 0)
			nonegit();
		applygit();
	}
	if (op == 3) nonegit();
	if (lcid == 2052)
		cout << "�����������" << endl;
	else
		cout << "Done." << endl;
	system("PAUSE");
	system("CLS");
	cleangit();
	return 0;
}
void cleancache()
{
	if (lcid == 2052)
		cout << "�������� Url ���棬���Ժ�..." << endl;
	else
		cout << "Cleaning Url caches, please wait..." << endl;
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/AAS.exe");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/av.sver");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/cfa.conform");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/xyl.exe");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/xv.sver");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/cfx.conform");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/Setup.exe");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/cfs.conform");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/addon.exe");
	DeleteUrlCacheEntry("https://gitee.com/cswitcher/AAS/raw/Switcher/cfado.conform");
}
void downloadaas()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			if (lcid == 2052)
				cout << "׼������" << endl;
			else
				cout << "Ready to retry." << endl;
		}
		if (lcid == 2052)
			cout << "���� AAS..." << endl;
		else
			cout << "Downloading AAS..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/AAS.exe"), TEXT(".\\Resources\\AAS.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/av.sver"), TEXT(".\\Resources\\av.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfa.conform"), TEXT(".\\Resources\\cfa.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfa.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�AAS ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download AAS after 3 tries, skipped." << endl;
	}
}
void downloadxyl()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			if (lcid == 2052)
				cout << "׼������" << endl;
			else
				cout << "Ready to retry." << endl;
		}
		if (lcid == 2052)
			cout << "����Ф���ֵĹ���..." << endl;
		else
			cout << "Downloading The Story of XYL..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/xyl.exe"), TEXT(".\\Resources\\xyl.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/xv.sver"), TEXT(".\\Resources\\xv.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfx.conform"), TEXT(".\\Resources\\cfx.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfx.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�Ф���ֵĹ��� ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download The Story of XYL after 3 tries, skipped." << endl;
	}
}
void downloadsetup()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			{
				if (lcid == 2052)
					cout << "׼������" << endl;
				else
					cout << "Ready to retry." << endl;
			}
		}
		if (lcid == 2052)
			cout << "���� Switcher Setup..." << endl;
		else
			cout << "Downloading Switcher Setup..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/Setup.exe"), TEXT(".\\Resources\\Setup.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfs.conform"), TEXT(".\\Resources\\cfs.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfs.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ�Switcher Setup ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download Switcher Setup after 3 tries, skipped." << endl;
	}
}
void downloadaddon()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
		{
			{
				if (lcid == 2052)
					cout << "׼������" << endl;
				else
					cout << "Ready to retry." << endl;
			}
		}
		if (lcid == 2052)
			cout << "���ظ��Ӹ���..." << endl;
		else
			cout << "Downloading Add-on Update..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/addon.exe"), TEXT(".\\Resources\\addon.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfado.conform"), TEXT(".\\Resources\\cfado.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfado.conform", 0)) == -1)
		{
			fail = 1;
			if (lcid == 2052)
				cout << "ʧ�ܣ��ȴ� 3 ��" << endl;
			else
				cout << "Failed, retry in 3 seconds." << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			if (lcid == 2052)
				cout << "�ɹ�" << endl;
			else cout << "Success." << endl;
			break;
		}
	}
	if (fail == 1)
	{
		if (lcid == 2052)
			cout << "�����γ��Ժ󣬸��Ӹ��� ����ʧ�ܣ��Ѿ�����" << endl;
		else
			cout << "Failed to download Add-on Update after 3 tries, skipped." << endl;
	}
}
void kill()
{
	system("taskkill /im Activator.exe /f");
	system("taskkill /im AAS.exe /f");
	system("taskkill /im xyl.exe /f");
	system("taskkill /im Switcher.exe /f");
}
void clean()
{
	if (lcid == 2052)
		cout << "����������ʱ�ļ������Ժ�" << endl;
	else
		cout << "Cleaning temp files, please wait..." << endl;
	if ((_access(".\\Resources\\upver.sver", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\upver.sver"));
	}
	if ((_access(".\\Resources\\cfa.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfa.conform"));
	}
	if ((_access(".\\Resources\\cfx.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfx.conform"));
	}
	if ((_access(".\\Resources\\cfs.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfs.conform"));
	}
	if ((_access(".\\Resources\\cfado.conform", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\cfado.conform"));
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\addon.exe"));
	}
	if ((_access(".\\Resources\\Setup.exe", 0)) != -1)
	{
		DeleteFile(TEXT(".\\Resources\\Setup.exe"));
	}
}
void apply()
{
	if ((_access(".\\Resources\\Setup.exe", 0)) != -1)
	{
		if (lcid == 2052)
			cout << "�������̲�Ӧ�� Switcher ����" << endl;
		else
			cout << "Killing processes to apply Switcher updates..." << endl;
		kill();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\Setup.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		if (lcid == 2052)
			cout << "�������̲�Ӧ�ø��Ӹ���" << endl;
		else
			cout << "Killing processes to apply Add-on updates..." << endl;
		kill();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\addon.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
}
void none()
{
	system("CLS");
	if (lcid == 2052)
		cout << "��������Ҫ���ص������" << endl << "���������1-4����0 �˳���";
	else
		cout << "Input what you want to download:" << endl << "Numbers (1-4), Exit: 0" << endl;
	int n, op;
	n = _getch() - 48;
	while (n < 0 || n>4)
	{
		if (lcid == 2052)
			cout << endl << "��Ч���룬�����ԣ�";
		else
			cout << "Invalid input, please try again: ";
		n = _getch() - 48;
	}
	if (n == 0) exit(0);
	if (lcid == 2052)
		cout << endl << "����������ţ�" << endl << "1.AAS 2.Ф���ֵĹ��� 3.Switcher Setup 4.���Ӹ��� No." << adon << endl;
	else
		cout << endl << "Which is program you want to download?" << endl << "1.AAS 2.The Story of XYL 3.Switcher Setup 4.Add-on Update No. " << adon << endl;
	int a[5];
	memset(a, 1, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		cin >> op;
		a[op] = 1;
	}
	system("CLS");
	if (lcid == 2052)
		cout << "������..." << endl;
	else
		cout << "downloading..." << endl;
	if (a[1] == 1)
	{
		downloadaas();
	}
	if (a[2] == 1)
	{
		downloadxyl();
	}
	if (a[3] == 1)
	{
		downloadsetup();
	}
	if (a[4] == 1)
	{
		downloadaddon();
	}
}
int maingitee()
{
	SetConsoleTitle("Switcher Updater From Gitee");
	kill();
	clean();
	cleancache();
	system("CLS");
	int op;
	string NewAASVersion, NewXYLVersion, CurrentAASVersion, CurrentXYLVersion, HeadOfAAS, CurrentHeadOfAAS, addonName;
	int na = 0, nx = 0, upn = 0, nado = 0, ado = 0;
	ifstream in;
	if (lcid == 2052)
	{
		cout << "Switcher ���³��򣨴� Gitee ���أ�" << endl;
		cout << "׼�������£���ȷ����������" << endl;
		cout << "Updater 2.4 Gitee, Switcher LTS" << endl;
		cout << "1.���� 2.ȡ�� 3.ת�������ؽ��� 4.����" << endl;
	}
	else
	{
		cout << "Switcher Online Updater (Download From Gitee)" << endl;
		cout << "Ready to check for update, please stay online." << endl;
		cout << "Updater 2.4 Gitee, Switcher LTS" << endl;
		cout << "1.continue 2.cancel 3.jump to download page 4.declaration" << endl;
	}
start:	op = _getch() - 48;
	while (op != 1 && op != 2 && op != 3 && op != 4)
	{
		if (lcid == 2052)
			cout << endl << "��Ч���룬�����ԣ�";
		else
			cout << endl << "Invalid input, please try again:";
		op = _getch() - 48;
	}
	if (op == 2)
	{
		clean();
		exit(0);
	}
	if (op == 4)
	{
		if (lcid == 2052)
			::MessageBox(NULL, "�������Ķ������������\n1.����Ʒ�� Switcher LTS һͬ��װ�����е������ۣ��ǲ�����ġ�\n2.�������ߵ��������ݾ�Ϊ���°� Updater ���ƣ���������ݴ�λ������������ Updater�����⣬�벻Ҫ���Ծɰ�� Updater���������Ը���\n3.����Ʒ�����ٶ��������кܴ�Ĺ�ϵ��һ�㵥һ�������ʱ�䲻����4-5���ӣ��������ʱ��������뿼�Ǹ������硣", "����", MB_ICONINFORMATION);
		else
			::MessageBox(NULL, "Please read this carefully:\n1.This online update tool is installed together with Switcher LTS. Do not use a single version.\n2.All online data is written for the newest version of Updater. Please keep this tool up-to-date. Moreover, do not downgrade Updater.\n3.If you cannot finish download in 3-5 minutes, please consider changing another network.", "Declaration", MB_ICONINFORMATION);
		goto start;
	}
	if (op == 1) {
		if (lcid == 2052)
			cout << endl << "���ڼ�����..." << endl;
		else
			cout << endl << "Checking update..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/upver.sver"), TEXT(".\\Resources\\upver.sver"), 0, NULL);
		if ((_access(".\\Resources\\upver.sver", 0)) == -1)
		{
			if (lcid == 2052)
				cout << "������ʧ��" << endl;
			else
				cout << "Failed to check for update." << endl;
			system("PAUSE");
			clean();
			exit(0);
		}
		in.open(".\\Resources\\upver.sver");
		in >> HeadOfAAS >> NewAASVersion >> NewXYLVersion >> adon;
		getline(in, addonName);
		in.get();
		in.close();
		in.open(".\\Resources\\av.sver");
		in >> CurrentHeadOfAAS >> CurrentAASVersion;
		in.close();
		in.open(".\\Resources\\xv.sver");
		in >> CurrentXYLVersion;
		in.close();
		in.open(".\\Resources\\addon.sver");
		in >> ado;
		in.close();
		system("CLS");
		for (int i = 0; i <= 4; i = i++)
		{
			if (NewAASVersion[i] > CurrentAASVersion[i]) { na = 1; break; }
			else
			{
				if (NewAASVersion[i] < CurrentAASVersion[i])
				{
					na = -1; break;
				}
			}
		}
		for (int i = 0; i <= 4; i = i + 2)
		{
			if (NewXYLVersion[i] > CurrentXYLVersion[i]) { nx = 1; break; }
			else
			{
				if (NewXYLVersion[i] < CurrentXYLVersion[i])
				{
					nx = -1; break;
				}
			}
		}
		if (adon > ado) nado = 1;
		if (adon < ado) nado = -1;
		if (CurrentXYLVersion.size() != 5)
			nx = -1;
		if (CurrentHeadOfAAS[0] == 'A') na = -3;
		if ((_access(".\\Resources\\av.sver", 0)) == -1) na = -2;
		if ((_access(".\\Resources\\xv.sver", 0)) == -1) nx = -2;
		if ((_access(".\\Resources\\addon.sver", 0)) == -1) nado = -2;
		if (na == 1 || nx == 1 || nado == 1) upn = 1;
		if (na == -2 || nx == -2 || nado == -2) upn = -2;
		if (na == -1 || nx == -1 || nado == -1) upn = -2;
		if (lcid == 2052)
		{
			cout << "Updater 2.4, Switcher LTS\n�������" << endl << "AAS ���°汾�� " << HeadOfAAS << ' ' << NewAASVersion << endl << "���У� " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "Ф���ֵĹ��� ���°汾��" << NewXYLVersion << endl << "����:" << CurrentXYLVersion << endl << endl;
			cout << "���Ӹ��� ���£�No." << adon << endl << "���У�No." << ado << endl;
			cout << "���Ӹ��� No." << adon << " ���ݣ�" << addonName << endl << endl;
			cout << "AAS ";
			if (na == 0) cout << "�޸���" << endl;
			if (na == 1) cout << "�и���" << endl;
			if (na == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (na == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			if (na == -3) cout << "�� Updater 2.1, Switcher LTS ( Final Release ) ��ʼ��Alpha �� AAS �޷��� Updater ��ȡ���£��볢�ԣ�\n�������µ� AAS��ֱ����������ѡ��3�������أ�" << endl << endl;
			cout << "Ф���ֵĹ��� ";
			if (nx == 0) cout << "�޸���" << endl;
			if (nx == 1) cout << "�и���" << endl;
			if (nx == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (nx == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			cout << "���Ӹ��� ";
			if (nado == 0) cout << "�޸���" << endl;
			if (nado == 1) cout << "�и���" << endl;
			if (nado == -1) cout << "�Աȳ�����ǰ�İ汾�����������°� [ERR:COMP]" << endl;
			if (nado == -2) cout << "�ļ�����������ļ������� [ERR:FILE]" << endl;
			cout << endl;
			if (upn == 1) cout << "׼�����£���ȷ����������" << endl << "1.���� 2.ȡ��";
			if (upn == 0) cout << "������£��Ƿ���Ҫ������" << endl << "1.��Ȼ���� 2.ȡ��";
			if (upn == -2) cout << "������" << endl << "1.���� 2.ȡ��";
			cout << endl;
		}
		else
		{
			cout << "Updater 2.4, Switcher LTS\nResult:" << endl << "Newest version of AAS: " << HeadOfAAS << ' ' << NewAASVersion << endl << "Current version of AAS: " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "Newest version of The Story of XYL: " << NewXYLVersion << endl << "Current version of The Story of XYL: " << CurrentXYLVersion << endl << endl;
			cout << "Newest version of Add-on Update: No. " << adon << endl << "Current version of Add-on Update: No. " << ado << endl;
			cout << "Add-on Update No." << adon << " What is it? " << addonName << endl << endl;
			cout << "AAS ";
			if (na == 0) cout << "Up-to-dated." << endl;
			if (na == 1) cout << "Ready to update." << endl;
			if (na == -1) cout << "[ERR:COMP]" << endl;
			if (na == -2) cout << "[ERR:FILE]" << endl;
			if (na == -3) cout << "Since Updater 2.1, Switcher LTS (Final Release), AAS Alpha cannot get update from Updater. Please try:\nDownload AAS Beta (Press 3 when main menu is displayed)." << endl << endl;
			cout << "The Story of XYL ";
			if (nx == 0) cout << "Up-to-dated." << endl;
			if (nx == 1) cout << "Ready to update." << endl;
			if (nx == -1) cout << "[ERR:COMP]" << endl;
			if (nx == -2) cout << "[ERR:FILE]" << endl;
			cout << "Add-on Update ";
			if (nado == 0) cout << "Up-to-dated." << endl;
			if (nado == 1) cout << "Ready to update." << endl;
			if (nado == -1) cout << "[ERR:COMP]" << endl;
			if (nado == -2) cout << "[ERR:FILE]" << endl;
			cout << endl;
			if (upn == 1) cout << "Ready to update, please stay online." << endl << "1.continue 2.cancel";
			if (upn == 0) cout << "You're up-to-dated." << endl << "1.download anyway 2.cancel";
			if (upn == -2) cout << "Error" << endl << "1.quick fix 2.cancel";
			cout << endl;
		}
		op = _getch() - 48;
		while (op != 1 && op != 2)
		{
			if (lcid == 2052)
				cout << endl << "��Ч���룬�����ԣ�";
			else
				cout << endl << "Invalid input, please try again:";
			op = _getch() - 48;
		}
		if (op == 2)
		{
			clean();
			exit(0);
		}
		system("CLS");
		if (lcid == 2052)
			cout << "������..." << endl;
		else
			cout << "Downloading..." << endl;
		if (na == 1 || na == -1 || na == -2)
		{
			downloadaas();
		}
		if (nx == 1 || nx == -1 || nx == -2)
		{
			downloadxyl();
		}
		if (nado == 1 || nado == -1 || nado == -2)
		{
			downloadaddon();
		}
		if (upn == 0)
			none();
		apply();
	}
	if (op == 3) none();
	if (lcid == 2052)
		cout << "�����������" << endl;
	else
		cout << "Done." << endl;
	system("PAUSE");
	system("CLS");
	clean();
	return 0;
}
int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		if (lcid == 2052)
			MessageBox(NULL, "������������ȷ\n����������\n*���������ķ����������ڽ������\nS: �����������ã��� Github �������°�װ����\nE: �����������ò��� Gitee �������°�װ����\nH: �����������ã��� Github �����£�\nF�������������ã��� Gitee �����¡�\n*��ʹ��ǰ���Ƚ� Updater ������ Switcher ��Ŀ¼��", "����", MB_ICONERROR);
		else
			MessageBox(NULL, "Invalid way of start.", "Error", MB_ICONERROR);
		return 0;
	}
	char Choice = *argv[1];
	ifstream in;
	string Server;
	if (argc >= 3)
	{
		if (lcid == 2052)
			cout << "������ " << argc - 1 << " ������������ " << Choice << " ����Ĳ���" << endl;
		else
			cout << "Inputed " << argc - 1 << " argvs, ignored argvs except " << Choice << endl;
	}
	switch (Choice)
	{
	case 'N':
		if (SwitcherActivateJudgeFunc())
		{
			in.open(".\\config\\server");
			in >> Server;
			if (Server == "Github")
			{
				maingit();
			}
			else
				maingitee();
			break;
		}
		else
		{
			if (lcid == 2052)
				MessageBox(NULL, "δ����\n���ȼ���", "����", MB_ICONERROR);
			else
				MessageBox(NULL, "Not Activated.\nPlease activate first.", "Error", MB_ICONERROR);
			return 0;
		}

	case 'S':
		if (lcid == 2052)
			SetConsoleTitle("�ָ�ģʽ���� Github ���ذ�װ��");
		else
			SetConsoleTitle("Recovery Mode (Github)");
		cleangit();
		cleancachegit();
		downloadgitsetup();
		applygit();
		break;
	case 'E':
		if (lcid == 2052)
			SetConsoleTitle("�ָ�ģʽ���� Gitee ���ذ�װ��");
		else
			SetConsoleTitle("Recovery Mode (Gitee)");
		clean();
		cleancache();
		downloadsetup();
		apply();
		break;
	case 'H':
		if (SwitcherActivateJudgeFunc())
		{
			maingit();
			break;
		}
		else
		{
			if (lcid == 2052)
				MessageBox(NULL, "δ����\n���ȼ���", "����", MB_ICONERROR);
			else
				MessageBox(NULL, "Not Activated.\nPlease activate first.", "Error", MB_ICONERROR);
			return 0;
		}
	case 'F':
		if (SwitcherActivateJudgeFunc())
		{
			maingitee();
			break;
		}
		else
		{
			if (lcid == 2052)
				MessageBox(NULL, "δ����\n���ȼ���", "����", MB_ICONERROR);
			else
				MessageBox(NULL, "Not Activated.\nPlease activate first.", "Error", MB_ICONERROR);
			return 0;
		}
	case 'T':
		clean();
		cleancachegit();
		if (lcid == 2052)
			SetConsoleTitle("Updater - ���ð�");
		else
			SetConsoleTitle("Updater - Trial Mode");
		downloadgitaas();
		downloadgitxyl();
		DeleteFile(".\\config\\DEMO");
		break;
	default:
		if (lcid == 2052)
			MessageBox(NULL, "������������ȷ\n����������\n*���������ķ����������ڽ������\nS: �����������ã��� Github �������°�װ����\nE: �����������ò��� Gitee �������°�װ����\nH: �����������ã��� Github �����£�\nF�������������ã��� Gitee �����¡�\n*��ʹ��ǰ���Ƚ� Updater ������ Switcher ��Ŀ¼��", "����", MB_ICONERROR);
		else
			MessageBox(NULL, "Invalid way of start.", "Error", MB_ICONERROR);
		break;
	}
}
