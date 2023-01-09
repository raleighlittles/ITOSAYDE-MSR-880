#ifndef _EMV_CORE_H
#define _EMV_CORE_H

#ifdef __cplusplus
    extern "C" {
#endif

#pragma pack(1)

#ifdef DLL_API
#define DLLAPI  _declspec(dllexport)
#else
#define DLLAPI
#endif

#ifndef u8
#define u8 unsigned char
#endif
#ifndef u16
#define u16 unsigned short
#endif
#ifndef u32
#define u32 unsigned int
#endif
#ifndef s8
#define s8  char
#endif
#ifndef s16
#define s16  short
#endif
#ifndef s32
#define s32  int
#endif

//���׵��ں�����
#define KERNAL_EMV_PBOC                     0       //EMV&PBOC
#define KERNAL_CONTACTLESS_ENTRY_POINT      1       //�ǽ�ͳһ���

//EMV L2�������ⲿ��
#define EMV_TEST_CONFIG_UNIONPAY            0
#define EMV_TEST_CONFIG_EMV                 1
#define EMV_TEST_CONFIG_PBOC                2
#define EMV_TEST_CONFIG_QPBOC               3
#define EMV_TEST_CONFIG_QUICS               4
#define EMV_TEST_CONFIG_PAYWARE             5
#define EMV_TEST_CONFIG_PAYPASS             6

//qPBOC�ֿ�����֤��ʽ
#define RD_CVM_NO 					0x00        //��
#define RD_CVM_ONLINE_PIN 		    0x80        //����PIN
#define RD_CVM_SIG 					0x40        //ǩ��
//#define RD_CVM_ONLINE_PIN_AND_SIG   0xC0        //����+ǩ��

//���׽��
#define APPROVE_M                   0x40        //��׼
#define DECLINE_M                   0x00        //�ܾ�
#define ONLINE_M                    0x80        //����

//PIN
#define ONLINE_ENCIPHERED_PIN       0x00        //��������PIN
#define OFFLINE_PLAINTEXT_PIN       0x01        //�ѻ�����PIN
#define OFFLINE_ENCIPHERED_PIN      0x02        //�ѻ�����PIN

//���׿�ѡ��,��λʹ��
#define OPTION_CARDHOLDER_NOT_PERFORM       0x01 //�ֽ��ֵ��Ȧ�������ô�λ��ִ�гֿ�����֤
#define OPTION_OFFLINE_DATA_AUTH_PREFORM    0x02 //�ѻ�������֤��ִ��

//PayPass ��������
#define TYPE_GOODS           0x00    //��������(����)
#define TYPE_REFUND          0x20    //��������(�˻�)

//IC������_����ʱ�洢
typedef struct
{
	u8 ucAID[16];		        	//9F06 Ӧ��ID
	u8 ucAIDLen;                  	//     Ӧ��aid����
	u8 ucSelectIndicator;     		//DF01 Ӧ��ѡ��ָʾ����ASI��(=0����ƥ��,=1��ȫƥ��)
	u8 ucTargetPercentage;     		//DF17 ����ٷֱ�
	u8 ucMaxTargetPercentage;  		//DF16 ������ٷֱ�
	u8 ucTermFloor[4];        		//9F1B �ն�����޶�HEX
    u8 ucOnLinePINFlag;            	//DF18 �ն�����PIN֧������(=0��֧��,=1֧��)
	u32 uiThresholdValue;			//DF15 ���ѡ��ֵ
	u8 ucTACDefault[5];        		//DF11 ȱʡ
	u8 ucTACDenial[5];         		//DF13 �ܾ�
	u8 ucTACOnline[5];         		//DF12 ����
	u8 ucDdolLen;       			//     DDOL����
	u8 ucDdol[252];            		//DF14 ȱʡDDOL
	u8 ucTdolLen;       			//     TDOL����
	u8 ucTdol[252];            		//97   ȱʡTDOL
	u8 ucTermAVM[2];           		//9F09 Ӧ�ð汾��
	u8 ucRFTxnLmt[6];   			//DF20 �ǽӴ���д�������޶�bcd,>=��ֵ������ֹ
	u8 ucRFFLmt[6];     			//DF19 �ǽӴ���д���ѻ�����޶�bcd,>��ֵ���� DF8123
	u8 ucRFCVMLmt[6];       		//DF21 �ǽӶ�д���ֿ�����֤����CVM��������bcd,>=��ִֵ��CVM
	u8 ucECTranLmt[6];        		//9F7B �����ֽ��ն˽����޶�bcd,<�ߵ����ֽ�

    //����EMV���Ժ�̨����---------------------------------
	u8 ucMerchantNameLocation[40+1];//9F4E �̻�����ASC����0x00����
	u8 ucMerchantCode[2];           //9F15 �̻������BCD
	u8 ucMerchantID[15+1];          //9F16 �̻���,Ӧ����0x00����
	u8 ucAcquirerID[6];        		//9F01 �յ���BCD
	u8 ucTermID[8+1];               //9F1C �ն˱�ʶ(�ն˺�),ASC��0x00����
	u8 ucTranRefCurrExp;		    //9F3D ���ײο�����ָ��
	u8 ucTranRefCurr[2];			//9F3C �ο����Ҵ���
	u8 ucTranCurrExp;			    //5F36 ���׻���ָ��
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���
    //----------------------------------------------------

	//PAYPASS---------------------------------
	u8 ucUdolLen;       			//UDOL����
	u8 ucUdol[240];            		//9F69     ȱʡUDOL
	u8 MagStripeInd;       			//     Mag Stripeָʾ��
	u8 MagStripeVer[2];             //9F6D    Mag Stripe�汾
    u8 TermCapNoCVMReq[3];          //NoCVM �ն�����
	u8 TermCapCVMReq[3];            //CVM �ն�����
	u8 ucPayPassAddTermCapa[5];     //9F40 �ն˸�������
	u8 ucPayPassTermType;		   //9F35 �ն�����
	u8 PaypassRFU[32];             //Ԥ��
	 //----------------------------------------------------
	u16 unCrc;						//	   crc
}T_EMV_APP_LIST;

//��֤���Ĺ�Կ����_����ʱ�洢
typedef struct
{
	u8 ucRID[5];               		//9F06 ����֤���Ĺ�Կ����һ���ʶ��֤���ĵĹ�Կ
	u8 ucIndex;                		//9F22 ��֤���Ĺ�Կ����
	u8 ucHashIndicator;        		//DF06 ��֤���Ĺ�Կ��ʲ�㷨��ʶ
	u8 ucCAPKIndicator;        		//DF07 ��֤���Ĺ�Կ�㷨��ʶ
	u8 ucModulusLen;
	u8 ucModulus[248];         		//DF02 ��֤���Ĺ�Կģ   �䳤�����Ϊ248
	u8 ucExponentLen;
	u8 ucExponent[3];         		//DF04 ��֤���Ĺ�Կָ��  0x10001��0x03
	u8 ucExpDate[3];           		//DF05 ��֤���Ĺ�Կ��Ч��(bcd yyyymmdd)
	u8 ucCheckSum[20];         		//DF03 ��֤���Ĺ�ԿУ��ֵsha1
	u16 unCrc;						//	   crc
}T_EMV_TERM_CAPK;

//֤������б�_�洢_EMV/PBOC L2����ʹ��
typedef struct
{
	u8 ucRID[5];               		//9F06 ����֤���Ĺ�Կ����һ���ʶ��֤���ĵĹ�Կ
	u8 ucIndex;                		//9F22 ��֤���Ĺ�Կ����
	u8 ucCertSerial[3];       		//     ֤�����к�
	u8 ucDeleteFlag;                //     =1��ɾ�� =0δɾ��
	u16 unCrc;						//	   crc
}T_EMV_REVOCATIONLIST;

//�ն˲���_������֮ǰ(�����main()����)����һ��(���洢)
typedef struct
{
	u8 ucIFD[8+1];                  //9F1E �豸���к�,ASC��0x00����
	u8 ucTerminalCountry[2];        //9F1A ���Ҵ���
	u8 ucTermType;				    //9F35 �ն�����
	u8 ucTermCapa[3];               //9F33 �ն�����
	u8 ucAddTermCapa[5];            //9F40 �ն˸�������

	u8 ucMerchantNameLocation[40+1];//9F4E �̻�����ASC����0x00����
	u8 ucMerchantCode[2];           //9F15 �̻������BCD
	u8 ucMerchantID[15+1];          //9F16 �̻���,Ӧ����0x00����
	u8 ucAcquirerID[6];        		//9F01 �յ���BCD
	u8 ucTermID[8+1];               //9F1C �ն˱�ʶ(�ն˺�),ASC��0x00����

	u8 ucTranRefCurrExp;		    //9F3D �ο�����ָ��
	u8 ucTranRefCurr[2];			//9F3C �ο����Ҵ���
	u8 ucTranCurrExp;			    //5F36 ���׻���ָ��
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���

    u8 ucCapture;                   //     ���ݲɼ� = 0�������ݲɼ� =1�����ݲɼ�
	u8 ucTermSMSupportIndicator;	//     �ն��Ƿ�֧��SM�㷨 =0��֧�� =1֧��
    u8 ucPaypassImplementationOptions;      //PayPassִ��ѡ�� =0 EMV��=1 Data Exchange

	u8 ucTermFLmtFlg;    			//	   �ǽӶ������Ƿ�֧���ն�����޶���9F1B (qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFTxnLmtFlg;				//	   �ǽӶ������Ƿ�֧�ֽ����޶���DF20(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFFLmtFlg;					//	   �ǽӶ������Ƿ�֧���ѻ�����޶���DF19(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFCVMLmtFlg;   			//	   �ǽӶ������Ƿ�֧��CVMִ���޶���DF21(qPBOCһ��Ϊ1) =0����飬=1���

	u8 ucRFStatusCheckFlg;    		// 	   �ǽӶ������Ƿ�֧��״̬���(qPBOCһ��Ϊ0) =1����Ȩ���Ϊ1,��9F66Ҫ����������
	u8 ucRFZeroAmtNoAllowed;       	//	   �ǽӽ���0�����(qPBOCһ��Ϊ0) =0����飬=1�������Ȩ���Ϊ0,��9F66Ҫ����������

	u8 ucUseFangba;                 //     �ǽ������������� =0������ =1����

	u8 ucPrintfDebugInfo;           //     ��ӡ���ڵ�����Ϣ =0����ӡ =1��ӡ
	u8 ucHostType;				    //	   =0��׼,=1BCTC���Ժ�̨
    u8 ucEmvTest;                   //     =0unionPay, =1EMV, =2PBOC, =3qPBOC, =4qUICS,=5PayWare,=6PayPass
    u8 ucUseCallBackApdu;           //     ʹ�ûص��������ͷ��ͽ���APDU =0������ =1����
}T_EMV_TERM_PARAM;

//���ײ���_������ǰ(����Ӧ��ѡ����)����(���洢)
typedef struct
{
	u8 ucTransKernalType; 			// 	   �ں�����, =0�Ӵ�ʽ��ǽӴ�ʽEMV/PBOC, =1�ǽ�ͳһ���
	u8 ucIsForceOnline;             //     �Ƿ�ǿ������,����EMV/PBOC�� =1 ǿ������(������ѯ��Ҫ)
	u8 ucIsSimpleFlow;              //     ����EMV/PBOC�� =0�������� =1 ��������(ֻ�ߵ�read record)
    u8 ucOption;                    //     ���׿�ѡ��(�����׿�ѡ��궨��,��λʹ��)
	u8 ucEcTerminalSupportIndicator;//9F7A �����ֽ��ն�֧��ָʾ��,����EMV/PBOC�� =0EMV =1�����ֽ�
    u8 ucReaderTTQ[4];      		//9F66 �ն˽������ܣ�����qPBOC��

    u8 ucTransNo[4];      			//9F41 ������ˮ�� BCD���������ѽ��ף�����ѯ��������
	u8 ucTransDate[3];  		    //9A   �������� BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 ����ʱ�� BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 ��Ȩ���(���׽��) BCD ,ucAmountAuth[0]=0x01��ʾ���Ϊ��
    u8 ucAmountOther[6];    		//9F03 �������(���ֽ��) BCD ,ucAmountOther[0]=0x01��ʾ���Ϊ��
	u8 ucTransType;                 //9C   �������� һ��Ϊ0x00 ,����������0x09

}T_EMV_TRANS_PARAM;

//������־
typedef struct
{
	u8 ucTransDate[3];  		    //9A   �������� BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 ����ʱ�� BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 ��Ȩ���(���׽��) BCD
    u8 ucAmountOther[6];    		//9F03 �������(���ֽ��) BCD
	u8 ucTerminalCountry[2];        //9F1A ���ն˹��Ҵ���
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���
	u8 ucMerchantNameLocation[40+1];//9F4E �̻����ƣ�ASC����0x00����
	u8 ucTransType;                 //9C   �������� һ��Ϊ0x00 ,����������0x09
	u8 ucATC[2];                    //9F36 ATC
}T_EMV_TRANS_LOG;

#ifndef MAX_RSA_MODULUS_LEN
#define MAX_RSA_MODULUS_LEN 248
typedef struct
{
    u16 unBits;                        //length in bits of modulus
    u8 ucModulus[MAX_RSA_MODULUS_LEN]; //modulus
    u8 ucExponent[3];                  //public exponent
}T_RSA_PUBLIC_KEY;

#endif

//�ֻ�оƬר��
typedef struct
{
    u8 ucCardName[20];              //������
    u8 ucCardNo[10];                //���� BCD,����Ϊ��ΪF
    u8 ucCardTrack2[20];            //���ŵ���Ϣ
    u8 ucCardTrack3[54];            //���ŵ���Ϣ
    u8 ucValidDate[2];              //��Ч��
    u8 ucRfu[2];
    u8 ucKey[8];                    //DF33 ������Կ
    u8 ucDateTime[7];               //DF34 �ն˶�ȡ�� BCD YYYYMMDDHHMMSS
    u8 ucChipSeq[10];               //DF32 оƬ���к�
}T_UPCARD;

//�������ش����붨��
#define EMV_OK                      0          //�ɹ�
#define ICC_CMD_ERR                 -1         //APDU����ʧ��
#define EMV_PARAM_ERR               -2         //EMV��������
#define ICC_BLOCK                   -3         //IC������
#define ICC_RSP_ERR                 -4         //APDU��Ӧ����
#define EMV_APP_BLOCK               -5         //Ӧ������
#define EMV_NO_APP                  -6         //��Ƭû���ն�֧�ֵ�Ӧ��
#define EMV_USER_CANCEL             -7         //����ȡ��
#define EMV_TIME_OUT                -8         //�û�������ʱ
#define EMV_DATA_ERR                -9         //��Ƭ���ݴ���
#define EMV_NOT_ACCEPT              -10        //���ײ�����
#define EMV_KEY_EXP                 -12        //��֤���Ĺ�Կ����Ч��
#define EMV_DATETIME_ERR            -13        //����ʱ�����
#define EMV_FILE_ERR                -14        //��дEMV�ļ�����
#define EMV_SUM_ERR                 -15        //��֤���Ĺ�ԿУ��ʧ��
#define EMV_NOT_FOUND               -16        //��EMV�ļ�û���ҵ���Ӧ�ļ�¼
#define EMV_DATA_AUTH_FAIL          -17        //�ѻ�������֤ʧ��
#define EMV_NOT_MATCH               -18        //�����ݲ�ƥ��(��2�ŵĿ�����Tag:5A���ŵ�)
#define EMV_NO_TRANS_LOG            -19        //�޽�����־
#define EMV_ONLINE_FAILED           -20        //�������ɹ�,��������ʧ��
#define EMV_NOT_ORG_ICC             -21        //���ǲ���������ԭʼ��
#define ICC_RSP_6985                -22        //GAC�п�Ƭ����6985, ��Ӧ�þ����Ƿ�fallback
#define EMV_EXCP_FILE               -23        //��Ƭ�������ն��쳣�ļ���
#define EMV_USE_CONTACT  		    -24        //��֧����������,��ʾ"��ʹ������������н���"����֧����������,��ʾ"������ֹ"
#define EMV_CARD_EXPIRED            -25        //��Ƭ����Ч��
#define EMV_TERMINATE    		    -26        //������ֹ
#define EMV_BALANCE_ERR    		    -27        //��ȡ���ʧ�ܣ���ʾ"������ֹ"
#define EMV_NOT_PAY    		        -28        //���������ۿ�δ�ɹ�
#define EMV_ALREADY_PAY    		    -29        //���������ۿ�ɹ�
#define EMV_BALANCE_NOT_ENOUGH    	-30        //����
#define EMV_DECLINE                 -31        //���׾ܾ�(���׽��Ϊ�ܾ�)
#define EMV_NO_PASSWORD             -32        //û�������δ��������
#define EMV_FANGBA                  -33        //��������
#define EMV_NO_PINPAD_OR_ERR        -34        //������̲����ڻ���������
#define EMV_NOT_QPBOC               -35        //��֧��QuickPass
#define EMV_NOT_SUPPORT             -36        //��֧�ָý���
#define ICC_RSP_6986                -37        //GPO����6986, ��ʾ�ֿ��˲����ֻ��������µ磬��1-1.5s��ʾ���»ӿ�
#define EMV_ONLINE_NORESP_MAC_OR_RECV_ERR  -38 //�������ɹ�,��������Ӧ�򷵻�MAC�����������ݴ���,����
#define EMV_NO_ONLINE               -39        //δ����
#define EMV_ONLINE_RESP_AAC         -40        //�����ɹ�,������Ȩ��Ӧ�뷵�ؾܾ�

//PayPass L1
#define ICC_TIME_OUT_ERROR          -60
#define ICC_TRANSMISSION_ERROR      -61
#define ICC_PROTOCOL_ERROR          -62

//PayPass L2
#define EMV_CARD_DATA_MISSING       -70
#define EMV_CAM_FAILED              -71
#define EMV_STATUS_BYTES            ICC_RSP_ERR
#define EMV_PARSING_ERROR           -73
#define EMV_MAX_LIMIT_EXCEEDED      -74
#define EMV_CARD_DATA_ERROR         EMV_DATA_ERR
#define EMV_MAGSTRIPE_NOT_SUPPORTED -76
#define EMV_NO_PPSE                 -77
#define EMV_PPSE_FAULT              -78
#define EMV_EMPTY_CANDIDATE_LIST    EMV_NO_APP
#define EMV_IDS_READ_ERROR          -80
#define EMV_IDS_WRITE_ERROR         -81
#define EMV_IDS_DATA_ERROR          -82
#define EMV_IDS_NO_MATCHING_AC      -83
#define EMV_TERMINAL_DATA_ERROR     -84

//PayPass L3
//#define EMV_TIME_OUT                -90 //�Ѷ���
#define EMV_STOP                    -91
#define EMV_AMOUNT_NOT_PRESENT      -92


/********************************************************************
��������: ���׻ص�����_��EMV����ǰ����(Ҳ�ɿ�����ʼ��ʱ����һ��)
�������:
�������:
�� �� ֵ: =0 �ɹ�
          <0 ���󣬴���ķ���ֵ��ʹ�ñ�ͷ�ļ������붨�壬����������ο��ص�����˵��
�޸���Ϣ: 2014-09-26  �޳�  ����
********************************************************************/
typedef struct
{
    //EMV��qPBOC���ûص�����
    s32 (*EmvCbGetAppListNum)(void);//�õ�IC����������(Ӧ���б�)����
    s32 (*EmvCbLoadAppListByIndex)(u32 uiIndex,T_EMV_APP_LIST *ptAppList);//���������ŵõ�IC����������(Ӧ���б�)

    s32 (*EmvCbGetCapkNum)(void);//�õ���֤���Ĺ�Կ��������
    s32 (*EmvCbLoadCapkByRIDCAPKIndex)(u8 *pucRID,u8 ucCAPKIndex,T_EMV_TERM_CAPK *ptTermCapk);//����RID�͹�Կ�����õ���֤���Ĺ�Կ����

    s32 (*EmvCbLoadRevocList)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertSerial);//����RID�͹�Կ�����õ���Կ�����б�=0�ҵ�

    s32 (*EmvCbExchangeApdu)(const u8 *pucSend,u32 uiSendLen,u8 *pucResp,u32 *puiRespLen);//����apdu,��Ӧapdu����
    s32 (*EmvCbGetRand)(u8 *pucRand,u8 ucLen); //��������̵õ�ָ���ֽڵ������
    s32 (*EmvCbSearchExceptionList)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//���Һ������������쳣�ļ���� =0�ҵ�

    //qPBOCר�ûص�����
    s32 (*EmvCbReSwipeCard)(void);// ��������,���»ӿ�
    s32 (*EmvCbControlLedAndBeep)(const u8 ucState);//����LED��BEEP = 0�������һ����¼֮��,=1�ѻ�������֤֮��

    //EMVר�ûص�����
    s32 (*EmvCbSelApp)(u8 ucIsFirstSelect,s8 *pcAppLabelList[], s32 iAppNum);//��ʾӦ�ñ�ǩ�б�Ҫ��ֿ���ѡ�� >= 1ѡ��Ӧ���б�����(��1��ʼ) <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbShowHint)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//��ʾ�ַ���ucStr;��ʾiDisplayTime�루�ɰ������������,iDisplayTime=0���ȴ�ֱ�ӷ��أ�iDisplayTime=-1�а����ŷ���
    s32 (*EmvCbInputPIN)(u8 ucPINType,u8 *pucICChallenge,T_RSA_PUBLIC_KEY *tPublicKey,u8 *pucOutPINBlock);//����PIN, ucPINType(�μ��궨��);pucICChallenge ��IC���õ��������,�����ѻ�����PIN;tPublicKey IC������PIN��Կ�������ѻ�����PIN;pucOutPINBlock:�õ���PINBLOCK
    s32 (*EmvCbCertVerify)(void);//�ֿ���֤����֤ =0�ɹ� <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbGetSumLogByPAN)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//�õ�һ�ſ�Ƭ�Ľ����ۼƽ������ж��ն�����޶�9f1b
    //s32 (*EmvCbOnlineProc)(u8 *pucRspCode,u8 *pucIAuthData,u32 *puiIAuthDataLen, u8 *pucscript71,u32 *puiScriptLen71,u8 *pucScript72,u32 *puiScriptLen72);//�������ͽ��գ�������Ӧ��55������,RspCodeΪ39��Ӧ����,>0ΪӦ�ò������
    s32 (*EmvCbReferProc)(void); //�����з�����Ȩ��Ӧ��(39��Ϊ01��02)��ʾ�ο�(��׼��ܾ�)
    s32 (*EmvCbAdviceProc)(void);//GAC֮��, ����֪ͨ

    //s32 (*EmvCbCardholderConfirm)(s8 *pcAppLabel);//�ֿ���ȷ����ʾ(���޸�ΪEmvCbMenuAppSel)��cAppLabelΪ��ʾ��Ӧ�ñ�ǩ������Ҫ��ʾΪ��
    //s32 (*EmvCbGetPreferenceLanguage)(u8 *pucLanguagePrefer,u8 ucLen);//���� 5F2d��ѡ����pucLanguagePrefer �õ��ն����õ����������±꣨0--���ģ�1--english��
}T_EMV_CALLBACK;

