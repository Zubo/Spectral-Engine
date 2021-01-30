#include <PlatformIndependence/Environment.hpp>

namespace sp {
    char Environment::FilePathSeparator() {
        #ifdef _WIN32
            return '\\';
        #else
            return '/';
        #endif
    }
}
