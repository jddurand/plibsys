/*
 * Copyright (C) 2013 Alexander Saprykin <xelfium@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 */

#if !defined (__PLIB_H_INSIDE__) && !defined (PLIB_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plib.h> instead."
#endif

#ifndef __PLIBPRIVATE_H__
#define __PLIBPRIVATE_H__

#include <pmacros.h>
#include <ptypes.h>

P_BEGIN_DECLS

#ifndef P_OS_WIN
/**
 * @brief Gets temporary directory on UNIX systems.
 * @return Temporary directory.
 * @since 0.0.1
 */
pchar *	__p_ipc_unix_get_temp_dir	(void);


/* Create file for System V IPC, if needed
 * Returns: -1 = error, 0 = file successfully created, 1 = file already exists */
/**
 * @brief Creates file for System V IPC usage.
 * @param file_name File name to create.
 * @return -1 in case of error, 0 if all was OK, and 1 if file already exists.
 * @since 0.0.1
 */
pint	__p_ipc_unix_create_key_file	(const pchar *file_name);

/**
 * @brief Wrapps ftok() UNIX call for uniquer IPC key.
 * @param file_name File name for ftok() call.
 * @return Key in case of success, -1 otherwise.
 * @since 0.0.1
 */
pint	__p_ipc_unix_get_ftok_key	(const pchar *file_name);
#endif /* !P_OS_WIN */

/**
 * @brief Generates platform-independent key for IPC usage, object name for Windows and
 * file name to use with ftok () for UNIX-like systems.
 * @param name Object name.
 * @param posix TRUE if key will be used for POSIX IPC callc, otherwise FALSE. This
 * parameter is not used on Windows platform.
 * @return Platform-independent key for IPC usage.
 * @since 0.0.1
 */
pchar *	__p_ipc_get_platform_key	(const pchar *name, pboolean posix);

P_END_DECLS

#endif /* __PLIBPRIVATE_H__ */