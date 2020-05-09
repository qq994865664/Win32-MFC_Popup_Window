// MiniNews.cpp : 定义应用程序的入口点。
// Download by http://www.codefans.net

#include "stdafx.h"
#include "MiniNews.h"
#include "NewsWindow.h"

CNewsWindow NewsWindow;
BOOL InitNews();

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

	if (!InitNews())
		return 0;


	// 主消息循环:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
BOOL InitNews()
{
	//int nScreenWidth, nScreenHeight;
	//nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	//nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	//printf("当前屏幕的分辨率为：%d×%d", nScreenWidth, nScreenHeight);
	//return 0;

	/*LPCTSTR lpNewsTitle		= _T("测试新闻标题");
	LPCTSTR lpNewsContent	= _T("测试新闻内容,彗星科技发展有限公司(彗星网络)有着多年网站制作、软件开发经验，并有经验丰富的开发团队。为您提供专业的网站建设、软件开发等服务。");*/
	LPCTSTR lpNewsTitle = _T("ShotgunTimeLog通知");
	LPCTSTR lpNewsContent = _T("您现在该更新ShogunTimelog啦~~~~~\n\n点击该窗口，直接运行Timelog程序！（点击一次即可，请勿点击多次）\n\n本弹框将不再强制隐藏任务栏\n\n本提醒将在您登陆Timelog后自动退出~~~~");
	LPCTSTR lpNewsURL = _T("C:\\ShotgunDesktop\\TimelogAutoRun.bat");
	//LPCTSTR lpNewsURL = _T("www.baidu.com");

	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_QQ));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_WANGWANG));
	NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_XUNLEI),0xFFFFFF);
	if (!NewsWindow.Create(_T("通知")))
		return FALSE;

	NewsWindow.SetNews(lpNewsTitle, lpNewsContent, lpNewsURL);
	NewsWindow.Show();
	NewsWindow.SetMainWindow();
	//NewsWindow.SetAutoClose(TRUE);
	//NewsWindow.HideTaskbar();
	//NewsWindow.ShowTaskbar();
	//ShowWindow(NewsWindow.m_hWnd, SW_MAXIMIZE);//最大化 hwnd 所代表的窗口
	return TRUE;
}