DLLAPI void sdkEmvSetCallBackFunc(T_EMV_CALLBACK *ptEmvCallback);//�ϲ�Ӧ�����ûص�������Emv�ں�(����ʱ��emv���׿�ʼǰ����һ��),ʹ�ں˿��Ե���

/********************************************************************
��������:
�������:
�������:
�� �� ֵ: =0 �ɹ�
          <0 ���󣬴���ķ���ֵ�μ���ͷ�ļ������붨�壬����������ο����庯��˵��
�޸���Ϣ: 2014-09-26  �޳�  ����
********************************************************************/

DLLAPI void sdkEmvKernelVersion(s8 *pcStrVer);//�õ�EMV�ں˰汾��
DLLAPI s32 sdkEmvVerifyCAPK(T_EMV_TERM_CAPK *ptTermCapk);//��֤���Ĺ�ԿУ��

//EMV����
DLLAPI s32 sdkEmvAppSelect(void);//Ӧ��ѡ��
DLLAPI s32 sdkEmvAppInit(void);//Ӧ�ó�ʼ��(GPO)
DLLAPI s32 sdkEmvReadAppData(void);//��Ӧ������
DLLAPI s32 sdkEmvOfflineDataAuth(void);//�ѻ�������֤
DLLAPI s32 sdkEmvProcessRestrictions(void);//��������
DLLAPI s32 sdkEmvCardholderVerification(void);//�ֿ�����֤
DLLAPI s32 sdkEmvTerminalRiskManagement(void);//�ն˷��չ���
DLLAPI s32 sdkEmvTerminalAndCardActionAnalysis(u8 *pucTransResult);//�ն���Ϊ����
DLLAPI s32 sdkEmvSeparateOnlineResp(u8 *pucAuthRespCode,u8 *pucIssuerResp,u32 uiIssuerRespLen);//����������Ӧ����,���pucAuthRespCode(8A,39��) == NULL��=="",����Ȩ��Ӧ��Ҫ������pucIssuerResp(��������Ӧ����,55��)��
DLLAPI s32 sdkEmvOnlineProcessing(s32 iOnlineRet,u8 *pucTransResult);//������Ӧ����,���׽���

