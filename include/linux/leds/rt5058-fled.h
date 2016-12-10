/*  include/linux/leds/rt5058-fled.h
 *  Include header file for Richtek RT5058 FLED file
 *
 *  Copyright (C) 2015 Richtek Technology Corp.
 *  Jeff Chang <jeff_chang@richtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#ifndef __LINUX_RT5058_FLED_H
#define __LINUX_RT5058_FLED_H

#define RT5058_FLED_USE_NESTED_IRQ	(0)

#define RT5058_RSTFLS_MASK	0x20

#define RT5058_FLEDMODE_MASK	0x01
#define RT5058_FLED_ALLEN_MASK	0x01
#define RT5058_FLED1EN_MASK	0x02
#define RT5058_FLED2EN_MASK	0x04

#define RT5058_FLED1STRB_MASK	0x20
#define RT5058_FLED2STRB_MASK	0x10
#define RT5058_TORCHCUR_MASK	0x0f
#define RT5058_STRBCUR_MASK	0x3f
#define RT5058_STRBTIMEOUT_MASK	0x3f
#define RT5058_TIMEOUT_MASK	0x70
#define RT5058_FLED_IRQMASK	0x40

#define RT5058_FLED_FLASH_MASK	0x30

#define RT5058_TIMEOUT_SHIFT	4


#define RT5058_FLED0		RT5058_REG_FLED1CTRL
#define RT5058_FLED1		RT5058_REG_FLED2CTRL
#define RT5058_ENBIT0		(0x02)
#define RT5058_ENBIT1		(0x04)
#define RT5058_STRBBIT0		(0x20)
#define RT5058_STRBBIT1		(0x10)
#define RT5058_TORCUR0		RT5058_REG_FLED1TORCTRL
#define RT5058_TORCUR1		RT5058_REG_FLED2TORCTRL
#define RT5058_STRBCUR0		0x44
#define RT5058_STRBCUR1		0x48
#define RT5058_FLEDTIMEOUT0	RT5058_REG_FLED1CTRL
#define RT5058_FLEDTIMEOUT1	RT5058_REG_FLED2CTRL
#define RT5058_STRBTIMEOUT0	RT5058_REG_FLED1STRBCTRL1
#define RT5058_STRBTIMEOUT1	RT5058_REG_FLED2STRBCTRL1

#define RT5058_MIN_TOR		(12500)
#define RT5058_MIN_STRB		(50000)
#define RT5058_MIN_TIMEOUT	(50000)
#define RT5058_MIN_STRBTO	(64) /*ms*/
#define RT5058_TOR_STEP		(12500)
#define RT5058_STRB_STEP	(25000)
#define RT5058_TIMEOUT_STEP	(25000)
#define RT5058_STRBTO_STEP	(32) /*ms*/
#define RT5058_TOR_SIZE		(16)
#define RT5058_STRB_SIZE	(39)
#define RT5058_TIMEOUT_SIZE	(7)
#define RT5058_STRBTO_SIZE	(37)

#define RT5058_FLED_PIN_CTRL	(0x01)

#define RT5058_STRBCUR_MAX		(1000)
#define RT5058_TORCHCUR_MAX		(200)
#define RT5058_TIMEOUT_CURRENT_LVLMAX	(200)
#define RT5058_STROBE_TIMEOUT_MAX	(1216)

enum {
	RT5058_FLED_1,
	RT5058_FLED_2,
	RT5058_FLED_MAX,
};

struct rt5058_fled_platform_data {
	u8 irq_mask[2];
	u8 control_mode:1;
	u8 torch1_en:1;
	u8 torch2_en:1;
	u8 flash1_en:1;
	u8 flash2_en:1;
};

enum {
	RT5058_FLED_OFF,
	RT5058_FLED_TORCH,
	RT5058_FLED_STROBE,
};

enum {
	FLED_I2C_CONTROL,
	FLED_PIN_CONTROL,
};

enum {
	FLEDEVENT_STRBPIN,
	FLEDEVENT_TORPIN,
	FLEDEVENT_TX,
	FLEDEVENT_LVF,
	FLEDEVENT_LED2SHORT = 6,
	FLEDEVENT_LED1SHORT,
	FLEDEVENT_LED2STRB,
	FLEDEVENT_LED1STRB,
	FLEDEVENT_LED2STRBTO,
	FLEDEVENT_LED1STRBTO,
	FLEDEVENT_LED2TOR,
	FLEDEVENT_LED1TOR,
	FLEDEVENT_MAX,
};

#endif /* __LINUX_RT5058_FLED_H */