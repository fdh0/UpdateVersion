#pragma once
#include "afxwin.h"


// CDlgSetting �Ի���

class CDlgSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetting)

public:
	CDlgSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSetting();

	CString IniFilePath; // ���������ļ����� 

// �Ի�������
	enum { IDD = IDD_DIALOG_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnKillfocusEditUrl();
	afx_msg void OnBnClickedButtonRoute();
	CEdit m_Edit_SetUrl;
	CEdit m_Edit_URL;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSetClose();
};
