#pragma once

namespace sp {
	struct ImGUIID {
	public:
		bool operator==(ImGUIID const & other) const;

	public:
		void * OwnerFunction;
		int Item;
		int Index;
	};
}