//qPBOCר��
DLLAPI s32 sdkEmvQTransPreProc(u8 *pucAmountAuth);//����Ԥ�����ڷǽ�Ѱ��֮ǰִ��,ucAmountAuth :��Ȩ���(6Byte BCD)
DLLAPI s32 skdEmvQTrans(u8 *pucBalance,u8 *pucTransResult,u8 *pucCVMType);//QPBOC������������,�罻�׽��(pucTransResult)Ϊ�����������pucCVMTypeִ��CVM,pucBalanceΪ���׺�����(pucBalance[0]=0x01��ʾ9F5D������)
DLLAPI s32 sdkEmvQIssuerUpdateIsNeed(u8 *pucAuthRespCode,u8 *pucIssuerResp,u32 uiIssuerRespLen);
DLLAPI s32 sdkEmvQIssuerUpdateProcessing(void);
DLLAPI s32 sdkEmvQGetCVMType(void);//qPBOC���׽����󣬵õ��ֿ�����֤��ʽ
//DLLAPI s32 skdEmvQBalanceQuery(u8 *pucTransDate,u8 *pucBalance);//QPBOC����ѯBCD(6byte)��������,���:pucTransDate��������(BCD YYMMDD)������:pucBalance���(BCD 6byte)

//EMV��������
//DLLAPI s32 sdkEmvECBalanceQuery(u8 ucDoubleFlag,u8 *pucBalance1,u8 *pucBalance1code,u8 *pucBalance2,u8 *pucBalance2code);//�������̣�˫�ҵ����ֽ����BCD(6byte)��ѯ;ucDoubleFlag=2(˫��),=1(����);��ΪucDoubleFlag=2ʱ,��Ƭֻ��һ�ֱ�ʱ���᷵�ش��󣬵�pucBalance1,pucBalance1Code�᷵�أ�pucBalance2Code����"\x00\x00"
DLLAPI s32 sdkEmvBalanceQuery(u8 ucTransKernalType,u8 *pucBalance);//����ѯ��������
DLLAPI s32 sdkEmvReadPANProc(u8 ucTransKernalType,u8 *pucTransDate,u8 *pucStrTrack2,u8 *pucStrPAN);//��������,�ǽӶ����źͿ���,��ڽ�������(9A   �������� BCD YYMMDD)
DLLAPI s32 sdkEmvReadTransLog(u8 ucTransKernalType,u8 *pucRecordNum,T_EMV_TRANS_LOG *ptEmvTransLog); //��ȡ���н�����־��¼(��������) ,*pucRecordNum ��������־�ܼ�¼��,*tEmvTransLog :��������־�ṹ��������

