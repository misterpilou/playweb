#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CELL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CELL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadCellValue_0(compiler::CodeAssemblerState* state_, TNode<Cell> p_o);
void StoreCellValue_0(compiler::CodeAssemblerState* state_, TNode<Cell> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CELL_TQ_H_
