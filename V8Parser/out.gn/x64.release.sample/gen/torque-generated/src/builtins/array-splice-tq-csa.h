#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SPLICE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SPLICE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<FixedArray> Extract_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_first, TNode<Smi> p_count, TNode<Smi> p_capacity);
TNode<FixedDoubleArray> Extract_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_first, TNode<Smi> p_count, TNode<Smi> p_capacity);
TNode<Object> FastArraySplice_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o, TNode<Number> p_originalLengthNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, compiler::CodeAssemblerLabel* label_Bailout);
TNode<Object> FillDeletedElementsArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount, TNode<JSReceiver> p_a);
void HandleForwardCase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount);
void HandleBackwardCase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount);
TNode<Object> SlowSplice_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_arguments, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_actualStart, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCount);
void FastSplice_FixedArray_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount);
void FastSplice_FixedDoubleArray_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount);
void DoMoveElements_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
void StoreHoles_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex);
void DoCopyElements_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
void DoMoveElements_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
void StoreHoles_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex);
void DoCopyElements_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedDoubleArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SPLICE_TQ_H_
