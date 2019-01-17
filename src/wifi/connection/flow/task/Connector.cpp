#include "wifi/connection/flow/task/Connector.h"

#include <DelayedTask.h>
#include <ESP8266WiFi.h>

namespace wifi {
namespace connection {

Connector::Connector(wifi::connection::flow::state::SharedState* sharedState, wifi::connection::task::TaskFactory* taskFactory)
    : Task(sharedState, taskFactory) {
}

void Connector::executeStep() {
  Executor& executor = sharedState->getExecutor();
  Config& config = sharedState->getConfig();

  if (WiFi.isConnected()) {
    WiFi.setAutoReconnect(true);
    executor.execute(sharedState->getSuccessTask());
  } else if (sharedState->getRetryCount() < config.getMaxRetryCount()) {
    WiFi.begin(config.getSsid().c_str(), config.getPassword().c_str());
    executor.execute(*new DelayedTask(executor, taskFactory->createConnectToWifiTask(), config.getDelay(), config.getDelayTimeUnit()));
  } else {
    executor.execute(sharedState->getFailTask());
  }

  sharedState->incrementRetryCount();
}

}  // namespace connection
}  // namespace wifi
