#ifndef LIBIOSFUNC_H
#define LIBIOSFUNC_H

#define IOSFUNC_PUBLIC __attribute__((visibility("default")))
#define IOSFUNC_HIDDEN __attribute__((visibility("hidden")))

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*	---	libcompiler_rt	---	*/
IOSFUNC_PUBLIC void __clear_cache(void *start, void *end);
IOSFUNC_PUBLIC void __enable_execute_stack(void *addr);

/*	---	libsystem_c	---	*/
#if defined __has_include
#  if !__has_include(<rune.h>)
#    ifndef _RUNE_H_
#    define _RUNE_H_
#    include <runetype.h>
#    include <stdio.h>
#    define _PATH_LOCALE    "/usr/share/locale"
#    define _INVALID_RUNE   _CurrentRuneLocale->__invalid_rune
#    define __sgetrune      _CurrentRuneLocale->__sgetrune
#    define __sputrune      _CurrentRuneLocale->__sputrune
#    define sgetrune(s, n, r)       (*__sgetrune)((s), (n), (r))
#    define sputrune(c, s, n, r)    (*__sputrune)((c), (s), (n), (r))
__BEGIN_DECLS
IOSFUNC_PUBLIC char    *mbrune(const char *, rune_t);
IOSFUNC_PUBLIC char    *mbrrune(const char *, rune_t);
IOSFUNC_PUBLIC char    *mbmb(const char *, char *);
IOSFUNC_PUBLIC long     fgetrune(FILE *);
IOSFUNC_PUBLIC int      fputrune(rune_t, FILE *);
IOSFUNC_PUBLIC int      fungetrune(rune_t, FILE *);
IOSFUNC_PUBLIC int      setrunelocale(char *);
IOSFUNC_PUBLIC void     setinvalidrune(rune_t);
__END_DECLS
#    endif  /*! _RUNE_H_ */
#  endif
#  if !__has_include(<util.h>)
#    ifndef _UTIL_H_
#    define _UTIL_H_
#    include <sys/cdefs.h>
#    include <sys/ttycom.h>
#    include <sys/types.h>
#    include <stdio.h>
#    include <pwd.h>
#    include <termios.h>
#    include <Availability.h>
#    define PIDLOCK_NONBLOCK        1
#    define PIDLOCK_USEHOSTNAME     2
#    define FPARSELN_UNESCESC       0x01
#    define FPARSELN_UNESCCONT      0x02
#    define FPARSELN_UNESCCOMM      0x04
#    define FPARSELN_UNESCREST      0x08
#    define FPARSELN_UNESCALL       0x0f
#    define OPENDEV_PART    0x01            /* Try to open the raw partition. */
#    define OPENDEV_BLCK    0x04            /* Open block, not character device. */
__BEGIN_DECLS
struct utmp; /* forward reference to /usr/include/utmp.h */
IOSFUNC_PUBLIC void    login(struct utmp *)            __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_12_0);
IOSFUNC_PUBLIC int     login_tty(int);
IOSFUNC_PUBLIC int     logout(const char *)            __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_12_0);
IOSFUNC_PUBLIC void    logwtmp(const char *, const char *, const char *) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_5,__IPHONE_2_0,__IPHONE_2_0);
IOSFUNC_PUBLIC int     opendev(char *, int, int, char **);
IOSFUNC_PUBLIC int     openpty(int *, int *, char *, struct termios *,
                     struct winsize *);
IOSFUNC_PUBLIC char   *fparseln(FILE *, size_t *, size_t *, const char[3], int);
IOSFUNC_PUBLIC pid_t   forkpty(int *, char *, struct termios *, struct winsize *);
IOSFUNC_PUBLIC int     pidlock(const char *, int, pid_t *, const char *);
IOSFUNC_PUBLIC int     ttylock(const char *, int, pid_t *);
IOSFUNC_PUBLIC int     ttyunlock(const char *);
IOSFUNC_PUBLIC int     ttyaction(char *tty, char *act, char *user);
struct iovec;
IOSFUNC_PUBLIC char   *ttymsg(struct iovec *, int, const char *, int);
__END_DECLS
/* Include utmp.h last to avoid deprecation warning above */
#    include <utmp.h>
#    endif /* !_UTIL_H_ */
#  endif
/*	--- 	libsystem_info	---	*/
int _ds_running(void);
void _si_disable_opendirectory(void);

