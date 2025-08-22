#include "os.hpp"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#ifdef __OGC__
#include <gccore.h>
#endif
#ifdef __WIIU__
#include <sstream>
#include <whb/sdcard.h>
#endif

size_t MemoryTracker::totalAllocated = 0;
size_t MemoryTracker::peakUsage = 0;
size_t MemoryTracker::allocationCount = 0;
size_t MemoryTracker::totalVRAMAllocated = 0;

void Log::log(std::string message, bool printToScreen) {
    if (printToScreen) std::cout << message << std::endl;
}
void Log::logWarning(std::string message, bool printToScreen) {
    if (printToScreen)
        std::cout << "\x1b[1;33m" << "Warning: " << message << "\x1b[0m" << std::endl;
}
void Log::logError(std::string message, bool printToScreen) {
    if (printToScreen)
        std::cerr << "\x1b[1;31m" << "Error: " << message << "\x1b[0m" << std::endl;
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

std::string OS::getScratchFolderLocation() {
#ifdef __WIIU__
    return std::string(WHBGetSdCardMountPath()) + "/wiiu/scratch-wiiu/";
#elif defined(__SWITCH__)
    return "/switch/scratch-nx/";
#elif defined(__OGC__)
    #if defined(WII)
        return "/apps/scratch-wii/";
    #else
        return "/";
    #endif
#else
    return "scratch-everywhere/";
#endif
}