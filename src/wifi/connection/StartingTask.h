#pragma once

#include <Runnable.h>
#include "wifi/connection/flow/state/SharedState.h"
#include "wifi/connection/task/TaskFactory.h"

namespace wifi {
namespace connection {

class StartingTask : public Runnable {
 public:
  StartingTask(wifi::connection::flow::state::SharedState* sharedState, wifi::connection::task::TaskFactory* taskFactory)
      : sharedState(sharedState), taskFactory(taskFactory) {
  }

  ~StartingTask() override {
    delete taskFactory;
    delete sharedState;
  }

  void run() override {
    sharedState->clear();
    taskFactory->createConnectToWifiTask().run();
  }

 private:
  wifi::connection::flow::state::SharedState* sharedState;
  wifi::connection::task::TaskFactory* taskFactory;
};

}  // namespace connection
}  // namespace wifi