/*	---	libsystem_kernel	---	*/
IOSFUNC_PUBLIC int __fstat(int fd, struct stat *buf);
IOSFUNC_PUBLIC int __fstatat(int fd, const char *path, struct stat *buf, int flag);
IOSFUNC_PUBLIC int __fstatfs(int fd, struct statfs *buf);
IOSFUNC_PUBLIC int __getfsstat(struct statfs *buf, int bufsize, int flags);
IOSFUNC_PUBLIC int __lstat(const char *restrict path, struct stat *restrict buf);
IOSFUNC_PUBLIC int __stat(const char *restrict path, struct stat *restrict buf);
IOSFUNC_PUBLIC int __statfs(const char *path, struct statfs *buf);
IOSFUNC_PUBLIC bool _os_xbs_chrooted;
IOSFUNC_PUBLIC int proc_clear_vmpressure(pid_t pid);
IOSFUNC_PUBLIC int proc_set_owner_vmpressure(void);
IOSFUNC_PUBLIC int proc_set_delayidlesleep(void);
IOSFUNC_PUBLIC int proc_clear_delayidlesleep(void);
IOSFUNC_PUBLIC int proc_disable_apptype(pid_t pid, int apptype);
IOSFUNC_PUBLIC int proc_enable_apptype(pid_t pid, int apptype);
IOSFUNC_PUBLIC int proc_suppress(__unused pid_t pid, __unused uint64_t *generation);
IOSFUNC_PUBLIC int quota(void);
IOSFUNC_PUBLIC int setquota(void);

#endif
#ifdef LIBIOSFUNC_INTERNAL
//IOSFUNC_HIDDEN void free_new_argv(char** argv);
// PATH_MAX for Darwin
#endif // LIBIOSFUNC_INTERNAL

#if defined(__APPLE__)
#  include <TargetConditionals.h>
#  if TARGET_OS_EMBEDDED
#    if !defined(LIBIOSFUNC_INTERNAL) && defined(ENABLE_SYMBOL_PREFIX)
#      define __clear_cache iosfunc___clear_cache
#      define __enable_execute_stack iosfunc___enable_execute_stack
#      define mbrune iosfunc_mbrune
#      define mbrrune iosfunc_mbrrune
#      define mbmb iosfunc_mbmb
#      define fgetrune iosfunc_fgetrune
#      define fputrune iosfunc_fputrune
#      define fungetrune iosfunc_fungetrune
#      define setrunelocale iosfunc_setrunelocale
#      define setinvalidrune iosfunc_setinvalidrune
#      define login iosfunc_login
#      define logout iosfunc_logout
#      define getutmp iosfunc_getutmp
#      define getutmpx iosfunc_getutmpx
#      define wordexp iosfunc_wordexp
#      define wordfree iosfunc_wordfree
#      define _ds_running iosfunc__ds_running
#      define _si_disable_opendirectory iosfunc__si_disable_opendirectory
#      define __fstat iosfunc___fstat
#      define __fstatat iosfunc___fstatat
#      define __fstatfs iosfunc___fstatfs
#      define __getfsstat iosfunc___getfsstat
#      define __lstat iosfunc___lstat
#      define __stat iosfunc___stat
#      define __statfs iosfunc___statfs
#      define _os_xbs_chrooted iosfunc__os_xbs_chrooted
#      define proc_clear_vmpressure iosfunc_proc_clear_vmpressure
#      define proc_set_owner_vmpressure iosfunc_proc_set_owner_vmpressure
#      define proc_set_delayidlesleep iosfunc_proc_set_delayidlesleep
#      define proc_clear_delayidlesleep iosfunc_proc_clear_delayidlesleep
#      define proc_disable_apptype iosfunc_proc_disable_apptype
#      define proc_enable_apptype iosfunc_proc_enable_apptype
#      define proc_suppress iosfunc_proc_suppress
#      define quota iosfunc_quota
#      define setquota iosfunc_setquota
#      define system_version_compat_mode iosfunc_system_version_compat_mode
#    endif // LIBIOSFUNC_INTERNAL
#  endif // TARGET_OS_EMBEDDED
#endif // __APPLE__
  
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIBIOSFUNC_H
