/*********************************************************************************************
    *   Filename        : sdk_cfg.h

    *   Description     : Config for Sound Box Case

    *   Author          : Bingquan

    *   Email           : bingquan_cai@zh-jieli.com

    *   Last modifiled  : 2016-12-01 15:36

    *   Copyright:(c)JIELI  2011-2016  @ , All Rights Reserved.
*********************************************************************************************/

#ifndef _CONFIG_
#define _CONFIG_

#include "includes.h"


///�����ջ��С���ò���
#define VM_TASK_STACK_SIZE          (1024 * 1)
#define MAIN_TASK_STACK_SIZE        (1024 * 2) //(1024 * 1)����
#define MUSIC_TASK_STACK_SIZE       (1024 * 4)
#define MUSIC_PHY_TASK_STACK_SIZE   (1024 * 4)
#define TONE_TASK_STACK_SIZE        (1024 * 4)
#define TONE_PHY_TASK_STACK_SIZE    (1024 * 2)
#define UI_TASK_STACK_SIZE          (1024 * 2)

//���ö���
///< ��������ʹ��,������ʱ�����Ų�sd\��u.fm,rtc.ble,��̨��app,ֻ֧��linein.
#define    BT_STEREO                     0   
///����ӻ������Ƿ���뱻���ӻ��ǻ���״̬
#define    STEREO_SLAVE_WAIT_CON         1  
///���������Ƿ�һ��ػ�
#define    BT_STEREO_POWEROFF_TOGETHER   0 

/********************************************************************************/
/*
 *          --------����������
 */
////<����ϵͳ��ӡ���Թ���
 //#define __DEBUG         

///<LEDָʾʹ��
#define LED_EN                  1       
///<��������
#define UART_UPDATA_EN          0      
///<�������
#define SYS_LVD_EN              1       

#if (BT_STEREO == 1)
   #define BT_KTV_EN			0
#else
///<����K�豦
#define BT_KTV_EN				0
#endif
///<Х������
#define HOWLING_SUPPRESSION_EN	0

/********************************************************************************/

/********************************************************************************/
/*
 *           --------�ֻ�app���� ���� 
 */
#if (BT_STEREO == 1)
   #define SUPPORT_APP_RCSP_EN    0 
   #define RCSP_LIGHT_HW	      0	
#else
///�����Ƿ�֧���ֻ�app���ܣ�  (1-֧��,0-��֧��)
   #define SUPPORT_APP_RCSP_EN   0 
///�����Ƿ�֧��������Ӳ������ (1-֧��,0-��֧��)
   #define RCSP_LIGHT_HW	     0	
#endif

/********************************************************************************/

/********************************************************************************/
/*
 *           --------��Դ������
 */
///   0:  no change   
#define    PWR_NO_CHANGE        0     
///   1:  LDOIN 5v -> VDDIO 3.3v -> DVDD 1.2v
#define    PWR_LDO33            1     
///   2:  LDOIN 5v -> LDO   1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_LDO15            2     
///   3:  LDOIN 5v -> DCDC  1.5v -> DVDD 1.2v, support bluetooth
#define    PWR_DCDC15           3     

///��ѡ���ã�PWR_NO_CHANGE/PWR_LDO33/PWR_LDO15/PWR_DCDC15
#define PWR_MODE_SELECT         PWR_LDO15

///����Ƿ�ػ�
#define CHARGE_POWER_OFF 	    0               
///�����������Զ��ػ���ʱ��u16���ͣ�0��ʾ���Զ��ػ�
#define AUTO_SHUT_DOWN_TIME     1200               

///<����˫������
#define KEY_DOUBLE_CLICK        1  
/********************************************************************************/

/********************************************************************************/
/*
 *           --------��Ч������
 */
///<EQģ�鿪��
#define EQ_EN			        0  
//���EQ,��1��������0�رգ���ϵͳʱ��Ҫ��ߣ�һ��Ҫ192M��
//�����󲻼�����ǰ��eq�ļ������µ�EQ���ߣ�ע��eq�ļ�����Ϊ"cfg_eq.bin"
//�������eq�ٶ�Ҫ��ߣ���֧�������ʽ����֧�ֶ���
#if (BT_STEREO == 1)
	#define USE_SOFTWARE_EQ   		0   
