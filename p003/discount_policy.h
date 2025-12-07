#pragma once

#include <algorithm>
#include <utility>
#include <vector>

namespace discount {
	struct Entry {
		int min_price;
		float rate;
	};

	inline const std::vector<Entry> standard_tiers = {
		{500'000, 0.2f},
		{300'000, 0.1f},
		{100'000, 0.05f},
	};

	class Policy {
	public:
		explicit Policy(std::vector<Entry> tiers) : entries_sorted_(std::move(tiers)) {
			std::sort(entries_sorted_.begin(), entries_sorted_.end(), [](const auto& a, const auto& b) {
				return a.min_price > b.min_price;
			});
		}

		static Policy create_default() {
			return Policy{ standard_tiers };
		}

		float get_discount_rate(int price) const {
			for (const auto& e : entries_sorted_) {
				if (price >= e.min_price) {
					return e.rate;
				}
			}

			return 0.0f;
		}

	private:
		std::vector<Entry> entries_sorted_;
	};
}
