#ifndef ZEPHYR_CEXPORT_H
#define ZEPHYR_CEXPORT_H

/* declare a namespaced name */
#ifdef __cplusplus
#define ZD(ns)
#else
#define ZD(ns) ns_
#endif

/* use a namespaced name */
#ifdef __cplusplus
#define ZU(ns) ns::
#else
#define ZU(ns) ns_
#endif

/* declare a namespace */
#ifdef __cplusplus
#define Z_NS_START(n) namespace n {
#define Z_NS_END }
#else
#define Z_NS_START(n)
#define Z_NS_END
#endif

/* enum class vs enum */
#ifdef __cplusplus
#define Z_ENUM_CLASS enum class
#else
#define Z_ENUM_CLASS enum
#endif

#endif
