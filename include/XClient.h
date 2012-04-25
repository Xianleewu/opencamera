// XClient.h
//

//need include
//hikclient.lib DS40xxSDK.lib hieclient.lib HCNetSDK.lib NVClientDLL.lib 

#define SERIALNO_LEN 	48
#define MAXDECCARDCHN	64

//For For HIK hie nv hikDVR dhDVR jpDVR

#define HIKCLIENT
//#define	HIECLIENT
#define NVCLIENT
#define HIKNETDVRCLIENT
#define DHNETDVRCLIENT
//#define JPNETDVRCLIENT	//����Ƕ��ʽ	//add by he 20071011

enum{HIK=0, HIE, NVINFO, HIKNETDVR, DHNETDVR, JPNETDVR};//modify by he 20071011
enum{NORMALMODE=0,OVERLAYMODE};
enum{UDPMODE=0, TCPMODE, MULTIMODE};

enum{LAN = 0, ADSL, ISDN, PSTN};

//����Ƕ��ʽ
#define NET_DVR_DEFAULTBRIGHTNESS 6
#define NET_DVR_DEFAULTCONTRAST 6
#define NET_DVR_DEFAULTSATURATION  6
#define NET_DVR_DEFAULTHUE 6

#define MAX_ALARMOUT 4
#define MAX_CHANNUM 16
#define MAX_DISKNUM 16
#define MAX_LINK 6
#define MAX_ALARMIN 16

//�ͻ����յ�����Ϣ
//#define RECDATAERR	0 //�������������쳣
//#define PLAYERR     1 //�ͻ��˲��ų����쳣
//#define REFUSED     2 //�ͻ������ӱ��ܾ�
//#define SERVERCLOSE 3 //�������˳�
//#define NETFAILED   4 //�������ͨ�ų����쳣

//�ͻ���״̬
#define INVALID			-1	//��Ч
#define CONNECTING	    1	//��������
#define RECEIVING		2	//��ʼ����ͼ��
#define HALT			3	//�쳣�˳�
#define FINISH		    4	//������ϣ��Ƴ�
#define UNREACHABLE		5	//�޷���ϵ������
#define REFUSE		    6	//�������ܾ�����

typedef struct{
	BYTE	m_bytRemoteChannel;	//����ͨ���Ŵ�0��ʼ
	BYTE	m_bytSendMode;		//�������ӷ�ʽ{UDPMODE=0,TCPMODE,MULTIMODE}
	BYTE	m_bytSendType;		//���紫������{LAN = 0, ADSL, ISDN, PSTN}
	BYTE	m_bytImgFormat;		//����ͼ���ʽ��0Ϊ�������ͨ��ͼ��1Ϊ�������ͨ��ͼ��
	UINT	m_nPort;			//���ն˿ں�
	char    *m_szIPAddress;		//�����IP��ַ
	char    *m_szUserName;		//�û���
	char    *m_szUserPassword;	//����
	BOOL	m_bUserCheck;		//�Ƿ�����û�У��
	HWND	m_hShowVideo;		//��ʾ����
}XCLIENT_VIDEOINFO, *PXCLIENT_VIDEOINFO;

typedef struct{
	long bToScreen;		//�������ʾ��
	long bToVideoOut;	//1
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;		//0
}XDISPLAY_PARA,*PXDISPLAY_PARA;

typedef struct{
	BYTE    m_bRemoteChannel;	//����ͨ���Ŵ�0��ʼ
	BYTE    m_bSendMode;		//�������ӷ�ʽ{UDPMODE=0,TCPMODE,MULTIMODE}
	BYTE    m_bRight;			//��������
	UINT	m_nPort;			//���ն˿ں�
	char    *m_szIPAddress;		//�����IP��ַ
	char    *m_szUserName;		//�û���
	char    *m_szUserPassword;	//����
	BOOL    m_bUserCheck;		//�Ƿ�����û�У��
	XDISPLAY_PARA displaypara;	//��ʾ����
	LONG	lUserID;			//����Ƕ��ʽ�û�ID	//add by he 20070402
}XCLIENT_CARDINFO, *PXCLIENT_CARDINFO;

typedef struct{
	char MRServerIPAddress[16];	//ת��������IP��ַ
	WORD MRServerPort;			//ת���������˿�
	BYTE Priority;				//ת������������Ȩ��(��ʱֻ�����л�ͨ����)
	BYTE withhold;				//����
}XCLIENT_MRSERVERINFO, *PXCLIENT_MRSERVERINFO;

/*
typedef struct  {
	BYTE sSerialNumber[SERIALNO_LEN];  //���к�
	BYTE byAlarmInPortNum;		//DVR�����������
	BYTE byAlarmOutPortNum;		//DVR�����������
	BYTE byDiskNum;				//DVR Ӳ�̸���
	BYTE byDVRType;				//DVR����, 
	BYTE byChanNum;				//DVR ͨ������
	BYTE byStartChan;			//��ʼͨ����,����DVS-1,DVR - 1
}NET_DVR_DEVICEINFO, *LPNET_DVR_DEVICEINFO;
*/

typedef struct
{
	UINT left;
	UINT top;
	UINT width;
	UINT height;
	COLORREF color;
	UINT param;
}REGION_PARAM;


