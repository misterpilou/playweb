#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_WEAK_REFS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_WEAK_REFS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<NativeContext> LoadJSFinalizationGroupNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<NativeContext> p_v);
TNode<Object> LoadJSFinalizationGroupCleanup_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupCleanup_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadJSFinalizationGroupActiveCells_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupActiveCells_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSFinalizationGroupClearedCells_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupClearedCells_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadJSFinalizationGroupKeyMap_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupKeyMap_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadJSFinalizationGroupNext_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupNext_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSFinalizationGroupFlags_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o);
void StoreJSFinalizationGroupFlags_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroup> p_o, TNode<Smi> p_v);
TNode<JSFinalizationGroup> LoadJSFinalizationGroupCleanupIteratorFinalizationGroup_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroupCleanupIterator> p_o);
void StoreJSFinalizationGroupCleanupIteratorFinalizationGroup_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationGroupCleanupIterator> p_o, TNode<JSFinalizationGroup> p_v);
TNode<HeapObject> LoadWeakCellFinalizationGroup_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellFinalizationGroup_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWeakCellTarget_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellTarget_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadWeakCellHoldings_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellHoldings_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadWeakCellPrev_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellPrev_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWeakCellNext_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellNext_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadWeakCellKey_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellKey_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadWeakCellKeyListPrev_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellKeyListPrev_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadWeakCellKeyListNext_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o);
void StoreWeakCellKeyListNext_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSWeakRefTarget_0(compiler::CodeAssemblerState* state_, TNode<JSWeakRef> p_o);
void StoreJSWeakRefTarget_0(compiler::CodeAssemblerState* state_, TNode<JSWeakRef> p_o, TNode<HeapObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_WEAK_REFS_TQ_H_
