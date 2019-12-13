#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_HEAP_NUMBER_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_HEAP_NUMBER_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Float64T> LoadHeapNumberValue_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_o);
void StoreHeapNumberValue_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_o, TNode<Float64T> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_HEAP_NUMBER_TQ_H_
