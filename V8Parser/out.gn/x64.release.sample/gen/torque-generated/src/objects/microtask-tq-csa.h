#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MICROTASK_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MICROTASK_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Foreign> LoadCallbackTaskCallback_0(compiler::CodeAssemblerState* state_, TNode<CallbackTask> p_o);
void StoreCallbackTaskCallback_0(compiler::CodeAssemblerState* state_, TNode<CallbackTask> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadCallbackTaskData_0(compiler::CodeAssemblerState* state_, TNode<CallbackTask> p_o);
void StoreCallbackTaskData_0(compiler::CodeAssemblerState* state_, TNode<CallbackTask> p_o, TNode<Foreign> p_v);
TNode<JSReceiver> LoadCallableTaskCallable_0(compiler::CodeAssemblerState* state_, TNode<CallableTask> p_o);
void StoreCallableTaskCallable_0(compiler::CodeAssemblerState* state_, TNode<CallableTask> p_o, TNode<JSReceiver> p_v);
TNode<Context> LoadCallableTaskContext_0(compiler::CodeAssemblerState* state_, TNode<CallableTask> p_o);
void StoreCallableTaskContext_0(compiler::CodeAssemblerState* state_, TNode<CallableTask> p_o, TNode<Context> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MICROTASK_TQ_H_
