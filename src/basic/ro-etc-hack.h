/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Hack for Ubuntu phone: check if path is an existing symlink to
 * /etc/writable; if it is, update that instead */
const char *writable_filename(const char *path);
