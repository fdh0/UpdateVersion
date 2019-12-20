// DlgSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UpdateVersion.h"
#include "DlgSetting.h"
#include "afxdialogex.h"


// CDlgSetting �Ի���

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


// CDlgSetting ��Ϣ�������


void CDlgSetting::OnEnKillfocusEditUrl()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString read_url;
	GetDlgItem(IDC_EDIT_URL)->GetWindowText(read_url);
	WritePrivateProfileString("����", "��������ַ", read_url, IniFilePath);
}


void CDlgSetting::OnBnClickedButtonRoute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	BROWSEINFO bi;
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	//�����ʾ���
	bi.lpszTitle= _T("��ѡ���ļ���");
	//���"�½��ļ�����"��"�༭��"
	bi.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	// ��ʾһ���Ի��������û�ѡ���ļ���
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	char szFolder[_MAX_PATH];
	memset(szFolder, 0, sizeof(szFolder));
	CString strFolder = _T("");
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, szFolder);
		//�����ļ���·����
		strFolder.Format(_T("%s"), szFolder);
		//AfxMessageBox(strFolder);
		m_Edit_SetUrl.SetWindowTextA(strFolder);
		WritePrivateProfileString("����", "����·��", strFolder, IniFilePath);
	}
	else
	{
		return;
	}
}


BOOL CDlgSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	IniFilePath="D:\\Program Files\\config.ini";   //  ʹ�����·��

	char cMissionPath[200];
	GetPrivateProfileString("����","��������ַ","http://fengdh.cn/shared/",cMissionPath,200,IniFilePath);
	CString s_MissionPath;
	s_MissionPath.Format("%s",cMissionPath);
	m_Edit_URL.SetWindowText(TEXT(s_MissionPath));

	GetPrivateProfileString("����","����·��","D:\\",cMissionPath,200,IniFilePath);
	s_MissionPath.Format("%s",cMissionPath);
	m_Edit_SetUrl.SetWindowTextA(s_MissionPath);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgSetting::OnBnClickedButtonSetClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(-1);
}
