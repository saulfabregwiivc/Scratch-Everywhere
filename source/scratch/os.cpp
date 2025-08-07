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

// Wii and Gamecube Timer implementation
#ifdef __OGC__

Timer::Timer() {
    start();
}

void Timer::start() {
    startTime = gettick();
}

int Timer::getTimeMs() {
    u64 currentTime = gettick();
    return ticks_to_millisecs(currentTime - startTime);
}

// everyone else...
#else
Timer::Timer() {
    start();
}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

int Timer::getTimeMs() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
    return static_cast<int>(duration.count());
}

#endif

bool Timer::hasElapsed(int milliseconds) {
    return getTimeMs() >= milliseconds;
}

bool Timer::hasElapsedAndRestart(int milliseconds) {
    if (hasElapsed(milliseconds)) {
        start();
        return true;
    }
    return false;
}