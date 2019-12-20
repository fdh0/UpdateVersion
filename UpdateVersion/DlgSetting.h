#pragma once
#include "afxwin.h"


// CDlgSetting 对话框

class CDlgSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetting)

public:
	CDlgSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSetting();

	CString IniFilePath; // 定义配置文件变量 

// 对话框数据
	enum { IDD = IDD_DIALOG_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnKillfocusEditUrl();
	afx_msg void OnBnClickedButtonRoute();
	CEdit m_Edit_SetUrl;
	CEdit m_Edit_URL;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSetClose();
};
