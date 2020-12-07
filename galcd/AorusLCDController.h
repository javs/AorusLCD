#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <cstdint>


class AorusLCDController
{
	HMODULE m_gvdisplay = nullptr;


	using TGvReadI2C = uint32_t(*)(uint32_t, void*, void*, uint32_t);
	TGvReadI2C _GvReadI2C = nullptr;

	using TGvWriteI2C = uint32_t(*)(uint32_t, void*);
	TGvWriteI2C _GvWriteI2C = nullptr;

	using TGvInitDispLib = uint32_t(*)();
	TGvInitDispLib _GvInitDispLib = nullptr;

	using TGvFreeDispLib = uint32_t(*)();
	TGvFreeDispLib _GvFreeDispLib = nullptr;

public:
	AorusLCDController();
	~AorusLCDController();

	uint32_t SetLCDStatus(bool on_off);
	void ReadI2C();
};

