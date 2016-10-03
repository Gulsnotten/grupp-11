#pragma once
#include <random>

class Random {
public:
	static std::default_random_engine& global_urng() {
		static std::default_random_engine u{};
		return u;
	}
	static void randomize() {
		static std::random_device rd{};
		global_urng().seed(rd());
	}
	static unsigned char color() {//0-255
		static std::uniform_int_distribution<> dist{};
		using parm_t = decltype(dist)::param_type;
		return static_cast<unsigned char>(dist(global_urng(), parm_t{ 0, 255 }));
	}
	static int getInt(int from, int thru) {//(from,thru)
		static std::uniform_int_distribution<> dist{};
		using parm_t = decltype(dist)::param_type;
		return dist(global_urng(), parm_t{ from, thru });
	}
	static float getFloat(float from, float upto) {// [from, upto)
		static std::uniform_real_distribution<float> dist{};
		using parm_t = decltype(dist)::param_type;
		return dist(global_urng(), parm_t{ from, upto });
	}
	static double getDouble(double from, double upto) {// [from, upto)
		static std::uniform_real_distribution<> dist{};
		using parm_t = decltype(dist)::param_type;
		return dist(global_urng(), parm_t{ from, upto });
	}
};