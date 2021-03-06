/*
 * Driver for ISX012 (5MP camera) from Sony
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#define DEFAULT_PIX_FMT		V4L2_PIX_FMT_UYVY	/* YUV422 */
#define DEFAULT_MCLK		24000000
#define ISX012_STREAMOFF_DELAY	120


enum {
	ISX012_FLASH_MODE_NORMAL,
	ISX012_FLASH_MODE_MOVIE,
	ISX012_FLASH_MODE_MAX,
};

enum {
	ISX012_FLASH_OFF = 0,
	ISX012_FLASH_ON = 1,
};

/* Define debug level */
#define CAMDBG_LEVEL_ERR		(1 << 0)
#define CAMDBG_LEVEL_WARN		(1 << 1)
#define CAMDBG_LEVEL_INFO		(1 << 2)
#define CAMDBG_LEVEL_DEBUG		(1 << 3)
#define CAMDBG_LEVEL_TRACE		(1 << 4)
#define CAMDBG_LEVEL_DEFAULT	\
	(CAMDBG_LEVEL_ERR | CAMDBG_LEVEL_WARN | CAMDBG_LEVEL_INFO)

struct isx012_platform_data {
	u32 default_width;
	u32 default_height;
	u32 pixelformat;
	u32 freq;	/* MCLK in Hz */

	/* This SoC supports Parallel & CSI-2 */
	u32 is_mipi;		/* set to 1 if mipi */
	s32 streamoff_delay;	/* ms, type is signed */

	/* ISP interrupt */
	/* int (*config_isp_irq)(void);*/

	#define ISX012_SUPPORT_FLASH
	int (*flash_en)(u32 mode, u32 onoff);
	int (*is_flash_on)(void);

	int (*stby_on)(bool);

	u8 dbg_level;
};

