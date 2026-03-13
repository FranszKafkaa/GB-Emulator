# CMake generated Testfile for 
# Source directory: /home/marce/projetos/gameboy-emulator-cpp
# Build directory: /home/marce/projetos/gameboy-emulator-cpp/build-nosdl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gbemu_tests "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests")
set_tests_properties(gbemu_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;119;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_apu "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "apu")
set_tests_properties(gbemu_suite_apu PROPERTIES  LABELS "suite;apu" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_bus "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "bus")
set_tests_properties(gbemu_suite_bus PROPERTIES  LABELS "suite;bus" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_cartridge "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "cartridge")
set_tests_properties(gbemu_suite_cartridge PROPERTIES  LABELS "suite;cartridge" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_cpu "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "cpu")
set_tests_properties(gbemu_suite_cpu PROPERTIES  LABELS "suite;cpu" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_joypad "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "joypad")
set_tests_properties(gbemu_suite_joypad PROPERTIES  LABELS "suite;joypad" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_options "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "options")
set_tests_properties(gbemu_suite_options PROPERTIES  LABELS "suite;options" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_ppu "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "ppu")
set_tests_properties(gbemu_suite_ppu PROPERTIES  LABELS "suite;ppu" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_state "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "state")
set_tests_properties(gbemu_suite_state PROPERTIES  LABELS "suite;state" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
add_test(gbemu_suite_timer "/home/marce/projetos/gameboy-emulator-cpp/build-nosdl/gbemu_tests" "--suite" "timer")
set_tests_properties(gbemu_suite_timer PROPERTIES  LABELS "suite;timer" _BACKTRACE_TRIPLES "/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;133;add_test;/home/marce/projetos/gameboy-emulator-cpp/CMakeLists.txt;0;")
