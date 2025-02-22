#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <ranges>

#include "RE/Skyrim.h"
#include "REX/REX/Singleton.h"
#include "SKSE/SKSE.h"

#include <MergeMapperPluginAPI.h>

#include <ankerl/unordered_dense.h>
#include <frozen/map.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <CLibUtil/distribution.hpp>
#include <CLibUtil/rng.hpp>
#include <CLibUtil/string.hpp>
#include <ClibUtil/simpleINI.hpp>

#include <ClibUtil/editorID.hpp>

#define DLLEXPORT __declspec(dllexport)

namespace logger = SKSE::log;
using namespace clib_util;
using namespace std::literals;

// for visting variants
template <class... Ts>
struct overload : Ts...
{
	using Ts::operator()...;
};

template <class K, class D>
using Map = ankerl::unordered_dense::map<K, D>;

template <class K>
using Set = ankerl::unordered_dense::set<K>;

struct string_hash
{
	using is_transparent = void;  // enable heterogeneous overloads
	using is_avalanching = void;  // mark class as high quality avalanching hash

	[[nodiscard]] std::uint64_t operator()(std::string_view str) const noexcept
	{
		return ankerl::unordered_dense::hash<std::string_view>{}(str);
	}
};

template <class D>
using StringMap = ankerl::unordered_dense::map<std::string, D, string_hash, std::equal_to<>>;

namespace stl
{
	using namespace SKSE::stl;
}

#include "Version.h"
