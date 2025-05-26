#pragma once

#include <cstdint>

#include "../for_gerefi/wideband_can.h"

void SetFault(int ch, wbo::Fault fault);
bool HasFault();
wbo::Fault GetCurrentFault(int ch);
