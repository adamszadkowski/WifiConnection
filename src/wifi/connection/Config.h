#pragma once

#include <TimeUnit.h>
#include "Arduino.h"

namespace wifi {
namespace connection {

class Config {
 public:
  virtual ~Config() {
  }

  virtual String getSsid() = 0;
  virtual String getPassword() = 0;

  virtual uint8_t getMaxRetryCount() {
    return 10;
  }

  virtual unsigned long getDelay() {
    return 5;
  }
  virtual TimeUnit getDelayTimeUnit() {
    return TimeUnit::SECONDS;
  }
};

}  // namespace connection
}  // namespace wifi
