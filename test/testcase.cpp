#include "riscv-emu.hpp"
#include "gtest/gtest.h"

namespace{
	TEST(parsing_test, parse_line){
		std::vector<std::string> parsed_str;

		parsed_str = parse_line("ld	s0,0(sp)");
		EXPECT_EQ(3	  , parsed_str.size());
		EXPECT_EQ("ld"    , parsed_str[0]);
		EXPECT_EQ("s0"    , parsed_str[1]);
		EXPECT_EQ("0(sp)" , parsed_str[2]);

		parsed_str = parse_line("addi	sp,sp,-16");
		EXPECT_EQ(4	  , parsed_str.size());
		EXPECT_EQ("addi"  , parsed_str[0]);
		EXPECT_EQ("sp"    , parsed_str[1]);
		EXPECT_EQ("sp"    , parsed_str[2]);
		EXPECT_EQ("-16"	  , parsed_str[3]);

		parsed_str = parse_line("addi	a0,a5,%lo(a)");
		EXPECT_EQ(4	  , parsed_str.size());
		EXPECT_EQ("addi"  , parsed_str[0]);
		EXPECT_EQ("a0"    , parsed_str[1]);
		EXPECT_EQ("a5"    , parsed_str[2]);
		EXPECT_EQ("%lo(a)", parsed_str[3]);
	}
}