#else
	#define USE_SOFTWARE_EQ   		0   
#endif
///<EQ uart online debug
#define EQ_UART_BDG	    		0       
///<dac�����ϲ�
#define DAC_SOUNDTRACK_COMPOUND 0       
///<�Զ�mute
#if BT_KTV_EN
	#define DAC_AUTO_MUTE_EN		0       
#else
	#define DAC_AUTO_MUTE_EN		0       
#endif
///<������
#define KEY_TONE_EN     	    1       
///<��0��ʾʹ��Ĭ������
#define SYS_DEFAULT_VOL         23
///<��������
#define VOCAL_REMOVER			0


/********************************************************************************/


/********************************************************************************/
/*
 *           --------DAC VCOMO ����
 */
///�Ƿ�ѡ��VCMOֱ�ƶ���
#define VCOMO_EN 	            0	
///��ѡ���ã�DAC_L_R_CHANNEL/DAC_L_CHANNEL/DAC_R_CHANNEL  
#define DAC_CHANNEL_SLECT       DAC_L_R_CHANNEL

/********************************************************************************/

/********************************************************************************/
/*
 *           --------����������
 */
 #if (BT_STEREO == 1)
	#define SDMMC0_EN           0
	#define SDMMC1_EN           0
	#define USB_DISK_EN         0
	#define USB_PC_EN           0
#else
    #define SDMMC0_EN           1
	#define SDMMC1_EN           0
	#define USB_DISK_EN         1
	#define USB_PC_EN           1
#endif

//usb_sd���Ÿ��ã���Ҫ���Լ�����
#define USB_SD0_MULT_EN     0	//<��Ҫ���Լ�����
#define USB_SD1_MULT_EN		0	//<��Ҫ���Լ�����

#if(USB_SD0_MULT_EN == 1)||(USB_SD1_MULT_EN == 1)
	#undef USB_PC_EN
	#define USB_PC_EN       0
#endif

/********************************************************************************/

/********************************************************************************/
/*
 *           --------����������
 */
#include "bluetooth/bluetooth_api.h"

#define NFC_EN          0  ///<NFC ENABLE

///��ѡ���ã�NORMAL_MODE/TEST_BQB_MODE/TEST_FCC_MODE/TEST_FRE_OFF_MODE/TEST_BOX_MODE
#define BT_MODE             NORMAL_MODE

#if (BT_MODE == TEST_FCC_MODE)
  #undef UART_UPDATA_EN
  #define UART_UPDATA_EN    0
#endif

///ģ������
#define BT_ANALOG_CFG       0
#define BT_XOSC             0//

///<������̨
#if (SUPPORT_APP_RCSP_EN == 1)
#define BT_BACKMODE         1             
#else
#define BT_BACKMODE         0             
#endif
///dependency
#if (BT_BACKMODE == 0)
    ///<HID���յĶ���ģʽֻ֧�ַǺ�̨
    #define BT_HID_INDEPENDENT_MODE  0    
#endif

///<���籨��
#define BT_PHONE_NUMBER     1          


/*
 *           --------�����͹������� 
 */
///��ѡ���ã�SNIFF_EN/SNIFF_TOW_CONN_ENTER_POWERDOWN_EN
#define SNIFF_MODE_CONF     0//SNIFF_EN 

///��ѡ���ã�BT_POWER_DOWN_EN/BT_POWER_OFF_EN
#define BT_LOW_POWER_MODE   0//BT_POWER_DOWN_EN

#define BT_OSC              0
#define RTC_OSCH            1
#define RTC_OSCL            2

///��ѡ���ã�BT_OSC/RTC_OSCH/RTC_OSCL
#define LOWPOWER_OSC_TYPE   BT_OSC

///��ѡ���ã�32768L//24000000L
#define LOWPOWER_OSC_HZ     24000000L



///��ѡ���ã�BT_BREDR_EN/BT_BLE_EN/(BT_BREDR_EN|BT_BLE_EN)
#if (BT_STEREO == 1)
	#define BLE_BREDR_MODE      (BT_BREDR_EN)
