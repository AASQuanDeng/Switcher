#include "MyForm.h"

using namespace Switcher;

[STAThread]

int main(cli::array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
}

//更新日志： 
//---------------------------------------
//Switcher 1.0：诞生
//使用 Dev C++ 编译，控制台应用程序
//---------------------------------------
//Switcher 1.1
//添加了对于新版 AAS 和 肖亚林的故事 支持
//新增了关于板块
//使用 Dev C++ 编译，控制台应用程序
//---------------------------------------
//Switcher 1.2
//关于板块首次出现动态版本指示
//使用 Dev C++ 编译，控制台应用程序
//---------------------------------------
//Switcher 1.3：迷失
//隐藏了一个彩蛋
//使用 Dev C++ 编译，控制台应用程序
//由于源代码丢失，此版本最终没有发布
//---------------------------------------
//Switcher GUI 0.5：追随现代的脚步
//Switcher 首次采用了图形界面
//删除了动态版本指示
//使用 Visual Studio 编译，Windows 窗体应用。
//---------------------------------------
//Switcher GUI 1.0
//Switcher GUI 0.5 的正式版
//界面微调
//使用 Visual Studio 编译，Windows 窗体应用。
//---------------------------------------
//Switcher GUI 1.0 Update / Switcher Core 3.1
//动态版本指示回归
//界面微调
//设立 Switcher Core 项目
//使用 Visual Studio 编译，Windows 窗体应用。
//---------------------------------------
//Switcher 2.0 / Switcher Core 4.0：重生
//重构代码
//界面大量修改
//加入更新和激活机制
//取消了对 Windows xp SP3, Windows Vista 的支持
//使用 Visual Studio 编译，Windows 窗体应用。
//June 7, 2019
//---------------------------------------
//Switcher 2.1 / Switcher Core 4.1
//取消了最大化按钮
//更改了Switcher的退出方式，使退出时不在有cmd窗口闪过；
//使用 Visual Studio 编译，Windows 窗体应用。
//由于该版本中的 Updater 存在变量错乱的严重问题，已经停止使用
//June 30, 2019
//---------------------------------------
//Switcher LTS Public Beta / Switcher Core LTS Public Beta：终结，还是起点？
//解决 Updater 中的严重问题
//推出附加更新
//使用 Visual Studio 编译，Windows 窗体应用。
//July 24, 2019
//---------------------------------------
//Switcher LTS / Switcher Core LTS
//使用新图标
//界面中央图片更改
//精简了 Updater 中的内容
//在 Activator 中添加错误指示。
//增加 Gitee 服务器并设为默认
//在应用启动时弹窗警告未激活
//使用 Visual Studio 编译，Windows 窗体应用。
//July 26，2019
//从此版本起，Updater 采用新的文件格式，之前的 Updater 版本全部失效
//---------------------------------------
//Switcher LTS Build 1907
//2019 年 7 月累计更新
//重新设计了图标
//修复 Updater 中的部分排版问题
//取消 Switcher Core 项目
//公开了非核心代码部分
//使用 Visual Studio 编译，Windows 窗体应用。
//July 31, 2019
//---------------------------------------
//Switcher LTS 2019 年夏季创意者更新
//重构代码，重新设计界面
//移除了主程序中残留的 Switcher Core 版本
//主程序由 Visual Studio 2010 升级为 2015 Update 3
//解决窗口最大化重新出现的问题
//增加安全性，允许以启动参数的方式从外部启动 Updater 以进入恢复模式
//Updater 整合，升级至 2.2，废除开始菜单内的“切换服务器”
//Updater 新增附加更新的名称
//Switcher 主程序现已支持更长的 AAS 前缀
//使用 Visual Studio 编译，Windows 窗体应用。
//October 4, 2019
//---------------------------------------
//Switcher LTS Build 1908 Beta 1 
//内部版本：190800.0.1
//全部组件使用 Visual Studio 2019 编译
//更改 肖亚林的故事 图标
//新增 错误指示
//界面微调 
//全新的关于界面
//Updater 添加激活判断
//Activator 现已支持不同服务器的激活
//添加当 AAS 和 肖亚林的故事 主程序不存在时，打开的提醒
//重新定义激活机制：
//未激活的情况下允许使用 AAS 和 肖亚林的故事
//允许试用一次 Updater 来下载初始版本的 AAS 和 肖亚林的故事
//此版本尝试对 Windows XP 和 Windows Vista 恢复支持，但由于 Visual Studio 2019 的兼容性放弃 
//使用 Visual Studio 编译，Windows 窗体应用。
//October 13, 2019
