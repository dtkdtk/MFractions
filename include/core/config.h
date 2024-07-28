#pragma once



#ifdef MF__CFG__FORCE_PREFIX
#    define MF__(name) mf__##name
#else
#    define MF__(name) name
#endif

#if _MSC_VER >= 1310 
#    define MF__NORETURN __declspec(noreturn)
#elif __GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ >= 5)
#    define MF__NORETURN __attribute__ ((noreturn))
#elif __STDC_VERSION__ >= 201ymmL
#    define MF__NORETURN _Noreturn
#else
#    define MF__NORETURN
#endif