#elif (BT_KTV_EN == 1)
	#define BLE_BREDR_MODE      (BT_BREDR_EN)
#else
    #define BLE_BREDR_MODE      (BT_BREDR_EN)//(BT_BREDR_EN|BT_BLE_EN)
#endif 


/********************************************************************************/

/********************************************************************************/
/*
 *           --------оƬ��װ���� 
 */
///RTCVDD��û�а����Ҫ��1,Ŀǰ��Ӧ��װоƬAC6905
#define RTCVDD_TYPE              0          
#define BTAVDD_TYPE              0          

/********************************************************************************/


/********************************************************************************/
/*
 *           --------MUSIC MACRO
 */
//SMP�����ļ�֧��
#define MUSIC_DECRYPT_EN 		0	
//AB�ϵ�֧��
#define MUSIC_AB_RPT_EN 		0	

///<MP3
#define DEC_TYPE_MP3_ENABLE     1
///<SBC
#define DEC_TYPE_SBC_ENABLE     1
///<AAC
#define DEC_TYPE_AAC_ENABLE		0

///<3K_code_space
#define DEC_TYPE_WAV_ENABLE     1
///<5K_code_space
#define DEC_TYPE_FLAC_ENABLE    1
///<8K_code_space
#define DEC_TYPE_APE_ENABLE     1
///<30K_code_space
#define DEC_TYPE_WMA_ENABLE     1
///<30K_code_space
#define DEC_TYPE_F1A_ENABLE     0

/********************************************************************************/


/********************************************************************************/
/*
 *           --------FM MACRO
 */
///<��׼SDK
#if (BT_STEREO == 1)
	#define FM_RADIO_EN         0 
#else
    #define FM_RADIO_EN         1
#endif 
      
///dependency
#if (FM_RADIO_EN == 1)
    ///<RDA5807FM
    #define RDA5807                 0       
    ///<BK1080FM
    #define BK1080                  0       
    ///<QN8035FM
    #define QN8035                  0       
    ///<оƬ�ڲ�FM
    #define FM_INSIDE               1       
#endif

/********************************************************************************/

/********************************************************************************/
/*
 *           --------RTC MACRO
 */
///<��׼SDK RTCʱ��ģʽ
 #if (BT_STEREO == 1)
    #define RTC_CLK_EN          0       
#else
    #define RTC_CLK_EN          0       
#endif
///dependency
#if (RTC_CLK_EN == 1)
    ///<RTC����ģʽ
    #define RTC_ALM_EN          1       
#endif

/********************************************************************************/

/********************************************************************************/
/*
 *           --------ECHO MACRO
 *			�������죬����ر�	DAC_AUTO_MUTE_EN
 */
///dependency
#if (BT_BACKMODE == 1)
    ///<��֧����������̨��������
    #define ECHO_EN             0       
    ///<����ģʽ ��׼SDK
    #define ECHO_TASK_EN        0       
#else
	#if BT_KTV_EN
    	///<���칦�� KTV_SDK
    	#define ECHO_EN             1
	#else
    	///<���칦�� ��׼SDK
    	#define ECHO_EN             0
	#endif

    ///<����ģʽ ��׼SDK
    #define ECHO_TASK_EN        0       
#endif

/********************************************************************************/

/********************************************************************************/
/*
 *           --------REC MACRO
 */
///dependency
#if (BT_BACKMODE == 1)
    ///<��֧����������̨����¼��
    #define REC_EN             0    
#else
    ///<��׼SDK¼������
    #define REC_EN             0    
#endif

#if (REC_EN == 1)
    ///<����¼��ʹ��
	#define BT_REC_EN		1       
    ///<MIC¼��ʹ��
	#define MIC_REC_EN		1       
    ///<FM¼��ʹ��
	#define FM_REC_EN		1       
    ///<AUX¼��ʹ��
	#define AUX_REC_EN		1       
