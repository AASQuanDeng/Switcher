#include "stdafx.h"
#include "upd.hpp"
#pragma comment (lib,"User32.lib")
#pragma comment( lib,"Urlmon.lib")
#pragma comment( lib, "wininet.lib") 
using namespace std;
int adon=0;
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
	cout << "正在清理 Url 缓存，请稍后..." << endl;
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
			cout << "准备重试" << endl;
		cout << "下载 AAS..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/AAS.exe"), TEXT(".\\Resources\\AAS.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/av.sver"), TEXT(".\\Resources\\av.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfa.conform"), TEXT(".\\Resources\\cfa.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfa.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，AAS 下载失败，已经跳过" << endl;
}
void downloadgitxyl()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载肖亚林的故事..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xyl.exe"), TEXT(".\\Resources\\xyl.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/xv.sver"), TEXT(".\\Resources\\xv.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfx.conform"), TEXT(".\\Resources\\cfx.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfx.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，肖亚林的故事下载失败，已经跳过" << endl;
}
void downloadgitsetup()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载 Switcher & Switcher Core Setup..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/Setup.exe"), TEXT(".\\Resources\\Setup.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfs.conform"), TEXT(".\\Resources\\cfs.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfs.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后， Switcher & Switcher Core Setup 下载失败，已经跳过" << endl;
}
void downloadgitaddon()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载附加更新..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/addon.exe"), TEXT(".\\Resources\\addon.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/cfado.conform"), TEXT(".\\Resources\\cfado.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfado.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，附加更新下载失败，已经跳过" << endl;
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
	cout << "正在清理临时文件，请稍后" << endl;
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
		cout << "结束进程并应用 Switcher & Switcher Core 更新" << endl;
		killgit();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\Setup.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		cout << "结束进程并应用附加更新" << endl;
		killgit();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\addon.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
}
void nonegit()
{
	system("CLS");
	cout<<"输入你需要下载的组件："<<endl<<"组件个数（1-4），0 退出：";
	int n,op;
	n = _getch()-48;
	while(n<0||n>4)
	{
		cout<<endl<<"无效输入，请重试：";
		cin>>n;
	}
	if (n == 0) exit(0);
	cout<<endl<<"输入组件代号："<<endl<<"1.AAS 2.肖亚林的故事 3.Switcher & Switcher Core Setup 4.附加更新 No."<<adon<<endl;
	int a[5];
	memset(a,1,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		a[op]=1;
	}
	system("CLS");
	cout<<"下载中..."<<endl;
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
	cout << "Switcher 更新程序（从 Github 下载）" << endl;
	cout << "准备检查更新，请确保网络连接" << endl;
	cout << "Updater 2.3 Github, Switcher LTS" << endl;
	cout << "1.继续 2.取消 3.转跳到下载界面 4.声明" << endl;
start:	op=_getch()-48;
	while(op!=1&&op!=2&&op!=3&&op!=4)
	{
		cout<<endl<<"无效输入，请重试：",
		op=_getch()-48;
	}
	if (op == 2)
	{
		cleangit();
		exit(0);
	}
	if (op == 4)
	{
		::MessageBox(NULL, "请认真阅读下面的声明：\n1.本产品与 Switcher LTS 一同安装，如有单独出售，那不是真的。\n2.所有在线的升级数据均为最新版 Updater 定制，如出现数据错位等现象，请升级 Updater，另外，请不要尝试旧版的 Updater，否则后果自负。\n3.本产品下载速度与网速有很大的关系，一般单一组件下载时间不超过4-5分钟，如果下载时间过长，请考虑更换网络。", "声明", MB_ICONINFORMATION);
		goto start;
	}
	if (op == 1) {
		cout << endl << "正在检查更新..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/upver.sver"), TEXT(".\\Resources\\upver.sver"), 0, NULL);
		if ((_access(".\\Resources\\upver.sver", 0)) == -1)
		{
			cout << "检查更新失败" << endl;
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
		cout << "Updater 2.3, Switcher LTS\n检查结果：" << endl << "AAS 最新版本： " << HeadOfAAS << ' ' << NewAASVersion << endl << "现有： " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "肖亚林的故事 最新版本：" << NewXYLVersion << endl << "现有:" << CurrentXYLVersion << endl << endl;
		cout << "附加更新 最新：No." << adon << endl << "现有：No." << ado << endl;
		cout << "附加更新 No." << adon << " 内容：" << addonName << endl << endl;
		cout << "AAS ";
		if (na == 0) cout << "无更新" << endl;
		if (na == 1) cout << "有更新" << endl;
		if (na == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (na == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		if (na == -3) cout << "自 Updater 2.1, Switcher LTS ( Final Release ) 开始，Alpha 版 AAS 无法从 Updater 获取更新，请尝试：\n下载最新的 AAS（直接在主界面选择3进入下载）" << endl << endl;
		cout << "肖亚林的故事 ";
		if (nx == 0) cout << "无更新" << endl;
		if (nx == 1) cout << "有更新" << endl;
		if (nx == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (nx == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		cout << "附加更新 ";
		if (nado == 0) cout << "无更新" << endl;
		if (nado == 1) cout << "有更新" << endl;
		if (nado == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (nado == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		cout << endl;
		if (upn == 1) cout << "准备更新，请确保网络连接" << endl << "1.更新 2.取消";
		if (upn == 0) cout << "无需更新，是否仍要继续？" << endl << "1.仍然更新 2.取消";
		if (upn == -2) cout << "检查出错" << endl << "1.下载 2.取消";
		cout << endl;
		op = _getch() - 48;
		while (op != 1 && op != 2)
		{
			cout << endl << "无效输入，请重试：",
				op = _getch() - 48;
		}
		if (op == 2)
		{
			cleangit();
			exit(0);
		}
		system("CLS");
		cout << "下载中..." << endl;
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
	cout<<"程序运行完毕"<<endl;
	system("PAUSE");
	system("CLS");
	cleangit();
	return 0;
}
void cleancache()
{
	cout << "正在清理 Url 缓存，请稍后..." << endl;
	DeleteUrlCacheEntry("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/AAS.exe");
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
	cout << "由于 AAS 可执行文件大于 1 MB，该文件会从 Github 下载" << endl;
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载 AAS..." << endl;
		URLDownloadToFile(NULL, TEXT("https://raw.githubusercontent.com/AASQuanDeng/AAS/Switcher/AAS.exe"), TEXT(".\\Resources\\AAS.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/av.sver"), TEXT(".\\Resources\\av.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfa.conform"), TEXT(".\\Resources\\cfa.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfa.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，AAS 下载失败，已经跳过" << endl;
}
void downloadxyl()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载肖亚林的故事..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/xyl.exe"), TEXT(".\\Resources\\xyl.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/xv.sver"), TEXT(".\\Resources\\xv.sver"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfx.conform"), TEXT(".\\Resources\\cfx.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfx.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，肖亚林的故事下载失败，已经跳过" << endl;
}
void downloadsetup()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载 Switcher & Switcher Core Setup..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/Setup.exe"), TEXT(".\\Resources\\Setup.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfs.conform"), TEXT(".\\Resources\\cfs.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfs.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后， Switcher & Switcher Core Setup 下载失败，已经跳过" << endl;
}
void downloadaddon()
{
	int retry = 1, fail = 0;
	while (retry <= 3)
	{
		if (fail == 1)
			cout << "准备重试" << endl;
		cout << "下载附加更新..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/addon.exe"), TEXT(".\\Resources\\addon.exe"), 0, NULL);
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/cfado.conform"), TEXT(".\\Resources\\cfado.conform"), 0, NULL);
		if ((_access(".\\Resources\\cfado.conform", 0)) == -1)
		{
			fail = 1;
			cout << "失败，等待 3 秒" << endl;
			retry++;
			Sleep(3000);
		}
		else
		{
			fail = 0;
			cout << "成功" << endl;
			break;
		}
	}
	if (fail == 1)
		cout << "在三次尝试后，附加更新下载失败，已经跳过" << endl;
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
	cout << "正在清理临时文件，请稍后" << endl;
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
		cout << "结束进程并应用 Switcher & Switcher Core 更新" << endl;
		kill();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\Setup.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
	if ((_access(".\\Resources\\addon.exe", 0)) != -1)
	{
		cout << "结束进程并应用附加更新" << endl;
		kill();
		ShellExecute(NULL, TEXT("runas"), TEXT(".\\Resources\\addon.exe"), NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
}
void none()
{
	system("CLS");
	cout << "输入你需要下载的组件：" << endl << "组件个数（1-4），0 退出：";
	int n, op;
	n = _getch() - 48;
	while (n < 0 || n>4)
	{
		cout << endl << "无效输入，请重试：";
		cin >> n;
	}
	if (n == 0) exit(0);
	cout << endl << "输入组件代号：" << endl << "1.AAS 2.肖亚林的故事 3.Switcher & Switcher Core Setup 4.附加更新 No." << adon << endl;
	int a[5];
	memset(a, 1, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		cin >> op;
		a[op] = 1;
	}
	system("CLS");
	cout << "下载中..." << endl;
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
	string NewAASVersion, NewXYLVersion, CurrentAASVersion, CurrentXYLVersion, NewHeadOfAAS, CurrentHeadOfAAS, addonName;
	int na = 0, nx = 0, upn = 0, nado = 0, ado = 0;
	ifstream in;
	cout << "Switcher 更新程序（从 Gitee 下载）" << endl;
	cout << "准备检查更新，请确保网络连接" << endl;
	cout << "Updater 2.3 GITEE, Switcher LTS" << endl;
	cout << "1.继续 2.取消 3.转跳到下载界面 4.声明" << endl;
start:	op = _getch() - 48;
	while (op != 1 && op != 2 && op != 3 && op != 4)
	{
		cout << endl << "无效输入，请重试：",
			op = _getch() - 48;
	}
	if (op == 2)
	{
		clean();
		exit(0);
	}
	if (op == 4)
	{
		::MessageBox(NULL, "请认真阅读下面的声明：\n1.本产品与 Switcher LTS 一同安装，如有单独出售，那不是真的。\n2.所有在线的升级数据均为最新版 Updater 定制，如出现数据错位等现象，请升级 Updater，另外，请不要尝试旧版的 Updater，否则后果自负。\n3.本产品下载速度与网速有很大的关系，一般单一组件下载时间不超过4-5分钟，如果下载时间过长，请考虑更换网络。", "声明", MB_ICONINFORMATION);
		goto start;
	}
	if (op == 1) {
		cout << endl << "正在检查更新..." << endl;
		URLDownloadToFile(NULL, TEXT("https://gitee.com/cswitcher/AAS/raw/Switcher/upver.sver"), TEXT(".\\Resources\\upver.sver"), 0, NULL);
		if ((_access(".\\Resources\\upver.sver", 0)) == -1)
		{
			cout << "检查更新失败" << endl;
			system("PAUSE");
			clean();
			exit(0);
		}
		in.open(".\\Resources\\upver.sver");
		in >> NewHeadOfAAS >> NewAASVersion >> NewXYLVersion >> adon;
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
		cout << "Updater 2.3, Switcher LTS\n检查结果：" << endl << "AAS 最新版本： " << NewHeadOfAAS << ' ' << NewAASVersion << endl << "现有： " << CurrentHeadOfAAS << ' ' << CurrentAASVersion << endl << endl << "肖亚林的故事 最新版本：" << NewXYLVersion << endl << "现有:" << CurrentXYLVersion << endl << endl;
		cout << "附加更新 最新：No." << adon << endl << "现有：No." << ado << endl;
		cout << "附加更新 No." << adon << " 内容：" << addonName << endl << endl;
		cout << "AAS ";
		if (na == 0) cout << "无更新" << endl;
		if (na == 1) cout << "有更新" << endl;
		if (na == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (na == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		if (na == -3) cout << "自 Updater 2.1, Switcher LTS ( Final Release ) 开始，Alpha 版 AAS 无法从 Updater 获取更新，请尝试：\n下载最新的 AAS（直接在主界面选择3进入下载）" << endl;
		cout << "肖亚林的故事 ";
		if (nx == 0) cout << "无更新" << endl;
		if (nx == 1) cout << "有更新" << endl;
		if (nx == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (nx == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		cout << "附加更新 ";
		if (nado == 0) cout << "无更新" << endl;
		if (nado == 1) cout << "有更新" << endl;
		if (nado == -1) cout << "对比出错：当前的版本大于在线最新版 [ERR:COMP]" << endl;
		if (nado == -2) cout << "文件出错：请求的文件不存在 [ERR:FILE]" << endl;
		cout << endl;
		if (upn == 1) cout << "准备更新，请确保网络连接" << endl << "1.更新 2.取消";
		if (upn == 0) cout << "无需更新，是否仍要继续？" << endl << "1.仍然更新 2.取消";
		if (upn == -2) cout << "检查出错" << endl << "1.下载 2.取消";
		cout << endl;
		op = _getch() - 48;
		while (op != 1 && op != 2)
		{
			cout << endl << "无效输入，请重试：",
				op = _getch() - 48;
		}
		if (op == 2)
		{
			clean();
			exit(0);
		}
		system("CLS");
		cout << "下载中..." << endl;
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
	cout << "程序运行完毕" << endl;
	system("PAUSE");
	system("CLS");
	clean();
	return 0;
}
int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		MessageBox(NULL, "启动参数不正确\n启动参数：\n*单独开启的方法仅适用于紧急情况\nS: 忽略所有配置，从 Github 下载最新安装包；\nE: 忽略所有配置并从 Gitee 下载最新安装包；\nH: 忽略所有配置，从 Github 检查更新；\nF：忽略所有配置，从 Gitee 检查更新。\n*在使用前，先将 Updater 拷贝至 Switcher 根目录。", "错误", MB_ICONERROR);
		return 0;
	}
	char Choice = *argv[1];
	ifstream in;
	string Server;
	if (argc >= 3)
	{
		cout << "共输入 " << argc - 1 << " 个参数，忽略 " << Choice << " 以外的参数" << endl;
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
			MessageBox(NULL, "未激活\n请先激活", "错误", MB_ICONERROR);
			return 0;
		}

	case 'S':
		SetConsoleTitle("恢复模式：从 Github 下载安装包");
		cleangit();
		cleancachegit();
		downloadgitsetup();
		applygit();
		break;
	case 'E':
		SetConsoleTitle("恢复模式：从 Gitee下载安装包");
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
			MessageBox(NULL, "在未激活的情况下使用恢复模式检查更新依然是不可取的\n请先激活", "错误", MB_ICONERROR);
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
			MessageBox(NULL, "在未激活的情况下使用恢复模式检查更新依然是不可取的\n请先激活", "错误", MB_ICONERROR);
			return 0;
		}
	case 'T':
		clean();
		cleancachegit();
		SetConsoleTitle("Updater - 试用版");
		downloadgitaas();
		downloadgitxyl();
		DeleteFile(".\\config\\DEMO");
	default:
		MessageBox(NULL, "启动参数不正确\n启动参数：\n*单独开启的方法仅适用于紧急情况\nS: 忽略所有配置，从 Github 下载最新安装包；\nE: 忽略所有配置并从 Gitee 下载最新安装包；\nH: 忽略所有配置，从 Github 检查更新；\nF：忽略所有配置，从 Gitee 检查更新。\n*在使用前，先将 Updater 拷贝至 Switcher 根目录。", "错误", MB_ICONERROR);
		break;
	}
}
