/*
 * include/linux/input/scroff_volctr.h
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

#ifndef _LINUX_SCROFF_VOLCTR_H
#define _LINUX_SCROFF_VOLCTR_H

#define SOVC_TOUCH_OFF_DELAY	5000	// Touch off delay time (ms)

extern int sovc_switch;
extern int sovc_tmp_onoff;
extern bool track_changed;
extern bool sovc_scr_suspended;

extern int sovc_ignore_start_y;
extern int sovc_ignore_end_y;
extern bool sovc_ignore;

extern bool es9218p_playing;
extern bool tfa9872_playing;
extern bool sovc_tmp_userspace_playing;

extern bool registered;

extern struct mutex sovc_playing_state_lock;

extern void unregister_sovc(void);

extern bool sovc_hifi_mode;
extern bool sovc_state_playing(void);

extern unsigned int calc_feather(int coord, int prev_coord);

#endif /* _LINUX_SCROFF_VOLCTR_H */
