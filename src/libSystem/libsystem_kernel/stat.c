#include <common.h>

#include <sys/stat.h>
#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>

// stat stuff with __ seems broken on macOS, but not present on iOS
int __fstat(int fd, struct stat *buf){ return fstat(fd, buf); };
int __fstatat(int fd, const char *path, struct stat *buf, int flag){ return fstatat(fd, path, buf, flag); };
int __fstatfs(int fd, struct statfs *buf){ return fstatfs(fd, buf); };
int __getfsstat(struct statfs *buf, int bufsize, int flags){ return getfsstat(buf, bufsize, flags); };
int __lstat(const char *restrict path, struct stat *restrict buf){ return lstat(path, buf); };
int __stat(const char *restrict path, struct stat *restrict buf){ return stat(path, buf); };
int __statfs(const char *path, struct statfs *buf){ return statfs(path, buf); };
