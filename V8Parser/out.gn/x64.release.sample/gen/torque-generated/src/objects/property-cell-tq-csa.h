#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Name> LoadPropertyCellName_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);
void StorePropertyCellName_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Name> p_v);
TNode<Smi> LoadPropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);
void StorePropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Smi> p_v);
TNode<Object> LoadPropertyCellValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);
void StorePropertyCellValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Object> p_v);
TNode<WeakFixedArray> LoadPropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);
void StorePropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<WeakFixedArray> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_H_
