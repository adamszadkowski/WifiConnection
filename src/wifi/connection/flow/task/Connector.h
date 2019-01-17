#pragma once

#include "wifi/connection/Config.h"
#include "wifi/connection/flow/state/SharedState.h"
#include "wifi/connection/task/Task.h"

namespace wifi {
namespace connection {

class Connector : public wifi::connection::task::Task {
 public:
  Connector(wifi::connection::flow::state::SharedState *sharedState, wifi::connection::task::TaskFactory *taskFactory);

  void executeStep() override;
};

}  // namespace connection
}  // namespace wifi
