#pragma fragment CBK_TEMPLATE
int32_t
@FOP_PREFIX@_@NAME@_cbk (call_frame_t *frame, void *cookie, xlator_t *this,
        int32_t op_ret, int32_t op_errno, @UNWIND_PARAMS@)
{
        STACK_UNWIND_STRICT (@NAME@, frame, op_ret, op_errno,
                             @UNWIND_ARGS@);
        return 0;
}

#pragma fragment COMMENT
If you are generating the leaf xlators, remove the STACK_WIND
and replace the @ERROR_ARGS@ to @UNWIND_ARGS@ if necessary

#pragma fragment FOP_TEMPLATE
int32_t
@FOP_PREFIX@_@NAME@ (call_frame_t *frame, xlator_t *this,
        @WIND_PARAMS@)
{
        STACK_WIND (frame, @FOP_PREFIX@_@NAME@_cbk,
                    FIRST_CHILD(this), FIRST_CHILD(this)->fops->@NAME@,
                    @WIND_ARGS@);
        return 0;
err:
        STACK_UNWIND_STRICT (@NAME@, frame, -1, errno,
                             @ERROR_ARGS@);
        return 0;
}

#pragma fragment FUNC_TEMPLATE
@RET_TYPE@
@FOP_PREFIX@_@NAME@ (@FUNC_PARAMS@)
{
        return @RET_VAR@;
}

#pragma fragment CP
/*
 *   Copyright (c) @CURRENT_YEAR@ Red Hat, Inc. <http://www.redhat.com>
 *   This file is part of GlusterFS.
 *
 *   This file is licensed to you under your choice of the GNU Lesser
 *   General Public License, version 3 or any later version (LGPLv3 or
 *   later), or the GNU General Public License, version 2 (GPLv2), in all
 *   cases as published by the Free Software Foundation.
 */

#pragma fragment INCLUDE_IN_SRC_FILE
#include "@XL_NAME@.h"

#pragma fragment XLATOR_METHODS

static int32_t
@FOP_PREFIX@_init (xlator_t *this)
{
        return 0;
}

static void
@FOP_PREFIX@_fini (xlator_t *this)
{
        return;
}

static int32_t
@FOP_PREFIX@_reconfigure (xlator_t *this, dict_t *dict)
{
        return 0;
}

static int
@FOP_PREFIX@_notify (xlator_t *this, int event, void *data, ...)
{
        return default_notify (this, event, data);
}

static int32_t
@FOP_PREFIX@_mem_acct_init (xlator_t *this)
{
        int     ret = -1;

        ret = xlator_mem_acct_init (this, gf_@FOP_PREFIX@_mt_end + 1);
        return ret;
}

static int32_t
@FOP_PREFIX@_dump_metrics (xlator_t *this, int fd)
{
        return 0;
}

struct volume_options @FOP_PREFIX@_options[] = {
        /*{ .key  = {""},
          .type = GF_OPTION_TYPE_BOOL,
          .default_value = "",
          .op_version = {GD_OP_VERSION_},
          .flags = OPT_FLAG_SETTABLE | OPT_FLAG_DOC | OPT_FLAG_CLIENT_OPT,
          .tags = {""},
          .description = "",
          .category = GF_EXPERIMENTAL,
        },
        { .key = {NULL} },
        */
};

xlator_api_t xlator_api = {
        .init          = @FOP_PREFIX@_init,
        .fini          = @FOP_PREFIX@_fini,
        .notify        = @FOP_PREFIX@_notify,
        .reconfigure   = @FOP_PREFIX@_reconfigure,
        .mem_acct_init = @FOP_PREFIX@_mem_acct_init,
        .dump_metrics  = @FOP_PREFIX@_dump_metrics,
        .op_version    = {GD_OP_VERSION_},
        .dumpops       = &@FOP_PREFIX@_dumpops,
        .fops          = &@FOP_PREFIX@_fops,
        .cbks          = &@FOP_PREFIX@_cbks,
        .options       = @FOP_PREFIX@_options,
        .identifier    = "@XL_NAME@",
        .category      = GF_EXPERIMENTAL,
};
#pragma fragment HEADER_FMT
#ifndef __@HFL_NAME@_H__
#define __@HFL_NAME@_H__

#include "@XL_NAME@-mem-types.h"
#include "@XL_NAME@-messages.h"
#include "glusterfs.h"
#include "xlator.h"
#include "defaults.h"

#endif /* __@HFL_NAME@_H__ */

#pragma fragment MEM_HEADER_FMT
#ifndef __@HFL_NAME@_H__
#define __@HFL_NAME@_H__

#include "mem-types.h"

enum gf_mdc_mem_types_ {
        gf_@FOP_PREFIX@_mt_   = gf_common_mt_end + 1,
        gf_@FOP_PREFIX@_mt_end
};

#endif /* __@HFL_NAME@_H__ */

#pragma fragment MSG_HEADER_FMT
#ifndef __@HFL_NAME@_H__
#define __@HFL_NAME@_H__

#include "glfs-message-id.h"

/* To add new message IDs, append new identifiers at the end of the list.
 *
 * Never remove a message ID. If it's not used anymore, you can rename it or
 * leave it as it is, but not delete it. This is to prevent reutilization of
 * IDs by other messages.
 *
 * The component name must match one of the entries defined in
 * glfs-message-id.h.
 */

GLFS_MSGID(@FOP_PREFIX@,
        @FOP_PREFIX@_MSG_NO_MEMORY
);

#endif /* __@HFL_NAME@_H__ */