typedef struct
{
	FILETIME	FCreationTime;//�ļ���ʼʱ��
	FILETIME	FLastWriteTime;//�ļ�����ʱ��
	__int64		iFLength;
	char		szFPath[MAX_PATH];
	BYTE		bytChn;//(1-MAXCHN)
	BYTE		bytType;//0:ȫ��1:�ֶ�2:�Զ�3:����4:�¼�
}RECFILE_INFO, *PRECFILE_INFO;

//add by he 20070425
typedef struct
{
	DWORD dwYear;		//��
	DWORD dwMonth;		//��
	DWORD dwDay;		//��
	DWORD dwHour;		//ʱ
	DWORD dwMinute;		//��
	DWORD dwSecond;		//��
} NET_TIME,*LPNET_TIME;

//add by he 20070425
typedef struct {
    unsigned int     ch;              //ͨ����
    char             filename[128];   //�ļ���
    unsigned int     size;            //�ļ�����
    NET_TIME         starttime;       //��ʼʱ��
    NET_TIME         endtime;         //����ʱ��
    unsigned int     driveno;         //���̺�
    unsigned int     startcluster;    //��ʼ�غ�
}NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;


//����
typedef struct _tagOperateDay
{
	SYSTEMTIME st;
	DWORD dwDate;
}OperateDay;

typedef struct tagChannelFileInfo
{
	int			Disk;	//�ļ�λ����һ����
	char		FileName[40];		//�ļ���
	int			nDiskSerial;	// �ļ����ڵľ��
}ChannelFileInfo,*PChannelFileInfo;

//add by he 20071121
typedef struct
{
	int nChannel;
	OperateDay ChnDayInfo;
	ChannelFileInfo ChnFileInfo;
}JP_FILEINFO, *PJP_FILEINFO;

//add by he 20070425
typedef struct
{
	WORD wFileType;//���Ͱ��շ���������
	union 
	{
		RECFILE_INFO NetFileinfo;//PC������Ƕ��ʽ���ص��ļ��ṹ
		NET_RECORDFILE_INFO dhFileinfo;//��Ƕ��ʽ���ص��ļ��ṹ
		JP_FILEINFO jpFileInfo;//�����ļ����Žṹ	//add by he 20071121
	}FileInfo;
}NET_RECFILE_INFO, *PNET_RECFILE_INFO;

typedef struct
{
	FILETIME	FFormTime;//��ʼʱ��
	FILETIME	FToTime;//����ʱ��
	BYTE		bytChn;//��ʾͨ����
	BYTE		bytType;//¼������
	char		szServerAddr[MAX_PATH];//�������ķ�������ַ��������������IP��ַ����Ϊ���򲻽����ж�
}SEARCH_RECINFO, *PSEARCH_RECINFO;

typedef struct  {
	BYTE sSerialNumber[SERIALNO_LEN];  //���к�
	BYTE byAlarmInPortNum;		//DVR�����������
	BYTE byAlarmOutPortNum;		//DVR�����������
	BYTE byDiskNum;				//DVR Ӳ�̸���
	BYTE byDVRType;				//DVR����, 
	BYTE byChanNum;				//DVR ͨ������
	BYTE byStartChan;			//��ʼͨ����,����DVS-1,DVR - 1
}NET_DVR_DEVICEINFO, *LPNET_DVR_DEVICEINFO;

typedef struct {
	BYTE byRecordStatic; //ͨ���Ƿ���¼��,0-��¼��,1-¼��
	BYTE bySignalStatic; //���ӵ��ź�״̬,0-����,1-�źŶ�ʧ
	BYTE byHardwareStatic;//ͨ��Ӳ��״̬,0-����,1-�쳣,����DSP����
	char reservedData;
	DWORD dwBitRate;//ʵ������
	DWORD dwLinkNum;//�ͻ������ӵĸ���
	DWORD dwClientIP[MAX_LINK];//�ͻ��˵�IP��ַ
}NET_DVR_CHANNELSTATE,*LPNET_DVR_CHANNELSTATE;

typedef struct {
	DWORD dwVolume;//Ӳ�̵�����
	DWORD dwFreeSpace;//Ӳ�̵�ʣ��ռ�
	DWORD dwHardDiskStatic; //Ӳ�̵�״̬,����,�,��������
}NET_DVR_DISKSTATE,*LPNET_DVR_DISKSTATE;


typedef struct{
	DWORD dwDeviceStatic; 	//�豸��״̬,0-����,1-CPUռ����̫��,����85%,2-Ӳ������,���紮������
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM]; 
	NET_DVR_CHANNELSTATE struChanStatic[MAX_CHANNUM];//ͨ����״̬
	BYTE  byAlarmInStatic[MAX_ALARMIN]; //�����˿ڵ�״̬,0-û�б���,1-�б���
	BYTE  byAlarmOutStatic[MAX_ALARMOUT]; //��������˿ڵ�״̬,0-û�����,1-�б������
	DWORD  dwLocalDisplay;//������ʾ״̬,0-����,1-������
}NET_DVR_WORKSTATE,*LPNET_DVR_WORKSTATE;


