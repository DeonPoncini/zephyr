#ifndef ZEPHYR_CEXPORT_H
#define ZEPHYR_CEXPORT_H

#ifdef __cplusplus
#define Z_NS_START(n) namespace n {
#define Z_NS_END }
#else
#define Z_NS_START(n)
#define Z_NS_END
#endif

#ifdef __cplusplus
#define Z_ENUM_CLASS(ns, n) enum class n
#else
#define Z_ENUM_CLASS(ns, n) enum ns ## _ ## n
#endif

#ifdef __cplusplus
#define Z_ENUM(ns, n) enum n
#else
#define Z_ENUM(ns, n) enum ns ## _ ## n
#endif

#ifdef __cplusplus
#define Z_STRUCT(ns, n) struct n
#else
#define Z_STRUCT(ns, n) struct ns ## _ ## n
#endif

#endif
