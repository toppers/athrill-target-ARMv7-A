cmake_minimum_required(VERSION 3.12)

project(athrill2)

set(CORE_DIR "athrill/src")
set(APLDIR "athrill/apl")
set(TARGET_DIR "src")

include_directories("${CORE_DIR}/inc" "${CORE_DIR}/lib" )

#libmain
file(GLOB MAIN-SRC
    "${CORE_DIR}/main/*.c" "${CORE_DIR}/main/option/*.c" "${CORE_DIR}/debugger/executor/cpu_control/*.c"
)

#libcui
file(GLOB CUI-SRC "${CORE_DIR}/lib/cui/*.c" "${CORE_DIR}/lib/cui/stdio/*.c" "${CORE_DIR}/lib/cui/udp/*.c"
    "${CORE_DIR}/debugger/interaction/front/parser/*.c" "${CORE_DIR}/debugger/interaction/front/parser/concrete_parser/*.c" 
    "${CORE_DIR}/debugger/executor/concrete_executor/*.c" "${CORE_DIR}/debugger/executor/concrete_executor/util/*.c"
)

#libcpu
file(GLOB CPU-SRC 
    "${TARGET_DIR}/cpu/cpu_common/*.c" "${TARGET_DIR}/cpu/coproc/cp15/*.c" "${TARGET_DIR}/cpu/coproc/cp11/*.c"
    "${TARGET_DIR}/cpu/cpu_dec/*.c" "${TARGET_DIR}/cpu/cpu_exec/*.c" "${TARGET_DIR}/cpu/config/*.c"
    "${CORE_DIR}/lib/dbg_log.c"
)

#libdevice
file(GLOB DEVICE-SRC 
    "${CORE_DIR}/device/peripheral/*.c" "${CORE_DIR}/device/peripheral/serial/fifo/*.c"
    "${TARGET_DIR}/device/*.c"
    "${TARGET_DIR}/device/intc/*.c"
    "${TARGET_DIR}/device/intc/gic/*.c"
    "${TARGET_DIR}/device/intc/register/*.c"
    "${TARGET_DIR}/device/peripheral/*.c"
    "${TARGET_DIR}/device/peripheral/timer/*.c"
    "${TARGET_DIR}/device/peripheral/serial/*.c"
    "${TARGET_DIR}/device/peripheral/vdev/*.c"
    "${TARGET_DIR}/debugger/executor/concrete_executor/*.c"
)

#libbus
file(GLOB BUS-SRC "${CORE_DIR}/bus/*.c")

#libloader
file(GLOB LOADER-SRC 
    "${CORE_DIR}/lib/symbol_ops.c" "${CORE_DIR}/lib/dwarf/*.c" "${CORE_DIR}/lib/dwarf/data_type/*.c"
)

#libmpu
file(GLOB MPU-SRC
    "${CORE_DIR}/device/mpu/*.c" "${CORE_DIR}/device/mpu/loader/*.c"
    "${TARGET_DIR}/cpu/config/mpu_config.c"
)

#libstd
file(GLOB STD-SRC
    "${CORE_DIR}/lib/hash.c" "${CORE_DIR}/lib/token.c" "${CORE_DIR}/lib/file.c" "${CORE_DIR}/lib/comm_buffer.c" "${CORE_DIR}/lib/winsock_wrapper/*.c"
    "${CORE_DIR}/lib/udp/*.c" "${CORE_DIR}/lib/tcp/*.c"
)

#libmros
set(MROS_SRC "${CORE_DIR}/device/peripheral/mros-dev/mros-src")
set(MROS_DEV "${CORE_DIR}/device/peripheral/mros-dev/mros-athrill")
file(GLOB MROS-SRC
    "${MROS_SRC}/comm/cimpl/target/*.c"
    "${MROS_SRC}/comm/cimpl/target/lwip/*.c"
    "${MROS_SRC}/lib/*.c"
    "${MROS_SRC}/node/*.c"
    "${MROS_SRC}/os/*.c"
    "${MROS_SRC}/os/target/os_asp/mros_os.c"
    "${MROS_SRC}/packet/cimpl/version/kinetic/*.c"
    "${MROS_SRC}/project/cimpl/*.c"
    "${MROS_SRC}/topic/cimpl/*.c"
    "${MROS_SRC}/transfer/cimpl/*.c"
    "${MROS_DEV}/api/*.c"
    "${MROS_DEV}/device/*.c"
    "${MROS_DEV}/config/*.c"
    "${MROS_DEV}/config/os/target/os_asp/mros_os.c"
    "${MROS_DEV}/target/os/*.c"
    "${MROS_DEV}/target/lwip/*.c"
    )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DOS_LINUX -O3")

