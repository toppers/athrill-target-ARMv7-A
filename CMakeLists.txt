cmake_minimum_required(VERSION 3.12)

project(athrill2)

#libmain
file(GLOB MAIN-SRC "athrill/src/main/*.c" "athrill/src/main/option/*.c" "athrill/src/debugger/executor/cpu_control/*.c")
include_directories("athrill/src/cpu" "athrill/src/inc" "athrill/src/lib" "athrill/src/bus" "athrill/src/device/mpu" "athrill/src/debugger/executor")
include_directories("athrill/src/lib/dwarf" "athrill/src/debugger/interaction" "athrill/src/debugger/interaction/inc" "athrill/src/main")
include_directories("src/cpu/config" "src/cpu" "src/debugger/interaction/inc")

#libcui
file(GLOB CUI-SRC "athrill/src/lib/cui/*.c" "athrill/src/lib/cui/stdio/*.c" "athrill/src/lib/cui/udp/*.c")
file(GLOB CUI-DEBUG-SRC "athrill/src/debugger/interaction/front/parser/*.c" "athrill/src/debugger/interaction/front/parser/concrete_parser/*.c" "athrill/src/debugger/executor/concrete_executor/*.c" "athrill/src/debugger/executor/concrete_executor/util/*.c")
include_directories("athrill/src/debugger/executor/concrete_executor/target")

#libcpu
file(GLOB CPU-SRC "src/cpu/cpu_common/*.c" "src/cpu/coproc/cp15/*.c" "src/cpu/coproc/cp11/*.c" "src/cpu/cpu_dec/*.c" "src/cpu/cpu_exec/*.c" "src/cpu/config/*.c")
include_directories("src/cpu/cpu_dec" "src/cpu/cpu_common")

#libdevice
file(GLOB DEVICE-SRC "athrill/src/device/peripheral/*.c" "athrill/src/device/peripheral/serial/fifo/*.c" "src/device/*.c" "src/device/intc/*.c" "src/device/intc/gic/*.c" "src/device/intc/register/*.c" )
file(GLOB DEVICE-SRC2-SRC "src/device/peripheral/*.c" "src/device/peripheral/timer/*.c" "src/device/peripheral/serial/*.c" "src/device/peripheral/vdev/*.c" "src/debugger/executor/concrete_executor/*.c")
include_directories("src/device/peripheral" "src/device/intc/gic" "athrill/src/device/peripheral/target" "athrill/src/device/peripheral/serial/fifo" "athrill/apl/include" "src/device")

#libbus
file(GLOB BUS-SRC "athrill/src/bus/*.c")

#libloader
file(GLOB LOADER-SRC "athrill/src/lib/symbol_ops.c" "athrill/src/lib/dwarf/*.c" "athrill/src/lib/dwarf/data_type/*.c")

#libmpu
file(GLOB MPU-SRC "athrill/src/device/mpu/*.c" "athrill/src/device/mpu/loader/*.c" "src/cpu/config/mpu_config.c")
include_directories("athrill/src/lib/dwarf/data_type")

#libstd
file(GLOB STD-SRC "athrill/src/lib/*.c" "athrill/src/lib/winsock_wrapper/*.c" "athrill/src/lib/udp/*.c" "athrill/src/lib/tcp/*.c")

#libmros
file(GLOB MROS-SRC "")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DOS_LINUX -O3")

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}  -lpthread -lm -ldl")
# set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_LINKER} -o <TARGET> <OBJECTS> <LINK_LIBRARIES> <LINK_FLAGS>")

add_library(main ${MAIN-SRC})
add_library(cui ${CUI-SRC} ${CUI-DEBUG-SRC})
add_library(cpu ${CPU-SRC})
add_library(device ${DEVICE-SRC} ${DEVICE-SRC2-SRC})
add_library(bus ${BUS-SRC})
add_library(loader ${LOADER-SRC})
add_library(mpu ${MPU-SRC})
add_library(std ${STD-SRC})
#add_library(mros )
add_executable(athrill2 ${MAIN-SRC})
target_link_libraries(athrill2 main cui cpu device bus loader mpu std)


# install(TARGETS main)

# enable_testing()
# add_test(NAME main COMMAND main)