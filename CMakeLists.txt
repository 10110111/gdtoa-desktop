cmake_minimum_required (VERSION 3.0)
project (gdtoa C)
include("GNUInstallDirs")

include_directories("${PROJECT_BINARY_DIR}")
option(BUILD_SHARED_LIBS "Build shared library instead of static" ON)

set(gdtoa_SOURCES
        gdtoa/dmisc.c
	    gdtoa/dtoa.c
	    gdtoa/g_Qfmt.c
	    gdtoa/g_Qfmt_p.c
	    gdtoa/g__fmt.c
	    gdtoa/g_ddfmt.c
	    gdtoa/g_ddfmt_p.c
	    gdtoa/g_dfmt.c
	    gdtoa/g_dfmt_p.c
	    gdtoa/g_ffmt.c
	    gdtoa/g_ffmt_p.c
	    gdtoa/g_xLfmt.c
	    gdtoa/g_xLfmt_p.c
	    gdtoa/g_xfmt.c
	    gdtoa/g_xfmt_p.c
	    gdtoa/gdtoa.c
	    gdtoa/gethex.c
	    gdtoa/gmisc.c
	    gdtoa/hd_init.c
	    gdtoa/hexnan.c
	    gdtoa/misc.c
	    gdtoa/smisc.c
	    gdtoa/strtoIQ.c
	    gdtoa/strtoId.c
	    gdtoa/strtoIdd.c
	    gdtoa/strtoIf.c
	    gdtoa/strtoIg.c
	    gdtoa/strtoIx.c
	    gdtoa/strtoIxL.c
	    gdtoa/strtod.c
	    gdtoa/strtodI.c
	    gdtoa/strtodg.c
	    gdtoa/strtof.c
	    gdtoa/strtopQ.c
	    gdtoa/strtopd.c
	    gdtoa/strtopdd.c
	    gdtoa/strtopf.c
	    gdtoa/strtopx.c
	    gdtoa/strtopxL.c
	    gdtoa/strtorQ.c
	    gdtoa/strtord.c
	    gdtoa/strtordd.c
	    gdtoa/strtorf.c
	    gdtoa/strtorx.c
	    gdtoa/strtorxL.c
	    gdtoa/sum.c
	    gdtoa/ulp.c
        "${PROJECT_BINARY_DIR}/arith.h"
        "${PROJECT_BINARY_DIR}/gd_qnan.h"
)

add_executable(arithchk gdtoa/arithchk.c)
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/arith.h"
    COMMAND "${PROJECT_BINARY_DIR}/arithchk" > "${PROJECT_BINARY_DIR}/arith.h"
    DEPENDS "${PROJECT_BINARY_DIR}/arithchk"
    VERBATIM)

add_executable(gd_qnan gdtoa/qnan.c "${PROJECT_BINARY_DIR}/arith.h")
add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/gd_qnan.h"
    COMMAND "${PROJECT_BINARY_DIR}/gd_qnan" > "${PROJECT_BINARY_DIR}/gd_qnan.h"
    DEPENDS "${PROJECT_BINARY_DIR}/gd_qnan"
    VERBATIM)

add_library(gdtoa ${gdtoa_SOURCES})

install(TARGETS gdtoa DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(FILES gdtoa/gdtoa.h "${PROJECT_BINARY_DIR}/arith.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/gdtoa/")