#endif
/*******************************zhgq2016-10-31**********************************/
#define PA_EN                   1    ///<����mute����
#if PA_EN
#define UMUTE()             	JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT &= ~BIT(4);
#define MUTE()            JL_PORTC->DIR &= ~BIT(4);JL_PORTC->OUT |= BIT(4);
#endif

#define AB_D_EN                 1    //����ABD��ʹ��
#if AB_D_EN
#define ABD_IO_INIT()   {JL_PORTC->PU &= ~BIT(5);JL_PORTC->PD &= ~BIT(5);JL_PORTC->DIR &= ~BIT(5);}
#define ABD_HIGH()		JL_PORTC->OUT |= BIT(5);
#define ABD_LOW()		JL_PORTC->OUT &= ~BIT(5);
#endif

#define JL_SDK                 0       ///���ﰴ��
#define PHONE_CHECK_EN          0     //�������1��Ч
#define AUX_IO_DET              0     //AUX IO  DET
#define AUX_AD_DET              1     //AD���AUX
#define AUX_PHONE_ADDET         0     //AUX/PHONE  adk���
//#define POWER_VOICE                            //������ʾ��
#define MUSIC_USB_SD_VOICE         //MUSIC ģʽSD_USB  ��ʾ��ʹ��
//#define SYS_POWER_KEY_EN      ///���ػ�
#define RESTRICT_NOTICE_VOL

#define  MAX_VOL_VOICE          1     //���������ʾ��
#define MUSIC_LED_PLAYONE_FLASH
/*****************SD0  �����������FM  ***********************/
//#define SD0_IIC_MULT_EN

//#define ADK_VOL_EN    ///��λ��������
#ifdef ADK_VOL_EN
#define mainVOL_step			8
#endif

//#define CODER_WHELL ///����������
#ifdef CODER_WHELL
#define     CODER_INIT()        JL_PORTC->DIE|=(BIT(10)|BIT(11));JL_PORTC->DIR|=(BIT(10)|BIT(11));JL_PORTC->PU|=(BIT(10)|BIT(11))
#define     CODER_READ_LEFT()   (JL_PORTC->&BIT(10))
#define     CODER_READ_RIGHT()  (JL_PORTC->&BIT(11))
#endif

//#define MEMERY_MODE	//MODE���书��
#ifdef MEMERY_MODE
#define  BLUE_MODE     0
#define  MUSIC_MODE    1
#if FM_RADIO_EN
#define  FM_MODE       2
#endif
#define  AUX_MODE      3
#define  PC_MODE       4
#endif
/********************************************************************************/

/********************************************************************************/
/*
 *           --------UI MACRO
 */
///<UI_��ʾ
#if (RCSP_LIGHT_HW == 1)
#define UI_ENABLE                0     
#else
#define UI_ENABLE                0     
#endif
///dependency
#if (UI_ENABLE == 1)
    #define LCD_128X64_EN        0      ///<lcd ֧��
    #define LED_7_EN             0      ///<led ֧��
	#define LCD_SEG_EN			 0	///<LCD֧��
#else
    ///����֧��
    #define LCD_128X64_EN        0
    #define LED_7_EN             0
#endif
#if ((LCD_128X64_EN == 1) && (LED_7_EN == 1)&&(LCD_SEG_EN == 1))
#error  "UI driver support only one"
#endif

#if (LCD_128X64_EN == 1)
    ///�˵���ʾ
    #define LCD_SUPPORT_MENU     1       
    ///LRC�����ʾ
    #define LRC_LYRICS_EN        1       
#else
    #define LCD_SUPPORT_MENU     0
    #define LRC_LYRICS_EN        0
#endif

/********************************************************************************/

 #if (BT_STEREO == 1)
///<��������ʹ��,������ʱ�����Ų�sd\��u.fm,rtc.ble,��̨��app.
  #if ((SDMMC0_EN) || (SDMMC0_EN)||(USB_DISK_EN)||(USB_PC_EN)||(BT_KTV_EN)||(FM_RADIO_EN)||(SUPPORT_APP_RCSP_EN)||(RTC_CLK_EN)||(BLE_BREDR_MODE&BT_BLE_EN))
  #error  "-------stereo not support this config ,please check sdk_cfg.h------------"
  #endif
#endif

#endif
