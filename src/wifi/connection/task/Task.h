#pragma once

#include <Runnable.h>
#include "wifi/connection/flow/state/SharedState.h"
#include "wifi/connection/task/TaskFactory.h"

namespace wifi {
namespace connection {
namespace task {

class Task : public Runnable {
 public:
  Task(wifi::connection::flow::state::SharedState* sharedState, TaskFactory* taskFactory)
      : sharedState(sharedState), taskFactory(taskFactory) {
  }

  void run() final {
    executeStep();
    delete this;
  }

  virtual void executeStep() = 0;

 protected:
  wifi::connection::flow::state::SharedState* sharedState;
  TaskFactory* taskFactory;
};

}  // namespace task
}  // namespace connection
}  // namespace wifi
