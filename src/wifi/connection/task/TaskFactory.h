#pragma once

#include <Runnable.h>
#include "wifi/connection/flow/state/SharedState.h"

namespace wifi {
namespace connection {
namespace task {

class TaskFactory {
 public:
  TaskFactory(::wifi::connection::flow::state::SharedState* sharedState);

  Runnable& createConnectToWifiTask();

 private:
  ::wifi::connection::flow::state::SharedState* sharedState;
};

}  // namespace task
}  // namespace connection
}  // namespace wifi
