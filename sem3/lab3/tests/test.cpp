#include "unorderedMaptests.h"
#include "cacheTests.h"
#include "myMapTest.h"
#include "histogramTest.h"


int main() {
    runUnorderedMapTest();
    runCacheTest();
    runMyMapTest();
    runHistogramTest();

    return 0;
}
