#include <common.h>

// No DirectoryService on iOS, let's make a stub
int _ds_running(void){
  if(getenv("DS_RUNNING")){
    return 1;
  } else {
    return 0;
  }
}

// No OpenDirectory on iOS
// Hey, what are you disabling btw?
void _si_disable_opendirectory(void){
  // Nothing to do
}
