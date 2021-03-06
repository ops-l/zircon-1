#ifndef SYSROOT_SYS_WAIT_H_
#define SYSROOT_SYS_WAIT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_pid_t
#define __NEED_id_t
#include <bits/alltypes.h>

typedef enum { P_ALL = 0, P_PID = 1, P_PGID = 2 } idtype_t;

pid_t wait(int*);
pid_t waitpid(pid_t, int*, int);

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || \
    defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include <signal.h>
int waitid(idtype_t, id_t, siginfo_t*, int);
#endif

#define WNOHANG 1
#define WUNTRACED 2

#define WSTOPPED 2
#define WEXITED 4
#define WCONTINUED 8
#define WNOWAIT 0x1000000

#define WEXITSTATUS(s) (((s)&0xff00) >> 8)
#define WTERMSIG(s) ((s)&0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WCOREDUMP(s) ((s)&0x80)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff) * 0x10001) >> 8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff) - 1U < 0xffu)
#define WIFCONTINUED(s) ((s) == 0xffff)

#ifdef __cplusplus
}
#endif

#endif  // SYSROOT_SYS_WAIT_H_
