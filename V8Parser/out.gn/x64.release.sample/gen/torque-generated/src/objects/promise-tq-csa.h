#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROMISE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROMISE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<HeapObject> LoadPromiseCapabilityPromise_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o);
void StorePromiseCapabilityPromise_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadPromiseCapabilityResolve_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o);
void StorePromiseCapabilityResolve_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o, TNode<Object> p_v);
TNode<Object> LoadPromiseCapabilityReject_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o);
void StorePromiseCapabilityReject_0(compiler::CodeAssemblerState* state_, TNode<PromiseCapability> p_o, TNode<Object> p_v);
TNode<Object> LoadPromiseReactionNext_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o);
void StorePromiseReactionNext_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadPromiseReactionRejectHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o);
void StorePromiseReactionRejectHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadPromiseReactionFulfillHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o);
void StorePromiseReactionFulfillHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadPromiseReactionPromiseOrCapability_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o);
void StorePromiseReactionPromiseOrCapability_0(compiler::CodeAssemblerState* state_, TNode<PromiseReaction> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadPromiseReactionJobTaskArgument_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o);
void StorePromiseReactionJobTaskArgument_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o, TNode<Object> p_v);
TNode<Context> LoadPromiseReactionJobTaskContext_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o);
void StorePromiseReactionJobTaskContext_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o, TNode<Context> p_v);
TNode<HeapObject> LoadPromiseReactionJobTaskHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o);
void StorePromiseReactionJobTaskHandler_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadPromiseReactionJobTaskPromiseOrCapability_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o);
void StorePromiseReactionJobTaskPromiseOrCapability_0(compiler::CodeAssemblerState* state_, TNode<PromiseReactionJobTask> p_o, TNode<HeapObject> p_v);
TNode<Context> LoadPromiseResolveThenableJobTaskContext_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o);
void StorePromiseResolveThenableJobTaskContext_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o, TNode<Context> p_v);
TNode<JSPromise> LoadPromiseResolveThenableJobTaskPromiseToResolve_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o);
void StorePromiseResolveThenableJobTaskPromiseToResolve_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o, TNode<JSPromise> p_v);
TNode<JSReceiver> LoadPromiseResolveThenableJobTaskThen_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o);
void StorePromiseResolveThenableJobTaskThen_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o, TNode<JSReceiver> p_v);
TNode<JSReceiver> LoadPromiseResolveThenableJobTaskThenable_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o);
void StorePromiseResolveThenableJobTaskThenable_0(compiler::CodeAssemblerState* state_, TNode<PromiseResolveThenableJobTask> p_o, TNode<JSReceiver> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROMISE_TQ_H_
