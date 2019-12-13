#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STACK_FRAME_INFO_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STACK_FRAME_INFO_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> LoadStackFrameInfoLineNumber_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoLineNumber_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<Smi> LoadStackFrameInfoColumnNumber_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoColumnNumber_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<Smi> LoadStackFrameInfoPromiseAllIndex_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoPromiseAllIndex_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<Smi> LoadStackFrameInfoScriptId_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoScriptId_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<Smi> LoadStackFrameInfoWasmFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoWasmFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoScriptName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoScriptName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoScriptNameOrSourceUrl_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoScriptNameOrSourceUrl_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoFunctionName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoFunctionName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoMethodName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoMethodName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoTypeName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoTypeName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoEvalOrigin_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoEvalOrigin_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadStackFrameInfoWasmModuleName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoWasmModuleName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<HeapObject> LoadStackFrameInfoWasmInstance_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoWasmInstance_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadStackFrameInfoFlag_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);
void StoreStackFrameInfoFlag_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadStackTraceFrameFrameArray_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o);
void StoreStackTraceFrameFrameArray_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadStackTraceFrameFrameIndex_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o);
void StoreStackTraceFrameFrameIndex_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadStackTraceFrameFrameInfo_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o);
void StoreStackTraceFrameFrameInfo_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadStackTraceFrameId_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o);
void StoreStackTraceFrameId_0(compiler::CodeAssemblerState* state_, TNode<StackTraceFrame> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STACK_FRAME_INFO_TQ_H_
