/*
 * @author thomas
 * @date 1/27/20.
 */

#include <dr_vector_engine.hpp>

#include <catch2/catch.hpp>

TEST_CASE("dr_vector_engine Default Constructor", "[dr_vector_engine][default][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}

	SECTION("dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>>")
	{
		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}
}

TEST_CASE("dr_vector_engine Move Constructor", "[dr_vector_engine][move][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3;
		engine1(1) = 2;
		engine1(2) = 1;

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);

		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine2 (std::move(engine1));

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == 3);
		CHECK(engine2(1) == 2);
		CHECK(engine2(2) == 1);

		CHECK(engine1.elements() == 0);
		CHECK(engine1.capacity() == 0);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3.1;
		engine1(1) = 2.2;
		engine1(2) = 1.3;

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));

		std::math::dr_vector_engine<float, std::allocator<float>> engine2 (std::move(engine1));

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == Approx(3.1));
		CHECK(engine2(1) == Approx(2.2));
		CHECK(engine2(2) == Approx(1.3));

		CHECK(engine1.elements() == 0);
		CHECK(engine1.capacity() == 0);
	}

	SECTION("dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>>")
	{
		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = std::vector<float>({3.1, 4.2, 5.3});
		engine1(1) = std::vector<float>({7.2, 8.9, 2.7});
		engine1(2) = std::vector<float>({1.1, 2.2, 3.3});

		CHECK(engine1(0)[0] == Approx(3.1));
		CHECK(engine1(0)[1] == Approx(4.2));
		CHECK(engine1(0)[2] == Approx(5.3));
		CHECK(engine1(1)[0] == Approx(7.2));
		CHECK(engine1(1)[1] == Approx(8.9));
		CHECK(engine1(1)[2] == Approx(2.7));
		CHECK(engine1(2)[0] == Approx(1.1));
		CHECK(engine1(2)[1] == Approx(2.2));
		CHECK(engine1(2)[2] == Approx(3.3));

		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine2 (std::move(engine1));

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0)[0] == Approx(3.1));
		CHECK(engine2(0)[1] == Approx(4.2));
		CHECK(engine2(0)[2] == Approx(5.3));
		CHECK(engine2(1)[0] == Approx(7.2));
		CHECK(engine2(1)[1] == Approx(8.9));
		CHECK(engine2(1)[2] == Approx(2.7));
		CHECK(engine2(2)[0] == Approx(1.1));
		CHECK(engine2(2)[1] == Approx(2.2));
		CHECK(engine2(2)[2] == Approx(3.3));

		CHECK(engine1.elements() == 0);
		CHECK(engine1.capacity() == 0);
	}
}

TEST_CASE("dr_vector_engine Copy Constructor", "[dr_vector_engine][copy][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3;
		engine1(1) = 2;
		engine1(2) = 1;

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);

		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine2 (engine1);

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == 3);
		CHECK(engine2(1) == 2);
		CHECK(engine2(2) == 1);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3.1;
		engine1(1) = 2.2;
		engine1(2) = 1.3;

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));

		std::math::dr_vector_engine<float, std::allocator<float>> engine2 (engine1);

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == Approx(3.1));
		CHECK(engine2(1) == Approx(2.2));
		CHECK(engine2(2) == Approx(1.3));

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));
	}

	SECTION("dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>>")
	{
		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = std::vector<float>({3.1, 4.2, 5.3});
		engine1(1) = std::vector<float>({7.2, 8.9, 2.7});
		engine1(2) = std::vector<float>({1.1, 2.2, 3.3});

		CHECK(engine1(0)[0] == Approx(3.1));
		CHECK(engine1(0)[1] == Approx(4.2));
		CHECK(engine1(0)[2] == Approx(5.3));
		CHECK(engine1(1)[0] == Approx(7.2));
		CHECK(engine1(1)[1] == Approx(8.9));
		CHECK(engine1(1)[2] == Approx(2.7));
		CHECK(engine1(2)[0] == Approx(1.1));
		CHECK(engine1(2)[1] == Approx(2.2));
		CHECK(engine1(2)[2] == Approx(3.3));

		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine2 (engine1);

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0)[0] == Approx(3.1));
		CHECK(engine2(0)[1] == Approx(4.2));
		CHECK(engine2(0)[2] == Approx(5.3));
		CHECK(engine2(1)[0] == Approx(7.2));
		CHECK(engine2(1)[1] == Approx(8.9));
		CHECK(engine2(1)[2] == Approx(2.7));
		CHECK(engine2(2)[0] == Approx(1.1));
		CHECK(engine2(2)[1] == Approx(2.2));
		CHECK(engine2(2)[2] == Approx(3.3));

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		CHECK(engine1(0)[0] == Approx(3.1));
		CHECK(engine1(0)[1] == Approx(4.2));
		CHECK(engine1(0)[2] == Approx(5.3));
		CHECK(engine1(1)[0] == Approx(7.2));
		CHECK(engine1(1)[1] == Approx(8.9));
		CHECK(engine1(1)[2] == Approx(2.7));
		CHECK(engine1(2)[0] == Approx(1.1));
		CHECK(engine1(2)[1] == Approx(2.2));
		CHECK(engine1(2)[2] == Approx(3.3));
	}
}