/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <errno.h>
#include <linux/limits.h>
#include <stdio.h>

#include "alloc-util.h"
#include "fs-util.h"
#include "ro-etc-hack.h"
#include "string-util-fundamental.h"

const char* writable_filename(const char *path) {
        ssize_t r;
        static char realfile_buf[PATH_MAX];
        _cleanup_free_ char *realfile = NULL;
        const char *result = path;
        int orig_errno = errno;

        r = readlink_and_make_absolute(path, &realfile);
        if (r >= 0 && startswith(realfile, "/etc/writable")) {
                snprintf(realfile_buf, sizeof(realfile_buf), "%s", realfile);
                result = realfile_buf;
        }

        errno = orig_errno;
        return result;
}
