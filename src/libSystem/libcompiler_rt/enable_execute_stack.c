// https://github.com/llvm/llvm-project/blob/main/compiler-rt/lib/builtins/enable_execute_stack.c
#include <common.h>
#include <sys/mman.h>

#if __LP64__
#define TRAMPOLINE_SIZE 48
#else
#define TRAMPOLINE_SIZE 40
#endif

void __enable_execute_stack(void *addr) {

#if __APPLE__ && !defined(HAVE_SYSCONF)
  // On Darwin, pagesize is always 4096 bytes
  const uintptr_t pageSize = 4096;
#else
  const uintptr_t pageSize = sysconf(_SC_PAGESIZE);
#endif // __APPLE__

  const uintptr_t pageAlignMask = ~(pageSize - 1);
  uintptr_t p = (uintptr_t)addr;
  unsigned char *startPage = (unsigned char *)(p & pageAlignMask);
  unsigned char *endPage =
      (unsigned char *)((p + TRAMPOLINE_SIZE + pageSize) & pageAlignMask);
  size_t length = endPage - startPage;
  (void)mprotect((void *)startPage, length, PROT_READ | PROT_WRITE | PROT_EXEC);
}
