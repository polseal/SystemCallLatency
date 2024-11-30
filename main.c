#include <stdio.h>
#include <windows.h>
#include <limits.h>
#include <time.h>

int main() {
    const int iterations = 1000000;
    long long minLatency = LLONG_MAX;

    // Wiederhole den Test für 1000000 Iterationen
    for (int i = 0; i < iterations; ++i)
    {
        // Startzeit messen
        LARGE_INTEGER start, end, frequency;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        // Systemaufruf, um die Thread-ID zu bekommen
        GetCurrentThreadId();
        // Endzeit messen
        QueryPerformanceCounter(&end); 

        // Latenz in Nanosekunden berechnen
        long long latency = (end.QuadPart - start.QuadPart) * 1000000000 / frequency.QuadPart;

        // Minimum Latenz speichern
        if (latency < minLatency)
        {
            minLatency = latency;
        }
    }

    // Ausgabe der minimalen Latenz
    printf("Min latency: %lld ns\n", minLatency);

    return 0;
}