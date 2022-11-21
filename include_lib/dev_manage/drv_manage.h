#ifndef __DRV_MANAGE_AC46_H__
#define __DRV_MANAGE_AC46_H__

#include "dev_manage/device_driver.h"
#include "common/list.h"

#define DEV_ACTIVE        0x55aa55bb
#define DEV_UNACTIVE      0xaa5555bb
#define DEV_DETECT        0xbb55cc55

#define IO2USB	BIT(0)
#define IO2SD0	BIT(1)

typedef struct dev_list_t
{
    const dev_io_t *dev_io;           ///<�豸�����ӿ�
    u32 dev_status;                   ///<�豸״̬
    u32 total_lg_dev;                 ///<�߼��豸����
    u32 *seek_list;;            ///<�߼�����ƫ���б�
    struct list_head entry;
}DEV_LIST_T;

typedef DEV_LIST_T* DEV_HANDLE;

extern DEV_HANDLE volatile sd0;        ///>�豸���
extern DEV_HANDLE volatile sd1;        ///>�豸���
extern DEV_HANDLE volatile usb;        ///>�豸���
extern DEV_HANDLE volatile cache;        ///>�豸���

#define DEVICE_REG(dev,parm) dev_register(dev_reg_##dev((parm)))

u32 dev_init(u32 devcheckprio,u32 devmountprio,void (* fun)(u32 p));
DEV_HANDLE dev_open(const char *name, void *pram);
u32 dev_read(DEV_HANDLE hdev, u8 *buf, u32 addr, u32 len);
u32 dev_write(DEV_HANDLE hdev, u8 *buf, u32 addr, u32 len);
u32 dev_get_lg_seek(DEV_HANDLE hdev,u32 snum);
u32 dev_get_online_status(void * parm);
u32 get_phydev_total();
u32 get_phydev_type(void *parm);
u32 dev_register(const dev_io_t * dev_io);
void phy_dev_list_init(void);
char * get_phydev_name(void *parm);

u8 usb_sd_mult_init(void);
u8 usb_sd_mult_pend(void);
u8 usb_sd_mult_post(void);

void io_2_sd0(void);
void io_2_usb(void);
void io_clean(void);
u8 get_io_status(void);

#endif
