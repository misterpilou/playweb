#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_ARRAY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_ARRAY_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadPropertyArrayLengthAndHash_0(compiler::CodeAssemblerState* state_, TNode<PropertyArray> p_o);
void StorePropertyArrayLengthAndHash_0(compiler::CodeAssemblerState* state_, TNode<PropertyArray> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_ARRAY_TQ_H_
