// mr_test.cpp : 定义控制台应用程序的入口点。
//


#pragma comment(lib,"mrapi.lib")

#include "stdafx.h"

#include <stdio.h>
#include <string>
#include <Windows.h>
#include <WinBase.h>
#include <process.h>
#include <time.h>

#include "mrapi.h"
#include "mr2api.h"

using namespace std;
#define MRAPI_DLL ".\\mrapi.dll"

typedef void *(WINAPI MR2INIT)(const char*, const char*, int, const STUConnInfo2*, void *);
typedef void *(WINAPI MR2INIT1)(const char*, const char*, const char*, int, const STUConnInfo2*, void *);
typedef void  (WINAPI MR2INIT1EX1)(void**, const char*, const char*, const char*, STUMsgProperty2*, int, const STUConnInfo2*, void*, int);
typedef void  (WINAPI MR2INIT2)(void**, const char*, const char*, STUMsgProperty2*, int, const STUConnInfo2*, void*, int);
typedef int   (WINAPI MR2CREATEPKGID)(void*, char *);
typedef int   (WINAPI MR2SEND)(void*, const char*, int, STUMsgProperty2*, int);
typedef int   (WINAPI MR2RECEIVE1)(void*, char**, int*, STUMsgProperty2*, int);
typedef void  (WINAPI MR2RECEIVE1_FREEBUF)(char*);
typedef int   (WINAPI MR2RECEIVE2)(void*, char*, int*, int, STUMsgProperty2*, int);
typedef int   (WINAPI MR2RECEIVE3)(void*, char**, int*, int*, STUMsgProperty2*, int);
typedef int   (WINAPI MR2ISLINKOK)(void*);
typedef void  (WINAPI MR2GETVERSION)(char*, int);
typedef int   (WINAPI MR2REGRECVCONDITION)(void*, STUMsgProperty2*, int);
typedef void  (WINAPI MR2DESTROY)(void*);
typedef int   (WINAPI MR2MULTIDESTSEND)(void*, const char*, int, STUMultiDestMsgProperty*, int);

MR2INIT				*Mr2Init_1;
MR2INIT2			*Mr2Init2_1;
MR2CREATEPKGID		*Mr2CreatePkgID_1;
MR2SEND				*Mr2Send_1;
MR2RECEIVE1			*Mr2Receive1_1;
MR2RECEIVE1_FREEBUF	*Mr2Receive1_FreeBuf_1;
MR2RECEIVE2			*Mr2Receive2_1;
MR2RECEIVE3			*Mr2Receive3_1;
MR2ISLINKOK			*Mr2IsLinkOK_1;
MR2GETVERSION		*Mr2GetVersion_1;
MR2REGRECVCONDITION	*Mr2RegRecvCondition_1;
MR2DESTROY			*Mr2Destroy_1;
MR2MULTIDESTSEND	*Mr2MultiDestSend_1;

HINSTANCE m_ghDll;

