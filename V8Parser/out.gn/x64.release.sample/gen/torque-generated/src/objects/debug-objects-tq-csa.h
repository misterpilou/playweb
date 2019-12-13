#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<SharedFunctionInfo> LoadDebugInfoShared_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoShared_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<SharedFunctionInfo> p_v);
TNode<Smi> LoadDebugInfoDebuggerHints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoDebuggerHints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadDebugInfoScript_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoScript_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadDebugInfoOriginalBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoOriginalBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadDebugInfoDebugBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoDebugBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<HeapObject> p_v);
TNode<FixedArray> LoadDebugInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<FixedArray> p_v);
TNode<Smi> LoadDebugInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadDebugInfoCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);
void StoreDebugInfoCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<HeapObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_H_
