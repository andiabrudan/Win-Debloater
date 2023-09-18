#pragma once

#include <streambuf>
#include <iostream>
#include <string_view>
#include <Windows.h>
#include "registry.h"

void ChangeRegistryNumber(
	HKEY machine,
	std::string_view key,
	std::string_view value,
	DWORD data);

void ChangeRegistryString(
	HKEY machine,
	std::string_view key,
	std::string_view value,
	std::string_view data);

void Delete_RegistryValue(
	HKEY machine,
	std::string_view key,
	std::string_view value);
