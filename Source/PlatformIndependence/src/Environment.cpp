#include <PlatformIndependence/Environment.h>

namespace sp {
    char Environment::FilePathSeparator() {
        #ifdef _WIN32
            return '\\';
        #else
            return '/';
        #endif
    }
}
