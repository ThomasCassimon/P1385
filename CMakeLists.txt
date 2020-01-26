cmake_minimum_required(VERSION 3.15)
project(P1385)

set(CMAKE_CXX_STANDARD 20)

set(P1385_Sources
		"src/linear_algebra.cpp")

add_library(P1385 ${P1385_Sources})

target_compile_options(P1385
		PRIVATE
			-Wall
			-Wextra
			-Wpedantic
			-Wshadow
			-Wnon-virtual-dtor
			-Wcast-align
			-Wunused
			-Woverloaded-virtual
			-Wconversion
			-Wnull-dereference
			-Wdouble-promotion
			-Wformat=2

			-Werror-return-type
			-Werror-switch
			-Werror-reorder
			-Werror-shorten-64-to-32
			-Werror-sign-conversion
			-Werror-sign-compare
			-Werror-old-style-cast

			-Wno-vla-extension
)

target_include_directories(P1385
		PUBLIC
			include/)

add_subdirectory(test)