add_library(main ${MAIN-SRC})
target_include_directories(main PUBLIC
    "${CORE_DIR}/lib/dwarf" "${CORE_DIR}/bus" "${CORE_DIR}/device/mpu" 
    "${CORE_DIR}/debugger/interaction" "${CORE_DIR}/debugger/interaction/inc" "${CORE_DIR}/debugger/executor"
    "${CORE_DIR}/cpu" "${CORE_DIR}/main"
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" "${TARGET_DIR}/debugger/interaction/inc" 
)

add_library(cui ${CUI-SRC})
target_include_directories(cui PUBLIC
    "${CORE_DIR}/lib/dwarf" 
    "${CORE_DIR}/debugger/interaction" "${CORE_DIR}/debugger/interaction/inc" "${CORE_DIR}/debugger/executor" "${CORE_DIR}/debugger/executor/concrete_executor/target"
    "${CORE_DIR}/cpu"
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" "${TARGET_DIR}/debugger/interaction/inc" 
)


add_library(cpu ${CPU-SRC})
target_include_directories(cpu PUBLIC
    "${CORE_DIR}/cpu" "${CORE_DIR}/bus" "${CORE_DIR}/device/mpu" 
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" "${TARGET_DIR}/cpu/cpu_exec" "${TARGET_DIR}/cpu/cpu_dec"
    "${TARGET_DIR}/cpu/cpu_common" "${TARGET_DIR}/device"
)

add_library(device ${DEVICE-SRC})
target_include_directories(device PUBLIC
    "${CORE_DIR}/cpu" "${CORE_DIR}/device/mpu" "${CORE_DIR}/debugger/executor" 
    "${CORE_DIR}/device/peripheral/target" 
    "${CORE_DIR}/device/peripheral/mros-dev/mros-athrill/api" 
    "${CORE_DIR}/device/peripheral/mros-dev/mros-athrill/device" 
    "${CORE_DIR}/device/peripheral/mros-dev/mros-athrill/target/os" 
    "${CORE_DIR}/device/peripheral/mros-dev/mros-src/os/target/os_asp" 
    "${CORE_DIR}/device/peripheral/serial/fifo" 
    "${APLDIR}/include"
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" "${TARGET_DIR}/device"
    "${TARGET_DIR}/device/intc" "${TARGET_DIR}/device/intc/gic" "${TARGET_DIR}/device/intc/register"
    "${TARGET_DIR}/device/peripheral" "${TARGET_DIR}/device/peripheral/inc"
)


add_library(bus ${BUS-SRC})
target_include_directories(bus PUBLIC
    "${CORE_DIR}/device/mpu" 
)

add_library(loader ${LOADER-SRC})
target_include_directories(loader PUBLIC
    "${CORE_DIR}/lib/dwarf" "${CORE_DIR}/cpu" 
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" 
)

add_library(mpu ${MPU-SRC})
target_include_directories(mpu PUBLIC
    "${CORE_DIR}/device/mpu" "${CORE_DIR}/device/peripheral/serial/fifo" "${CORE_DIR}/cpu" 
    "${CORE_DIR}/lib/dwarf" "${CORE_DIR}/lib/dwarf/data_type" 
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config" 
)

add_library(std ${STD-SRC})

add_library(mros ${MROS-SRC})
target_include_directories(mros PUBLIC
    "${TARGET_DIR}/cpu" "${TARGET_DIR}/cpu/config"
    "${MROS_SRC}/api" "${MROS_SRC}/inc" "${MROS_SRC}/os/target/os_asp" "${MROS_SRC}/protocol/cimpl" "${MROS_SRC}/node/cimpl"
    "${MROS_SRC}/topic/cimpl" "${MROS_SRC}/comm/cimpl/target/lwip" "${MROS_SRC}/comm/cimpl" "${MROS_SRC}/packet/cimpl"
    "${MROS_SRC}/packet/template/version/kinetic" "${MROS_SRC}/packet/cimpl/version/kinetic" "${MROS_SRC}/transfer/cimpl"
    "${MROS_DEV}/api" "${MROS_DEV}/config" "${MROS_DEV}/config/os/target/os_asp" "${MROS_DEV}/target" "${MROS_DEV}/target/os"
    "${MROS_DEV}/device"
)
target_compile_options(mros PUBLIC
    -DTARGET_ATHRILL
    -DLWIP_TRANSPORT_ETHERNET
)

add_executable(athrill2 ${MAIN-SRC})
target_link_libraries(athrill2 main cui cpu device bus loader mpu std mros pthread m dl)


# install(TARGETS main)

# enable_testing()
# add_test(NAME main COMMAND main)