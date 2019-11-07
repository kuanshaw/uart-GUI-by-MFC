
// ClientDlg.h : 头文件
//

#pragma once

#include "afxwin.h"
#include "ClientSocket.h"


// CClientDlg 对话框
class CClientDlg : public CDialogEx
{
// 构造
public:
	CClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();

public:
	bool m_connect;
	CClientSocket* pSock;  // 客户端套接字指针对象
	BOOL WChar2MByte(LPCWSTR lpSrc, LPSTR lpDest, int nlen); //字符转换函数
	virtual BOOL PreTranslateMessage(MSG* pMsg);		//防止按下enter、esc时退出程序

public:
	CButton m_ConPC;
	CString m_DataSend;
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedConnect();
	UINT m_port;
	CString m_IP;
};
