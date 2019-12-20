// DlgSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "UpdateVersion.h"
#include "DlgSetting.h"
#include "afxdialogex.h"


// CDlgSetting 对话框

IMPLEMENT_DYNAMIC(CDlgSetting, CDialogEx)

CDlgSetting::CDlgSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSetting::IDD, pParent)
{
}

CDlgSetting::~CDlgSetting()
{
}

void CDlgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ROUTE, m_Edit_SetUrl);
	DDX_Control(pDX, IDC_EDIT_URL, m_Edit_URL);
}


BEGIN_MESSAGE_MAP(CDlgSetting, CDialogEx)
	ON_EN_KILLFOCUS(IDC_EDIT_URL, &CDlgSetting::OnEnKillfocusEditUrl)
	ON_BN_CLICKED(IDC_BUTTON_ROUTE, &CDlgSetting::OnBnClickedButtonRoute)
	ON_BN_CLICKED(IDC_BUTTON_SET_CLOSE, &CDlgSetting::OnBnClickedButtonSetClose)
END_MESSAGE_MAP()


// CDlgSetting 消息处理程序


void CDlgSetting::OnEnKillfocusEditUrl()
{
	// TODO: 在此添加控件通知处理程序代码
	CString read_url;
	GetDlgItem(IDC_EDIT_URL)->GetWindowText(read_url);
	WritePrivateProfileString("参数", "服务器地址", read_url, IniFilePath);
}


void CDlgSetting::OnBnClickedButtonRoute()
{
	// TODO: 在此添加控件通知处理程序代码

	BROWSEINFO bi;
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	//添加提示语句
	bi.lpszTitle= _T("请选择文件夹");
	//添加"新建文件夹项"和"编辑框"
	bi.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	// 显示一个对话框让让用户选择文件夹
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	char szFolder[_MAX_PATH];
	memset(szFolder, 0, sizeof(szFolder));
	CString strFolder = _T("");
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, szFolder);
		//保存文件夹路径存
		strFolder.Format(_T("%s"), szFolder);
		//AfxMessageBox(strFolder);
		m_Edit_SetUrl.SetWindowTextA(strFolder);
		WritePrivateProfileString("参数", "保存路径", strFolder, IniFilePath);
	}
	else
	{
		return;
	}
}


BOOL CDlgSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	IniFilePath="D:\\Program Files\\config.ini";   //  使用相对路径

	char cMissionPath[200];
	GetPrivateProfileString("参数","服务器地址","http://fengdh.cn/shared/",cMissionPath,200,IniFilePath);
	CString s_MissionPath;
	s_MissionPath.Format("%s",cMissionPath);
	m_Edit_URL.SetWindowText(TEXT(s_MissionPath));

	GetPrivateProfileString("参数","保存路径","D:\\",cMissionPath,200,IniFilePath);
	s_MissionPath.Format("%s",cMissionPath);
	m_Edit_SetUrl.SetWindowTextA(s_MissionPath);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgSetting::OnBnClickedButtonSetClose()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(-1);
}
