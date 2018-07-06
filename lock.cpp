// Undo the defines we do for renaming gdtoa's functions for the header to work normally
#undef strtod
#undef strtof
#include <mutex>

static std::mutex mutexes[2];

extern "C" void ACQUIRE_DTOA_LOCK(unsigned n)
{
    mutexes[n].lock();
}

extern "C" void FREE_DTOA_LOCK(unsigned n)
{
    mutexes[n].unlock();
}

extern "C" unsigned int dtoa_get_threadno()
{
    return 0; // FIXME: stub, but should work
}
