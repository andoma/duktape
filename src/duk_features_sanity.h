/*
 *  Sanity check of duk_features.h defines.  This is a separate file
 *  because we also check for consistency between duktape.h and
 *  duk_features.h defines.  Duktape.h cannot be included first
 *  because feature selection macros would then be incorrect.
 *  This file can also double check user tweaks made by an optional
 *  duk_custom.h header.
 */

#ifndef DUK_FEATURES_SANITY_H_INCLUDED
#define DUK_FEATURES_SANITY_H_INCLUDED

/*
 *  Deprecated feature options.
 *
 *  Catch so that user more easily notices and updates build.
 */

#if defined(DUK_OPT_NO_FUNC_STMT)
#error DUK_OPT_NO_FUNC_STMT is deprecated, use DUK_OPT_NO_NONSTD_FUNC_STMT
#endif

#if defined(DUK_OPT_FUNC_NONSTD_CALLER_PROPERTY)
#error DUK_OPT_FUNC_NONSTD_CALLER_PROPERTY is deprecated, use DUK_OPT_NONSTD_FUNC_CALLER_PROPERTY
#endif

#if defined(DUK_OPT_FUNC_NONSTD_SOURCE_PROPERTY)
#error DUK_OPT_FUNC_NONSTD_SOURCE_PROPERTY is deprecated, use DUK_OPT_NONSTD_FUNC_SOURCE_PROPERTY
#endif

#if defined(DUK_OPT_NO_ARRAY_SPLICE_NONSTD_DELCOUNT)
#error DUK_OPT_NO_ARRAY_SPLICE_NONSTD_DELCOUNT is deprecated, use DUK_OPT_NO_NONSTD_ARRAY_SPLICE_DELCOUNT
#endif

#if defined(DUK_OPT_NO_OBJECT_ES6_PROTO_PROPERTY)
#error DUK_OPT_NO_OBJECT_ES6_PROTO_PROPERTY is deprecated, use DUK_OPT_NO_ES6_OBJECT_PROTO_PROPERTY
#endif

#if defined(DUK_OPT_NO_OBJECT_ES6_SETPROTOTYPEOF)
#error DUK_OPT_NO_OBJECT_ES6_SETPROTOTYPEOF is deprecated, use DUK_OPT_NO_ES6_OBJECT_SETPROTOTYPEOF
#endif

/*
 *  Debug print consistency
 */

#if defined(DUK_USE_DPRINT) && !defined(DUK_USE_DEBUG)
#error DUK_USE_DPRINT without DUK_USE_DEBUG
#endif

#if defined(DUK_USE_DDPRINT) && !defined(DUK_USE_DEBUG)
#error DUK_USE_DDPRINT without DUK_USE_DEBUG
#endif

#if defined(DUK_USE_DDDPRINT) && !defined(DUK_USE_DEBUG)
#error DUK_USE_DDDPRINT without DUK_USE_DEBUG
#endif

/*
 *  Garbage collection consistency
 */

#if defined(DUK_USE_REFERENCE_COUNTING) && !defined(DUK_USE_DOUBLE_LINKED_HEAP)
#error DUK_USE_REFERENCE_COUNTING defined without DUK_USE_DOUBLE_LINKED_HEAP
#endif

#if defined(DUK_USE_GC_TORTURE) && !defined(DUK_USE_MARK_AND_SWEEP)
#error DUK_USE_GC_TORTURE defined without DUK_USE_MARK_AND_SWEEP
#endif

/*
 *  Misc
 */

#if (defined(DUK_USE_VARIADIC_MACROS) && !defined(DUK_API_VARIADIC_MACROS)) || \
    (!defined(DUK_USE_VARIADIC_MACROS) && defined(DUK_API_VARIADIC_MACROS))
#error DUK_USE_VARIADIC_MACROS and DUK_API_VARIADIC_MACROS must agree
#endif

#endif  /* DUK_FEATURES_SANITY_H_INCLUDED */