//�õ�����EMV����
DLLAPI s32 sdkEmvGetData(u8 ucP1,u8 ucP2,u8 *pucLen,u8 *pucResp,u8 *pucStatus);//����get data apdu
DLLAPI void sdkEmvSetTransResult(u8 ucTransResult);//���ý��׽��
DLLAPI u8 sdkEmvGetTransResult(void);//�õ����׽��
DLLAPI s32 sdkEmvGetTVR(u8 *pucTVR);//�õ�TVR
DLLAPI s32 sdkEmvGetTSI(u8 *pucTSI);//�õ�TSI
DLLAPI s32 sdkEmvGetTLVData(u32 uiTag,u8 *pucDataOut,u32 *puiDataOutLen);//�õ�һ��tag������
DLLAPI s32 sdkEmvSetTLVData(u32 uiTag,u8 *pucDataIn,u32 uiDataInLen);//����һ��tag���ݵ���emv�ں�
DLLAPI s32 sdkEmvGetScriptResult(u8 *pucResult, u32 *puiResultLen);//�õ��ű�������
DLLAPI s32 sdkEmvGetTrack2AndPAN(u8 *pucStrTrack2,u8 *pucStrPAN);//��ȡ���ŵ���Ч����(ASC),���˺�(ASC)
DLLAPI s32 sdkEmvGetPAN(u8 *pucPAN,u32 *puiPANLen);//�õ����˺�(BCD,������'F'),���Tag5A�ò�������Tag57�еõ�
DLLAPI s32 sdkEmvGetBalance(u8 *pucBalance);//�õ�GAC���صĵ����ֽ�����qPBOC���׺�����,ucBalance[0] == 0x00Ϊ�ɹ�����
DLLAPI s32 sdkEmvGetCardFromTrack(u8 *pucCardNo,u8 *pucTrack2,u8 *pucTrack3); //�Ӵŵ���ȡ���� track2 2�ŵ����� track3 3�ŵ�����

