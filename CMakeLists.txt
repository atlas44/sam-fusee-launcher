set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain


cmake_minimum_required(VERSION 2.8)
#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(sam-fusee-launcher C CXX)

#====================================================================#
print_board_list()
print_programmer_list()
#====================================================================#

#set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
#set(ARDUINO_DEFAULT_PORT COM4) # Default Port, when not specified