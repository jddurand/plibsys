set (PLIBSYS_THREAD_MODEL posix)
set (PLIBSYS_IPC_MODEL node)
set (PLIBSYS_TIME_PROFILER_MODEL posix)
set (PLIBSYS_DIR_MODEL posix)
set (PLIBSYS_LIBRARYLOADER_MODEL none)

set (PLIBSYS_PLATFORM_LINK_LIBRARIES pthread dl)

set (PLIBSYS_PLATFORM_DEFINES
        -D_REENTRANT
)