DLLAPI void sdkRemoveTailChars(u8 *pucStr, u8 ucRemove);//ȥ���ַ���pStrδβָ�����ַ�(ucRemove),��ȥ������δβ��'F'
DLLAPI u8 *sdkEmvSeparateTLV(u8 *pucTLVData,u32 *puiTag,u32 *puiDataOutLen);//����tlv���ݣ��õ�������tlv����ָ�룬tag������
DLLAPI u32 sdkEmvPackageTLV(u32 uiTag,u8 *pucData,u32 uiDataLen,u8 *pucOutTLVData);//����Tag,Data,DataLen�����ΪTLV�ṹ������,����TLV�����ܳ�(��ֻ������(һ)�ֽ�Tag,����(����=0,>0xFF)��TAG)
DLLAPI s32 sdkEmvFindTLV(u8 *pucTLVData,u32 uiTLVDataLen,u32 uiTag,u8 *pucDataOut,u32 *puiDataOutLen);//����TLV���ݣ�����ָ����TAG������TAGֵ�ͳ������
DLLAPI s32 sdkFindTagFromTLVList(u32 uiTLVLen,u8 *ucTLV,u32 uiTag);  //����TLV�б�,����Tag,�ҵ�=0,δ�ҵ�=1
DLLAPI s32 sdkFindTagFromTLList(u32 uiTLListLen,u8 *ucTLList,u32 uiTag); //����TL�б�,����CDOL,PDOL,����Tag,�ҵ�=0,δ�ҵ�=1

DLLAPI s32 sdkEmvRSAPublicKeyDecrypt(u8 *ucOutput, u32 *uiOutputLen, u8 *ucInput, u32 uiInputLen, T_RSA_PUBLIC_KEY *tPublicKey);


//���ϲ�Ӧ�õõ�emv�ں˲���ָ��,ʹ���������
DLLAPI T_EMV_TERM_PARAM *sdkEmvGetTermParam(void);//�õ��ն˲���ָ��
DLLAPI T_EMV_TRANS_PARAM *sdkEmvGetTransParam(void);//�õ����ײ���ָ��

//�ֻ�оƬר��
DLLAPI s32 sdkReadUpCard(u8 *pucDataTime,T_UPCARD *ptUpCard);//���ֻ�оƬ������,ucDataTimeΪ��ǰʱ��(bcd YYYYMMDDHHMMSS)

//paypass
DLLAPI s32 sdkPaypassSelODAMethod(void);
DLLAPI s32 sdkPaypassTerminalRiskManagement(void);

#ifdef __cplusplus
	}
#endif

#endif

