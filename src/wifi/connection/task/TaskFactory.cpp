#include "wifi/connection/task/TaskFactory.h"

#include "wifi/connection/flow/task/Connector.h"

namespace wifi {
namespace connection {
namespace task {

TaskFactory::TaskFactory(::wifi::connection::flow::state::SharedState* sharedState) : sharedState(sharedState) {
}

Runnable& TaskFactory::createConnectToWifiTask() {
  return *new Connector(sharedState, this);
}

}  // namespace task
}  // namespace connection
}  // namespace wifi
