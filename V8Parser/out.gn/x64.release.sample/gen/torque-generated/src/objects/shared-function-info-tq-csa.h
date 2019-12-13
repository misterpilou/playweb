#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SHARED_FUNCTION_INFO_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SHARED_FUNCTION_INFO_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Int32T> LoadPreparseDataDataLength_0(compiler::CodeAssemblerState* state_, TNode<PreparseData> p_o);
void StorePreparseDataDataLength_0(compiler::CodeAssemblerState* state_, TNode<PreparseData> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadPreparseDataChildrenLength_0(compiler::CodeAssemblerState* state_, TNode<PreparseData> p_o);
void StorePreparseDataChildrenLength_0(compiler::CodeAssemblerState* state_, TNode<PreparseData> p_o, TNode<Int32T> p_v);
TNode<BytecodeArray> LoadInterpreterDataBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<InterpreterData> p_o);
void StoreInterpreterDataBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<InterpreterData> p_o, TNode<BytecodeArray> p_v);
TNode<Code> LoadInterpreterDataInterpreterTrampoline_0(compiler::CodeAssemblerState* state_, TNode<InterpreterData> p_o);
void StoreInterpreterDataInterpreterTrampoline_0(compiler::CodeAssemblerState* state_, TNode<InterpreterData> p_o, TNode<Code> p_v);
TNode<Object> LoadSharedFunctionInfoFunctionData_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoFunctionData_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Object> p_v);
TNode<Object> LoadSharedFunctionInfoNameOrScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoNameOrScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadSharedFunctionInfoOuterScopeInfoOrFeedbackMetadata_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoOuterScopeInfoOrFeedbackMetadata_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadSharedFunctionInfoScriptOrDebugInfo_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoScriptOrDebugInfo_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<HeapObject> p_v);
TNode<Int16T> LoadSharedFunctionInfoLength_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoLength_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Int16T> p_v);
TNode<Uint16T> LoadSharedFunctionInfoFormalParameterCount_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoFormalParameterCount_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Uint16T> p_v);
TNode<Uint16T> LoadSharedFunctionInfoExpectedNofProperties_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoExpectedNofProperties_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Uint16T> p_v);
TNode<Int16T> LoadSharedFunctionInfoFunctionTokenOffset_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoFunctionTokenOffset_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Int16T> p_v);
TNode<Int32T> LoadSharedFunctionInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadSharedFunctionInfoFunctionLiteralId_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o);
void StoreSharedFunctionInfoFunctionLiteralId_0(compiler::CodeAssemblerState* state_, TNode<SharedFunctionInfo> p_o, TNode<Int32T> p_v);
TNode<String> LoadUncompiledDataInferredName_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o);
void StoreUncompiledDataInferredName_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o, TNode<String> p_v);
TNode<Int32T> LoadUncompiledDataStartPosition_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o);
void StoreUncompiledDataStartPosition_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadUncompiledDataEndPosition_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o);
void StoreUncompiledDataEndPosition_0(compiler::CodeAssemblerState* state_, TNode<UncompiledData> p_o, TNode<Int32T> p_v);
TNode<PreparseData> LoadUncompiledDataWithPreparseDataPreparseData_0(compiler::CodeAssemblerState* state_, TNode<UncompiledDataWithPreparseData> p_o);
void StoreUncompiledDataWithPreparseDataPreparseData_0(compiler::CodeAssemblerState* state_, TNode<UncompiledDataWithPreparseData> p_o, TNode<PreparseData> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SHARED_FUNCTION_INFO_TQ_H_
