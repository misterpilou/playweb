#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<HeapObject> LoadSourceTextModuleCode_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleCode_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);
TNode<FixedArray> LoadSourceTextModuleRegularExports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleRegularExports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);
TNode<FixedArray> LoadSourceTextModuleRegularImports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleRegularImports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);
TNode<FixedArray> LoadSourceTextModuleRequestedModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleRequestedModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);
TNode<Script> LoadSourceTextModuleScript_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleScript_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Script> p_v);
TNode<HeapObject> LoadSourceTextModuleImportMeta_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleImportMeta_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);
TNode<ArrayList> LoadSourceTextModuleAsyncParentModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleAsyncParentModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<ArrayList> p_v);
TNode<HeapObject> LoadSourceTextModuleTopLevelCapability_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleTopLevelCapability_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadSourceTextModuleDfsIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleDfsIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModuleDfsAncestorIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleDfsAncestorIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModulePendingAsyncDependencies_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModulePendingAsyncDependencies_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModuleFlags_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);
void StoreSourceTextModuleFlags_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryExportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryExportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryLocalName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryLocalName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryImportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryImportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);
TNode<Smi> LoadSourceTextModuleInfoEntryModuleRequest_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryModuleRequest_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModuleInfoEntryCellIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryCellIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModuleInfoEntryBegPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryBegPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSourceTextModuleInfoEntryEndPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);
void StoreSourceTextModuleInfoEntryEndPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_H_
