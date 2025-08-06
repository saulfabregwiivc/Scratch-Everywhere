#include "os.hpp"
#ifdef __OGC__
#include <gccore.h>
#endif

size_t MemoryTracker::totalAllocated = 0;
size_t MemoryTracker::peakUsage = 0;
size_t MemoryTracker::allocationCount = 0;

void Log::log(std::string message, bool printToScreen) {
    if (printToScreen) {
#ifdef __OGC__
        SYS_Report("%s\n", message.c_str());
#else
        std::cout << message << std::endl;
#endif
    }
}
void Log::logWarning(std::string message, bool printToScreen) {
    if (printToScreen) {
#ifdef __OGC__
        SYS_Report("Warning: %s\n", message.c_str());
#else
        std::cout << "Warning: " << message << std::endl;
#endif
    }
}
void Log::logError(std::string message, bool printToScreen) {
    if (printToScreen) {
#ifdef __OGC__
        SYS_Report("Error: %s\n", message.c_str());
#else
        std::cerr << "Error: " << message << std::endl;
#endif
    }
}
void Log::writeToFile(std::string message, std::string filePath) {
}