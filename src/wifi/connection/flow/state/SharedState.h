#pragma once

#include <Executor.h>
#include <Runnable.h>
#include "wifi/connection/Config.h"

namespace wifi {
namespace connection {
namespace flow {
namespace state {

class SharedState {
 public:
  SharedState(Executor &executor, Config &config, Runnable &successTask, Runnable &failTask)
      : executor(executor), config(config), successTask(successTask), failTask(failTask) {
    clear();
  }

  void clear() {
    retryCount = 0;
  }

  Executor &getExecutor() {
    return executor;
  }

  Config &getConfig() {
    return config;
  }

  Runnable &getSuccessTask() {
    return successTask;
  }

  Runnable &getFailTask() {
    return failTask;
  }

  uint8_t getRetryCount() {
    return retryCount;
  }
  void incrementRetryCount() {
    ++retryCount;
  }

 private:
  Executor &executor;
  Config &config;
  Runnable &successTask;
  Runnable &failTask;

  uint8_t retryCount;
};

}  // namespace state
}  // namespace flow
}  // namespace connection
}  // namespace wifi
