#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<FixedArray> GetCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_function, compiler::CodeAssemblerLabel* label_IfNoCoverageInfo);
TNode<Smi> SlotCount_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_coverageInfo);
TNode<Smi> FirstIndexForSlot_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_slot);
void IncrementBlockCount_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_coverageInfo, TNode<Smi> p_slot);
TNode<FixedArray> UnsafeCast_CoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_H_
