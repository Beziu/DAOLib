#ifndef DAOLIB_GLOBAL_H
#define DAOLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DAOLIB_LIBRARY)
#  define DAOLIB_EXPORT Q_DECL_EXPORT
#else
#  define DAOLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // DAOLIB_GLOBAL_H
