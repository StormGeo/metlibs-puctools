/* $Id$ */
#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__MSVCRT__)

// Windows with Microsoft Visual C runtime: separate 64-bit functions

typedef struct _stati64 pu_struct_stat;
static inline int
pu_stat(const char *fn, pu_struct_stat *sb)
{
	return _stati64(fn, sb);
}

#else

/*
 * Everything else: either stat() / fstat() / lstat() support 64-bit sizes
 * directly (*BSD), or the library takes care of it transparently (GNU).
 */
typedef struct stat pu_struct_stat;
static inline int
pu_stat(const char *fn, pu_struct_stat *sb)
{
	return stat(fn, sb);
}
#endif

#ifdef __cplusplus
}
#endif

#endif