bool LoadDll()
{
	bool bRet = false ;
	
	m_ghDll = ::LoadLibrary(LPCWSTR(MRAPI_DLL)) ;
	if (m_ghDll == NULL)
	{
		printf("error: can not find (mrapi.dll).") ;
		return bRet ;
	}

	Mr2Init_1 = (MR2INIT *)::GetProcAddress(m_ghDll, "Mr2Init") ;
	if (Mr2Init_1 == NULL)
	{
		printf("error: can not find Mr2Init(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Init2_1 = (MR2INIT2 *)::GetProcAddress(m_ghDll, "Mr2Init2") ;
	if (Mr2Init2_1 == NULL)
	{
		printf("error: can not find Mr2Init2(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Send_1 = (MR2SEND *)::GetProcAddress(m_ghDll, "Mr2Send") ;
	if (Mr2Send_1 == NULL)
	{
		printf("error: can not find Mr2Send(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2MultiDestSend_1 = (MR2MULTIDESTSEND *)::GetProcAddress(m_ghDll, "Mr2MultiDestSend") ;
	if (Mr2MultiDestSend_1 == NULL)
	{
		printf("error: can not find Mr2MultiDestSend(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2CreatePkgID_1 = (MR2CREATEPKGID *)::GetProcAddress(m_ghDll, "Mr2CreatePkgID") ;
	if (Mr2CreatePkgID_1 == NULL)
	{
		printf("error: can not find Mr2CreatePkgID(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Receive1_1 = (MR2RECEIVE1 *)::GetProcAddress(m_ghDll, "Mr2Receive1") ;
	if (Mr2Receive1_1 == NULL)
	{
		printf("error: can not find Mr2Receive1(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Receive1_FreeBuf_1 = (MR2RECEIVE1_FREEBUF *)::GetProcAddress(m_ghDll, "Mr2Receive1_FreeBuf") ;
	if (Mr2Receive1_FreeBuf_1 == NULL)
	{
		printf("error: can not find Mr2Receive1_FreeBuf(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Receive2_1 = (MR2RECEIVE2 *)::GetProcAddress(m_ghDll, "Mr2Receive2") ;
	if (Mr2Receive2_1 == NULL)
	{
		printf("error: can not find Mr2Receive2(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Receive3_1 = (MR2RECEIVE3 *)::GetProcAddress(m_ghDll, "Mr2Receive3") ;
	if (Mr2Receive3_1 == NULL)
	{
		printf("error: can not find Mr2Receive3(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2IsLinkOK_1 = (MR2ISLINKOK *)::GetProcAddress(m_ghDll, "Mr2IsLinkOK") ;
	if (Mr2IsLinkOK_1 == NULL)
	{
		printf("error: can not find Mr2IsLinkOK(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2Destroy_1 = (MR2DESTROY *)::GetProcAddress(m_ghDll, "Mr2Destroy") ;
	if (Mr2Destroy_1 == NULL)
	{
		printf("error: can not find Mr2Destroy(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2RegRecvCondition_1 = (MR2REGRECVCONDITION *)::GetProcAddress(m_ghDll, "Mr2RegRecvCondition") ;
	if (Mr2RegRecvCondition_1 == NULL)
	{
		printf("error: can not find Mr2RegRecvCondition(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}

	Mr2GetVersion_1 = (MR2GETVERSION *)::GetProcAddress(m_ghDll, "Mr2GetVersion") ;
	if (Mr2GetVersion_1 == NULL)
	{
		printf("error: can not find Mr2GetVersion(mrapi.dll)") ;
		::FreeLibrary(m_ghDll) ;
		m_ghDll = NULL ;
		return bRet ;
	}
	return true ;
}

void MySleep(int iMillSecond)
{
	Sleep(iMillSecond);
}


void*   g_pHandle = NULL;
time_t  g_ltLastTimeRecv = 0;
time_t  g_ltBeginTimeRecv = 0;
int      g_iRecvCount = 0;


int OnReceive(const char* psPkg, int iPkgLen, const STUMsgProperty2* pMsgPropery, void* pvUserData)
{
    g_ltLastTimeRecv = time(NULL);
    ++g_iRecvCount;
    if(g_iRecvCount%100==0)
    {
        printf("recv ok: PkgContent[%s]\n, pkgID[%s], src[%s.%s], dest[%s.%s], pkgLen[%d], CorrPkgID[%s], UserData1[%s], UserData2[%s] \n", psPkg, pMsgPropery->m_szPkgID, pMsgPropery->m_szSourceUserID, pMsgPropery->m_szSourceAppID, pMsgPropery->m_szDestUserID, pMsgPropery->m_szDestAppID, iPkgLen, pMsgPropery->m_szCorrPkgID, pMsgPropery->m_szUserData1, pMsgPropery->m_szUserData2);
        printf("client recv count[%d]\n", g_iRecvCount);
    }

#ifndef MR_CLIENT
    STUMsgProperty2 oMsgProperySend;
    memset(&oMsgProperySend, '\0', sizeof(STUMsgProperty2));
    strcpy(oMsgProperySend.m_szDestUserID, pMsgPropery->m_szSourceUserID);
    strcpy(oMsgProperySend.m_szDestAppID, pMsgPropery->m_szSourceAppID);
    strcpy(oMsgProperySend.m_szCorrPkgID, pMsgPropery->m_szPkgID);
    strcpy(oMsgProperySend.m_szUserData1, pMsgPropery->m_szUserData1);
    strcpy(oMsgProperySend.m_szUserData2, pMsgPropery->m_szUserData2);
    oMsgProperySend.m_ucFlag = 0;
    int iRet = Mr2Send(g_pHandle, psPkg, iPkgLen, &oMsgProperySend, 2000);
#endif

    return 0;
}


unsigned __stdcall RecvThrd(void *pvParam)
{
    int iLastGetOk = 0;
    for(;;)
    {
        STUMsgProperty2 oMsgPropery;
        memset(&oMsgPropery, '\0', sizeof(STUMsgProperty2));

        int iRecvPkgLen = 0;
        char* psPkg = NULL;
		int iRet = Mr2Receive1(g_pHandle, &psPkg, &iRecvPkgLen, &oMsgPropery, 1000);
        if(iRet==0)
        {
            g_ltLastTimeRecv = time(NULL);
            ++g_iRecvCount;
            if(g_iRecvCount%100==0)
            {
                printf("recv ok: PkgContent[%s]\n, pkgID[%s], src[%s.%s], dest[%s.%s], pkgLen[%d], CorrPkgID[%s], UserData1[%s], UserData2[%s] \n", psPkg, oMsgPropery.m_szPkgID, oMsgPropery.m_szSourceUserID, oMsgPropery.m_szSourceAppID, oMsgPropery.m_szDestUserID, oMsgPropery.m_szDestAppID, iRecvPkgLen, oMsgPropery.m_szCorrPkgID, oMsgPropery.m_szUserData1, oMsgPropery.m_szUserData2);
                printf("client recv count[%d]\n", g_iRecvCount);
            }

#ifndef MR_CLIENT
            STUMsgProperty2 oMsgProperySend;
            memset(&oMsgProperySend, '\0', sizeof(STUMsgProperty2));
            strcpy(oMsgProperySend.m_szDestUserID, oMsgPropery.m_szSourceUserID);
            strcpy(oMsgProperySend.m_szDestAppID, oMsgPropery.m_szSourceAppID);
            strcpy(oMsgProperySend.m_szCorrPkgID, oMsgPropery.m_szPkgID);
            strcpy(oMsgProperySend.m_szUserData1, oMsgPropery.m_szUserData1);
            strcpy(oMsgProperySend.m_szUserData2, oMsgPropery.m_szUserData2);
            oMsgProperySend.m_ucFlag = 0;
            int iRet = Mr2Send(g_pHandle, psPkg, iRecvPkgLen, &oMsgProperySend, 2000);
#endif
            Mr2Receive1_FreeBuf(psPkg);
        }
        else
        {
            MySleep(500);
        }
    }
    return 0;
}


int main(int argc, char* argv[])
{
	if (!LoadDll())
	{
		printf("load mrapi.dll error.\n");
		return -1;
	}
	
	string ssSourceUserID, ssSourceAppID, ssDestUserID, ssDestAppID;
    string ssName1 = "FTCSTEST91";
    string ssName2 = "app8";
    string ssName3 = "FTCSTEST92";
    string ssName4 = "app6";
#ifdef MR_CLIENT
    ssSourceUserID = ssName1;
    ssSourceAppID = ssName2;
    ssDestUserID = ssName3;
    ssDestAppID = ssName4;
#else
    ssSourceUserID = ssName3;
    ssSourceAppID = ssName4;
    ssDestUserID = ssName1;
    ssDestAppID = ssName2;
#endif

    g_ltLastTimeRecv = time(NULL);

    string ssMyPasswd = "1";
    string *pUserData = new string("hello");

    STUConnInfo2  oConnInfo[2];
    memset(&oConnInfo, 0, 2*sizeof(STUConnInfo2));
    if(argc<2) strcpy(oConnInfo[0].m_szMRIP, "127.0.0.1");
    else strcpy(oConnInfo[0].m_szMRIP, argv[1]);
    oConnInfo[0].m_usMRPort = 1001;
    strcpy(oConnInfo[1].m_szMRIP, "127.0.0.1");
    oConnInfo[1].m_usMRPort = 3001;

    g_pHandle = Mr2Init(ssSourceAppID.c_str(), ssMyPasswd.c_str(), NULL, &oConnInfo[0], 2, pUserData);
	if(g_pHandle==NULL) return -1;
/*
    STUMsgProperty2 oOnRecvMsgPropery;
    memset(&oOnRecvMsgPropery, 0, sizeof(STUMsgProperty2));
    strcpy(oOnRecvMsgPropery.m_szCorrPkgID, "<EMPTY>");
    Mr2Init2(&g_pHandle, ssSourceAppID.c_str(), ssMyPasswd.c_str(), &oOnRecvMsgPropery, (int)OnReceive, &oConnInfo, 2, pUserData, 1);
    if(g_pHandle==NULL) return -1;

*/
    if(_beginthreadex(NULL, 0,  RecvThrd, NULL, 0, NULL)==0)
    {
        printf("create thread failed\n");
        return -1;
    }

    printf("\n");
    MySleep(2000);

    g_ltLastTimeRecv = time(NULL);


//#ifdef MR_CLIENT
    STUMsgProperty2 oMsgPropery;
    int i=0;
    for(;;)
    {
        memset(&oMsgPropery, '\0', sizeof(STUMsgProperty2));
		    strcpy(oMsgPropery.m_szSourceAppID, ssSourceAppID.c_str());
        strcpy(oMsgPropery.m_szDestUserID, ssDestUserID.c_str());
        strcpy(oMsgPropery.m_szDestAppID, ssDestAppID.c_str());
        oMsgPropery.m_ucFlag = 0;

        ++i;
        char * pSendStrNew = new char[65536];
        strcpy(pSendStrNew, " <IFTS Len=\" 1205\" DataVer =\"1.0.0.1\" SeqNo=\"\" Type=\"B\" Dup=\"N\" CheckSum=\"\">\n");
        strcat(pSendStrNew, "  <MsgText> \n");
        strcat(pSendStrNew, "     <Acmt.001.01> \n");
        strcat(pSendStrNew, "       <MsgHdr> \n");
        strcat(pSendStrNew, "          <Ver>1.0</Ver> \n");
        strcat(pSendStrNew, "          <SysType>0</SysType> \n");
        strcat(pSendStrNew, "          <InstrCd>11002</InstrCd> \n");
        strcat(pSendStrNew, "          <Sender> \n");
        strcat(pSendStrNew, "            <InstType>S</InstType> \n");
        strcat(pSendStrNew, "             <BrchId>1</BrchId> \n");
        strcat(pSendStrNew, "          </Sender> \n");
        strcat(pSendStrNew, "          <Recver> \n");
        strcat(pSendStrNew, "             <InstType>B</InstType> \n");
        strcat(pSendStrNew, "             <BrchId>2</BrchId> \n");
        strcat(pSendStrNew, "          </Recver> \n");
        strcat(pSendStrNew, "          <Date>20061216</Date> \n");
        strcat(pSendStrNew, "          <Time>114340</Time> \n");
        strcat(pSendStrNew, "          <Ref> \n");
        strcat(pSendStrNew, "           <IssrType>S</IssrType> \n");
        strcat(pSendStrNew, "           <Ref>9</Ref> \n");
        strcat(pSendStrNew, "          </Ref> \n");
        strcat(pSendStrNew, "        </MsgHdr> \n");
        strcat(pSendStrNew, "        <Cust> \n");
        strcat(pSendStrNew, "          <Name>郭达</Name> \n");
        strcat(pSendStrNew, "          <CertType>10</CertType> \n");
        strcat(pSendStrNew, "          <CertId>42218901</CertId> \n");
        strcat(pSendStrNew, "          <Type>INVE</Type> \n");
        strcat(pSendStrNew, "          <Sex>M</Sex> \n");
        strcat(pSendStrNew, "          <Ntnl>CHN</Ntnl> \n");
        strcat(pSendStrNew, "          <Addr>八卦四路22号</Addr>\n");
        strcat(pSendStrNew, "          <PstCd>518029</PstCd> \n");
        strcat(pSendStrNew, "          <Email></Email> \n");
        strcat(pSendStrNew, "          <Fax></Fax> \n");
        strcat(pSendStrNew, "          <Mobile>13843453</Mobile> \n");
        strcat(pSendStrNew, "          <Tel></Tel> \n");
        strcat(pSendStrNew, "         </Cust> \n");
        strcat(pSendStrNew, "         <Agt> </Agt>\n");
        strcat(pSendStrNew, "         < BkAcct> </ BkAcct>\n");
        strcat(pSendStrNew, "         < ScAcct> </ ScAcct>\n");
        strcat(pSendStrNew, "         < ScAcct> </ ScAcct>\n");
        strcat(pSendStrNew, "      </Acmt.001.01>\n");
        strcat(pSendStrNew, "   </MsgText>\n");
        strcat(pSendStrNew, " </IFTS>\n");
        string ssPkg = pSendStrNew;
        delete []pSendStrNew;
    sprintf(oMsgPropery.m_szCorrPkgID, "%d", i);
    sprintf(oMsgPropery.m_szUserData1, "%d", i+1);
    sprintf(oMsgPropery.m_szUserData2, "%d", i+2);
        int iRet = Mr2Send(g_pHandle, ssPkg.c_str(), (int)ssPkg.length(), &oMsgPropery, 2000);
        if(i%100==0)
            printf("client send[%d-%d]\n", i, iRet);

        MySleep(50);
    }
    printf("send finished\n");

//#else

    for(;;MySleep(1000))
    {
    }
//#endif

    Mr2Destroy(g_pHandle);
    printf("End\n");
    getchar();

    return 0;
}
