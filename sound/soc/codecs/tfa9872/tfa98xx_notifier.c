/*
 * sound/soc/codecs/tfa98xx_notifier.c
 *
 * Copyright (c) 2018, jollaman999 <admin@jollaman999>
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

#include <linux/notifier.h>
#include <linux/export.h>

static BLOCKING_NOTIFIER_HEAD(tfa98xx_notifier_list);

int tfa98xx_register_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&tfa98xx_notifier_list, nb);
}
EXPORT_SYMBOL(tfa98xx_register_client);

int tfa98xx_unregister_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&tfa98xx_notifier_list, nb);
}
EXPORT_SYMBOL(tfa98xx_unregister_client);

int tfa98xx_notifier_call_chain(unsigned long val, void *v)
{
	return blocking_notifier_call_chain(&tfa98xx_notifier_list, val, v);
}
EXPORT_SYMBOL_GPL(tfa98xx_notifier_call_chain);
