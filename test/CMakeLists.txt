find_package(Catch2 REQUIRED)

set(Test_Sources
		"src/dr_vector_engine.cpp"
		"src/main.cpp")

add_executable(P1385_Test_Suite	${Test_Sources})

target_link_libraries(P1385_Test_Suite
		PRIVATE
			P1385
			Catch2::Catch2)