#ifndef CACHEX_RESULT_H
#define CACHEX_RESULT_H

#include <cstdint>
#include <vector>

#include "scsi_status.h"

struct CommandResult
{
  CommandResult(unsigned int NumOutBytes)
      : Data(NumOutBytes), Duration(0.0), Valid(false), ScsiStatus(0xff)
  {
  }

  std::vector<std::uint8_t> Data;
  double Duration;
  bool Valid;
  std::uint8_t ScsiStatus;

  operator bool() const { return Valid && ScsiStatus == ScsiStatus::GOOD; }
};

#endif
