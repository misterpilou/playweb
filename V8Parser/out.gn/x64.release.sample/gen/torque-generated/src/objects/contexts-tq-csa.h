#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CONTEXTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CONTEXTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadContextLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o);
void StoreContextLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o, TNode<Smi> p_v);
TNode<ScopeInfo> LoadContextScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o);
void StoreContextScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o, TNode<ScopeInfo> p_v);
TNode<Object> LoadContextPrevious_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o);
void StoreContextPrevious_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CONTEXTS_TQ_H_
