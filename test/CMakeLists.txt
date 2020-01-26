find_package(Catch2 REQUIRED)

set(Test_Sources
		"src/main.cpp")

add_executable(P1385_Test_Suite	${Test_Sources})

target_link_libraries(P1385_Test_Suite
		PRIVATE
			P1385
			Catch2::Catch2)