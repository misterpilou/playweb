#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_CELL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_CELL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<HeapObject> LoadFeedbackCellValue_0(compiler::CodeAssemblerState* state_, TNode<FeedbackCell> p_o);
void StoreFeedbackCellValue_0(compiler::CodeAssemblerState* state_, TNode<FeedbackCell> p_o, TNode<HeapObject> p_v);
TNode<Int32T> LoadFeedbackCellInterruptBudget_0(compiler::CodeAssemblerState* state_, TNode<FeedbackCell> p_o);
void StoreFeedbackCellInterruptBudget_0(compiler::CodeAssemblerState* state_, TNode<FeedbackCell> p_o, TNode<Int32T> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FEEDBACK_CELL_TQ_H_
