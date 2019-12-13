#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FREE_SPACE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FREE_SPACE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadFreeSpaceSize_0(compiler::CodeAssemblerState* state_, TNode<FreeSpace> p_o);
void StoreFreeSpaceSize_0(compiler::CodeAssemblerState* state_, TNode<FreeSpace> p_o, TNode<Smi> p_v);
TNode<MaybeObject> LoadFreeSpaceNext_0(compiler::CodeAssemblerState* state_, TNode<FreeSpace> p_o);
void StoreFreeSpaceNext_0(compiler::CodeAssemblerState* state_, TNode<FreeSpace> p_o, TNode<MaybeObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FREE_SPACE_TQ_H_
