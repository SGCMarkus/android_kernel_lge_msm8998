/*
 * include/linux/input/tfa98xx_notifier.h
 *
 * Copyright (c) 2018, jollaman999 <admin@jollaman999.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _LINUX_TFA98XX_NOTIFIER_H
#define _LINUX_TFA98XX_NOTIFIER_H

#include <linux/notifier.h>

#define TFA98XX_EVENT_PLAYING		0x01
#define TFA98XX_EVENT_STOPPED		0x02

int tfa98xx_register_client(struct notifier_block *nb);
int tfa98xx_unregister_client(struct notifier_block *nb);
int tfa98xx_notifier_call_chain(unsigned long val, void *v);

#endif /* _LINUX_TFA98XX_NOTIFIER_H */
