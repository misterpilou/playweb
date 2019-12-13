#ifndef V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Code> LoadWasmExportedFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Code> p_v);
TNode<WasmInstanceObject> LoadWasmExportedFunctionDataInstance_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataInstance_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<WasmInstanceObject> p_v);
TNode<Smi> LoadWasmExportedFunctionDataJumpTableOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataJumpTableOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);
TNode<Object> LoadWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Object> p_v);
TNode<Object> LoadWasmExportedFunctionDataWasmCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataWasmCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Object> p_v);
TNode<Smi> LoadWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);
void StoreWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);
TNode<JSReceiver> LoadWasmJSFunctionDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);
void StoreWasmJSFunctionDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<JSReceiver> p_v);
TNode<Code> LoadWasmJSFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);
void StoreWasmJSFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<Code> p_v);
TNode<Smi> LoadWasmJSFunctionDataSerializedReturnCount_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);
void StoreWasmJSFunctionDataSerializedReturnCount_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWasmJSFunctionDataSerializedParameterCount_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);
void StoreWasmJSFunctionDataSerializedParameterCount_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<Smi> p_v);
TNode<ByteArray> LoadWasmJSFunctionDataSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);
void StoreWasmJSFunctionDataSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<ByteArray> p_v);
TNode<RawPtrT> LoadWasmCapiFunctionDataCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);
void StoreWasmCapiFunctionDataCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<RawPtrT> p_v);
TNode<Foreign> LoadWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);
void StoreWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Foreign> p_v);
TNode<Code> LoadWasmCapiFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);
void StoreWasmCapiFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Code> p_v);
TNode<ByteArray> LoadWasmCapiFunctionDataSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);
void StoreWasmCapiFunctionDataSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<ByteArray> p_v);
TNode<Uint32T> LoadWasmIndirectFunctionTableSize_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o);
void StoreWasmIndirectFunctionTableSize_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o, TNode<Uint32T> p_v);
TNode<RawPtrT> LoadWasmIndirectFunctionTableSigIds_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o);
void StoreWasmIndirectFunctionTableSigIds_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o, TNode<RawPtrT> p_v);
TNode<RawPtrT> LoadWasmIndirectFunctionTableTargets_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o);
void StoreWasmIndirectFunctionTableTargets_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o, TNode<RawPtrT> p_v);
TNode<HeapObject> LoadWasmIndirectFunctionTableManagedNativeAllocations_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o);
void StoreWasmIndirectFunctionTableManagedNativeAllocations_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o, TNode<HeapObject> p_v);
TNode<FixedArray> LoadWasmIndirectFunctionTableRefs_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o);
void StoreWasmIndirectFunctionTableRefs_0(compiler::CodeAssemblerState* state_, TNode<WasmIndirectFunctionTable> p_o, TNode<FixedArray> p_v);
TNode<WasmInstanceObject> LoadWasmDebugInfoInstance_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoInstance_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<WasmInstanceObject> p_v);
TNode<HeapObject> LoadWasmDebugInfoInterpreterHandle_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoInterpreterHandle_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<HeapObject> p_v);
TNode<Cell> LoadWasmDebugInfoInterpreterReferenceStack_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoInterpreterReferenceStack_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<Cell> p_v);
TNode<HeapObject> LoadWasmDebugInfoLocalsNames_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoLocalsNames_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWasmDebugInfoCWasmEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoCWasmEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWasmDebugInfoCWasmEntryMap_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o);
void StoreWasmDebugInfoCWasmEntryMap_0(compiler::CodeAssemblerState* state_, TNode<WasmDebugInfo> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o);
void StoreWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadWasmModuleObjectNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);
void StoreWasmModuleObjectNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Foreign> p_v);
TNode<FixedArray> LoadWasmModuleObjectExportWrappers_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);
void StoreWasmModuleObjectExportWrappers_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<FixedArray> p_v);
TNode<Script> LoadWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);
void StoreWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Script> p_v);
TNode<HeapObject> LoadWasmModuleObjectAsmJsOffsetTable_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);
void StoreWasmModuleObjectAsmJsOffsetTable_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<HeapObject> p_v);
TNode<FixedArray> LoadWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);
void StoreWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v);
TNode<Smi> LoadWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);
void StoreWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v);
TNode<Object> LoadWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);
void StoreWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Object> p_v);
TNode<FixedArray> LoadWasmTableObjectDispatchTables_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);
void StoreWasmTableObjectDispatchTables_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v);
TNode<Smi> LoadWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);
void StoreWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v);
TNode<JSArrayBuffer> LoadWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);
void StoreWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<JSArrayBuffer> p_v);
TNode<Smi> LoadWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);
void StoreWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);
void StoreWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);
void StoreWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);
void StoreWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);
void StoreWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v);
TNode<Smi> LoadWasmGlobalObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);
void StoreWasmGlobalObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v);
TNode<ByteArray> LoadWasmExceptionObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionObject> p_o);
void StoreWasmExceptionObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionObject> p_o, TNode<ByteArray> p_v);
TNode<HeapObject> LoadWasmExceptionObjectExceptionTag_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionObject> p_o);
void StoreWasmExceptionObjectExceptionTag_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionObject> p_o, TNode<HeapObject> p_v);
TNode<Foreign> LoadAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);
void StoreAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<Foreign> p_v);
TNode<FixedArray> LoadAsmWasmDataExportWrappers_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);
void StoreAsmWasmDataExportWrappers_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<FixedArray> p_v);
TNode<ByteArray> LoadAsmWasmDataAsmJsOffsetTable_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);
void StoreAsmWasmDataAsmJsOffsetTable_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<ByteArray> p_v);
TNode<HeapNumber> LoadAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);
void StoreAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<HeapNumber> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_H_
