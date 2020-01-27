cmake_minimum_required(VERSION 3.15)
project(P1385)

set(CMAKE_CXX_STANDARD 20)

set(P1385_Sources
		"src/dr_vector_engine.cpp"
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

			$<$<CXX_COMPILER_ID:clang>:-Werror-return-type>
			$<$<CXX_COMPILER_ID:clang>:-Werror-switch>
			$<$<CXX_COMPILER_ID:clang>:-Werror-reorder>
			$<$<CXX_COMPILER_ID:clang>:-Werror-shorten-64-to-32>
			$<$<CXX_COMPILER_ID:clang>:-Werror-sign-conversion>
			$<$<CXX_COMPILER_ID:clang>:-Werror-sign-compare>
			$<$<CXX_COMPILER_ID:clang>:-Werror-old-style-cast>

			$<$<CXX_COMPILER_ID:gcc>:-Werror=return-type>
			$<$<CXX_COMPILER_ID:gcc>:-Werror=switch>
			$<$<CXX_COMPILER_ID:gcc>:-Werror=reorder>
			$<$<CXX_COMPILER_ID:gcc>:-Werror=Werror-sign-conversion>
			$<$<CXX_COMPILER_ID:gcc>:-Werror=sign-compare>
			$<$<CXX_COMPILER_ID:gcc>:-Werror=old-style-cast>

			-Wno-vla-extension
)

target_include_directories(P1385
		PUBLIC
			include/)

add_subdirectory(test)