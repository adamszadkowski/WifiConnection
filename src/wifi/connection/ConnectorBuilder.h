#pragma once

#include <Executor.h>
#include <Runnable.h>
#include "wifi/connection/Config.h"

namespace wifi {
namespace connection {

class ConnectorBuilder {
 public:
  ConnectorBuilder();

  ConnectorBuilder& withExecutor(Executor& executor);
  ConnectorBuilder& withConfig(Config& config);
  ConnectorBuilder& withSuccessTask(Runnable& successTask);
  ConnectorBuilder& withFailTask(Runnable& failTask);
  Runnable* build();

 private:
  Executor* executor;
  Config* config;
  Runnable* successTask;
  Runnable* failTask;
};

}  // namespace connection
}  // namespace wifi
