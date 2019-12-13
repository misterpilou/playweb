#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<JSArrayBuffer> LoadJSArrayBufferViewBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);
void StoreJSArrayBufferViewBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<JSArrayBuffer> p_v);
TNode<UintPtrT> LoadJSArrayBufferViewByteOffset_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);
void StoreJSArrayBufferViewByteOffset_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<UintPtrT> p_v);
TNode<UintPtrT> LoadJSArrayBufferViewByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);
void StoreJSArrayBufferViewByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<UintPtrT> p_v);
TNode<UintPtrT> LoadJSTypedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);
void StoreJSTypedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<UintPtrT> p_v);
TNode<RawPtrT> LoadJSTypedArrayExternalPointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);
void StoreJSTypedArrayExternalPointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<RawPtrT> p_v);
TNode<Object> LoadJSTypedArrayBasePointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);
void StoreJSTypedArrayBasePointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<Object> p_v);
TNode<UintPtrT> LoadJSArrayBufferByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);
void StoreJSArrayBufferByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<UintPtrT> p_v);
TNode<RawPtrT> LoadJSArrayBufferBackingStore_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);
void StoreJSArrayBufferBackingStore_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<RawPtrT> p_v);
TNode<RawPtrT> LoadJSDataViewDataPointer_0(compiler::CodeAssemblerState* state_, TNode<JSDataView> p_o);
void StoreJSDataViewDataPointer_0(compiler::CodeAssemblerState* state_, TNode<JSDataView> p_o, TNode<RawPtrT> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_H_
