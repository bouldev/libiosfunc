

#ifndef __XPCPRIVATE__
#define __XPCPRIVATE__

#include <xpc/xpc.h>

#define XPC_ENV_SANDBOX_CONTAINER_ID "APP_SANDBOX_CONTAINER_ID"

typedef struct os_log_pack_s {
    uint64_t        olp_continuous_time;
    struct timespec olp_wall_time;
    const void     *olp_mh;
    const void     *olp_pc;
    const char     *olp_format;
    uint8_t         olp_data[0];
} os_log_pack_s, *os_log_pack_t;
typedef struct _xpc_pipe_s* xpc_pipe_t;

extern xpc_object_t xpc_connection_copy_entitlement_value(xpc_connection_t connection, const char *entitlement);

extern int _xpc_runtime_is_app_sandboxed();

extern void xpc_connection_set_target_uid(xpc_connection_t connection, uid_t uid);

extern void xpc_dictionary_set_mach_send(xpc_object_t message, char *name, mach_port_t bootstrap);

extern xpc_object_t xpc_create_from_plist(const void *data, size_t size);

extern xpc_object_t xpc_copy_entitlements_for_pid(pid_t pid);

extern xpc_pipe_t xpc_pipe_create(const char *name, uint64_t flags);

extern int xpc_pipe_routine(xpc_pipe_t pipe, xpc_object_t message, xpc_object_t *reply);

#endif
