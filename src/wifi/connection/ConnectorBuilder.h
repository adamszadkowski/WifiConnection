#pragma once

#include <Command.h>
#include <Executor.h>
#include "wifi/connection/Config.h"

namespace wifi {
namespace connection {

class ConnectorBuilder {
 public:
  ConnectorBuilder();

  ConnectorBuilder& withExecutor(Executor& executor);
  ConnectorBuilder& withConfig(Config& config);
  ConnectorBuilder& withSuccessTask(Command successTask);
  ConnectorBuilder& withFailTask(Command failTask);
  Runnable* build();

 private:
  Executor* executor;
  Config* config;
  Command successTask;
  Command failTask;
};

}  // namespace connection
}  // namespace wifi
