//#include <common.h>

#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>

bool _os_xbs_chrooted = 0;

static int get_inode(void){
   struct stat buf;
   fstat(open("/", O_RDONLY), &buf);
   return buf.st_ino;
}

static bool check_if_chrooted(void){
  if (get_inode() != 2){
    return true;
  } else {
    return false;
  }
}

static void __attribute__((constructor)) _os_xbs_chrooted_init() {
  _os_xbs_chrooted = check_if_chrooted();
}
