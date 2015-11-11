#ifndef CORE_GLOBAL_H
#define CORE_GLOBAL_H

#include <QtGlobal>

#if defined(CORE_LIBRARY)
#  define CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CORE_GLOBAL_H
