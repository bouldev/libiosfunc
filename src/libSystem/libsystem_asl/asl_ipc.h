#ifndef	_asl_ipc_user_
#define	_asl_ipc_user_

/* Module asl_ipc */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>
	
/* BEGIN VOUCHER CODE */

#ifndef KERNEL
#if defined(__has_include)
#if __has_include(<mach/mig_voucher_support.h>)
#ifndef USING_VOUCHERS
#define USING_VOUCHERS
#endif
#ifndef __VOUCHER_FORWARD_TYPE_DECLS__
#define __VOUCHER_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
	extern boolean_t voucher_mach_msg_set(mach_msg_header_t *msg) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif // __VOUCHER_FORWARD_TYPE_DECLS__
#endif // __has_include(<mach/mach_voucher_types.h>)
#endif // __has_include
#endif // !KERNEL
	
/* END VOUCHER CODE */

	
/* BEGIN MIG_STRNCPY_ZEROFILL CODE */

#if defined(__has_include)
#if __has_include(<mach/mig_strncpy_zerofill_support.h>)
#ifndef USING_MIG_STRNCPY_ZEROFILL
#define USING_MIG_STRNCPY_ZEROFILL
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
	extern int mig_strncpy_zerofill(char *dest, const char *src, int len) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif /* __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__ */
#endif /* __has_include(<mach/mig_strncpy_zerofill_support.h>) */
#endif /* __has_include */
	
/* END MIG_STRNCPY_ZEROFILL CODE */


#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	asl_ipc_MSG_COUNT
#define	asl_ipc_MSG_COUNT	9
#endif	/* asl_ipc_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <sys/types.h>

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
__BEGIN_DECLS


/* Routine _asl_server_create_aux_link */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_create_aux_link
(
	mach_port_t server,
	caddr_t message,
	mach_msg_type_number_t messageCnt,
	mach_port_t *fileport,
	caddr_t *url,
	mach_msg_type_number_t *urlCnt,
	int *status
);

/* SimpleRoutine _asl_server_message */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_message
(
	mach_port_t server,
	caddr_t message,
	mach_msg_type_number_t messageCnt
);

/* SimpleRoutine _asl_server_register_direct_watch */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_register_direct_watch
(
	mach_port_t server,
	int port
);

/* SimpleRoutine _asl_server_cancel_direct_watch */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_cancel_direct_watch
(
	mach_port_t server,
	int port
);

/* Routine _asl_server_query_2 */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_query_2
(
	mach_port_t server,
	caddr_t request,
	mach_msg_type_number_t requestCnt,
	uint64_t startid,
	int count,
	int flags,
	caddr_t *reply,
	mach_msg_type_number_t *replyCnt,
	uint64_t *lastid,
	int *status
);

/* Routine _asl_server_match */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t _asl_server_match
(
	mach_port_t server,
	caddr_t request,
	mach_msg_type_number_t requestCnt,
	uint64_t startid,
	uint64_t count,
	uint32_t duration,
	int direction,
	caddr_t *reply,
	mach_msg_type_number_t *replyCnt,
	uint64_t *lastid,
	int *status
);

__END_DECLS

/********************** Caution **************************/
/* The following data types should be used to calculate  */
/* maximum message sizes only. The actual message may be */
/* smaller, and the position of the arguments within the */
/* message layout may vary from what is presented here.  */
/* For example, if any of the arguments are variable-    */
/* sized, and less than the maximum is sent, the data    */
/* will be packed tight in the actual message to reduce  */
/* the presence of holes.                                */
/********************** Caution **************************/

/* typedefs for all requests */

#ifndef __Request__asl_ipc_subsystem__defined
#define __Request__asl_ipc_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t message;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t messageCnt;
	} __Request___asl_server_create_aux_link_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t message;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t messageCnt;
	} __Request___asl_server_message_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int port;
	} __Request___asl_server_register_direct_watch_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int port;
	} __Request___asl_server_cancel_direct_watch_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t request;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t requestCnt;
		uint64_t startid;
		int count;
		int flags;
	} __Request___asl_server_query_2_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t request;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t requestCnt;
		uint64_t startid;
		uint64_t count;
		uint32_t duration;
		int direction;
	} __Request___asl_server_match_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Request__asl_ipc_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__asl_ipc_subsystem__defined
#define __RequestUnion__asl_ipc_subsystem__defined
union __RequestUnion__asl_ipc_subsystem {
	__Request___asl_server_create_aux_link_t Request__asl_server_create_aux_link;
	__Request___asl_server_message_t Request__asl_server_message;
	__Request___asl_server_register_direct_watch_t Request__asl_server_register_direct_watch;
	__Request___asl_server_cancel_direct_watch_t Request__asl_server_cancel_direct_watch;
	__Request___asl_server_query_2_t Request__asl_server_query_2;
	__Request___asl_server_match_t Request__asl_server_match;
};
#endif /* !__RequestUnion__asl_ipc_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__asl_ipc_subsystem__defined
#define __Reply__asl_ipc_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t fileport;
		mach_msg_ool_descriptor_t url;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t urlCnt;
		int status;
	} __Reply___asl_server_create_aux_link_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply___asl_server_message_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply___asl_server_register_direct_watch_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply___asl_server_cancel_direct_watch_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t reply;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t replyCnt;
		uint64_t lastid;
		int status;
	} __Reply___asl_server_query_2_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t reply;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t replyCnt;
		uint64_t lastid;
		int status;
	} __Reply___asl_server_match_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Reply__asl_ipc_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__asl_ipc_subsystem__defined
#define __ReplyUnion__asl_ipc_subsystem__defined
union __ReplyUnion__asl_ipc_subsystem {
	__Reply___asl_server_create_aux_link_t Reply__asl_server_create_aux_link;
	__Reply___asl_server_message_t Reply__asl_server_message;
	__Reply___asl_server_register_direct_watch_t Reply__asl_server_register_direct_watch;
	__Reply___asl_server_cancel_direct_watch_t Reply__asl_server_cancel_direct_watch;
	__Reply___asl_server_query_2_t Reply__asl_server_query_2;
	__Reply___asl_server_match_t Reply__asl_server_match;
};
#endif /* !__RequestUnion__asl_ipc_subsystem__defined */

#ifndef subsystem_to_name_map_asl_ipc
#define subsystem_to_name_map_asl_ipc \
    { "_asl_server_create_aux_link", 117 },\
    { "_asl_server_message", 118 },\
    { "_asl_server_register_direct_watch", 119 },\
    { "_asl_server_cancel_direct_watch", 120 },\
    { "_asl_server_query_2", 121 },\
    { "_asl_server_match", 122 }
#endif

#ifdef __AfterMigUserHeader
__AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#endif	 /* _asl_ipc_user_ */
