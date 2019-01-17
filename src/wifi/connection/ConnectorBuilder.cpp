#include "wifi/connection/ConnectorBuilder.h"

#include <NullTask.h>
#include "wifi/connection/StartingTask.h"
#include "wifi/connection/flow/state/SharedState.h"

namespace wifi {
namespace connection {

ConnectorBuilder::ConnectorBuilder() {
  executor = &::executor;
  successTask = &NullTask::getInstance();
  failTask = &NullTask::getInstance();
}

ConnectorBuilder& ConnectorBuilder::withExecutor(Executor& executor) {
  ConnectorBuilder::executor = &executor;
  return *this;
}

ConnectorBuilder& ConnectorBuilder::withConfig(Config& config) {
  ConnectorBuilder::config = &config;
  return *this;
}

ConnectorBuilder& ConnectorBuilder::withSuccessTask(Runnable& successTask) {
  ConnectorBuilder::successTask = &successTask;
  return *this;
}

ConnectorBuilder& ConnectorBuilder::withFailTask(Runnable& failTask) {
  ConnectorBuilder::failTask = &failTask;
  return *this;
}

Runnable* ConnectorBuilder::build() {
  wifi::connection::flow::state::SharedState* state =
      new wifi::connection::flow::state::SharedState(*executor, *config, *successTask, *failTask);
  wifi::connection::task::TaskFactory* taskFactory = new wifi::connection::task::TaskFactory(state);

  return new StartingTask(state, taskFactory);
}

}  // namespace connection
}  // namespace wifi
